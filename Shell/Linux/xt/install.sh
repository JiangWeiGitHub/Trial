#!/usr/bin/env bash

set -eu

DASH="------------------------------------------------------------"

banner_front()
{
  sleep 1s
  echo ""
  echo $DASH
  echo "$1"
  echo ""
}

banner_end()
{
  echo ""
  echo "$1"
  echo $DASH
  echo ""
  sleep 1s
}

# File Name: list.csv
# CSV format
# Machine Type, Machine IP, Machine Port, Is Local Machine
#
# Machine Type: 1 (Front End) 2 (Back End Without Database) 3 (Back End With Database) 4 (All In One)
# Is Local Machine: 1 (Yes) 0 (No)
#
fileName="list.csv"

banner_front "Check CSV File"
if [ ! -f "./${fileName}" ]; then
  echo "Error: ${fileName} Not Found!"
  exit 100
fi
banner_end "Done"

banner_front "Reading CSV File"
machineNumber=`cat ${fileName} | wc -l`
for((i=1,j=1;i<=`expr ${machineNumber}`;i++));
do
  machineType[i]=`cat ${fileName} | head -n ${i} | tail -n +${i} | awk -F, '{ print $1; }'`
  machineIP[i]=`cat ${fileName} | head -n ${i} | tail -n +${i} | awk -F, '{ print $2; }'`
  machinePort[i]=`cat ${fileName} | head -n ${i} | tail -n +${i} | awk -F, '{ print $3; }'`
  machineLocal[i]=`cat ${fileName} | head -n ${i} | tail -n +${i} | awk -F, '{ print $4; }'`
  
  echo "machineType[i]: ${machineType[i]}"
  echo "machineIP[i]: ${machineIP[i]}"
  echo "machinePort[i]: ${machinePort[i]}"
  echo "machineLocal[i]: ${machineLocal[i]}"
  echo "================================="

  if [[ ${machineType[i]} == "1" ]]
  then
    singleType=0
  elif [[ ${machineType[i]} == "2" ]]
  then
    singleType=0
  elif [[ ${machineType[i]} == "3" ]]
  then
    singleType=0
    databaseMachine=${machineIP[i]}
  else
    singleType=1
    databaseMachine=${machineIP[i]}
  fi
	
  if [[ ${machineLocal[i]} == "1" ]]
  then
    localhostIP=${machineIP[i]}
  else
    remoteMachine[j]=${machineIP[i]}
    remoteMachinePort[j]=${machinePort[i]}
    j=$((${j}+1))
  fi

done
banner_end "Done"

banner_front "Check Version"
strRelease=`cat /etc/redhat-release`
strGoal="CentOS release 6.9 (Final)"
if [[ $strRelease != *$strGoal* ]]
then
  echo "Error: Wrong Release Version!"
  exit 101
fi
banner_end "Done"

banner_front "Stop & Disable Postfix"
service postfix stop && chkconfig postfix off
if [[ $? -ne 0 ]]
then
  echo "Error: Stop & Disable Postfix Failed!"
  exit 102
fi
banner_end "Done"

banner_front "Stop & Disable seLinux"
setenforce 0 && sed -i 's/SELINUX=enforcing/SELINUX=disabled/' /etc/selinux/config
if [[ $? -ne 0 ]]
then
  echo "Error: Stop & Disable seLinux Failed!"
  exit 103
fi
banner_end "Done"

banner_front "Stop & Disable iptables"
service iptables stop && chkconfig iptables off
if [[ $? -ne 0 ]]
then
  echo "Error: Stop iptables Failed!"
  exit 104
fi
banner_end "Done"

banner_front "Chmod XT Files"
xtMainFile="cmXT5.0.7-1_ENT_main_RHEL6_x86_64.install.sh"
if [ ! -f "./${xtMainFile}" ]; then
  echo "Error: XT Main File Not Found!"
  exit 105
fi

xtClamavFile="cmXT5.0.7-1_clamav_RHEL6_x86_64.tar.gz"
if [ ! -f "./$xtClamavFile" ]; then
  echo "Error: XT Clamav File Not Found!"
  exit 106
fi

chmod 755 ./cmXT5.0.7-1_*
if [[ $? -ne 0 ]]
then
  echo "Error: Chmod Failed!"
  exit 107
fi
banner_end "Done"

banner_front "Installation XT"
echo 'Installing XT...'
./${xtMainFile} -f
if [[ $? -ne 0 ]]
then
  echo "Error: Installation Failed!"
  exit 108
fi
banner_end "Done"

banner_front "Configure Webinst"
webInit=1
while [[ ${webInit} != "Yes" ]]
do
  read -p "Have you done it? ( Yes ) : " webInit
done
banner_end "Done"

banner_front "Install clamav"
yum install -y libtool-ltdl-2.2.6-15.5.el6.x86_64
cp cmXT5.0.7-1_clamav_RHEL6_x86_64.tar.gz /home/coremail/
cd /home/coremail/
tar zxvf ./cmXT5.0.7-1_clamav_RHEL6_x86_64.tar.gz
cd /home/coremail/install/options/clamav/

./install.sh
if [[ $? -ne 0 ]]
then
  echo "Error: Installation Failed!"
  exit 109
fi
banner_end "Done"

banner_front "Modify MySQL"
passWord=`awk 'NR==2 {print $3}' /home/coremail/bin/mysql_cm | awk '{print substr($0,3)}'`

for((i=1;i<=`expr ${machineNumber}`;i++));
do
  /home/coremail/mysql/bin/mysql -uroot -p${passWord} -h127.0.0.1 -P3308 <<EOF
    use cmxt;
    GRANT ALL PRIVILEGES ON *.* TO 'coremail'@'${machineIP[i]}' IDENTIFIED BY '${passWord}';
EOF
done
banner_end "Done"

banner_front "Stop All Programs"
/home/coremail/sbin/cmctrl.sh stop
if [[ $? -ne 0 ]]
then
  echo "Error: Stop All Failed!"
  exit 110
fi
banner_end "Done"

banner_front "Edit programs.cf"
for((i=1;i<=`expr ${machineNumber}`;i++));
do
  sed -i "/FreeIPList/{s/\"/,${machineIP[i]}\"/2}" /home/coremail/conf/programs.cf
  if [[ $? -ne 0 ]]
  then
    echo "Error: Modify programs.cf Failed!"
    exit 111
  fi
done

cp /home/coremail/conf/programs.cf /home/coremail/var/mainconfig/programs.cf
banner_end "Done"

banner_front "Edit datasources.cf"
for((i=1;i<=`expr ${machineNumber}`;i++));
do
  sed -i "s/Server=\"127.0.0.1\"/Server=\"${databaseMachine}\"/" /home/coremail/conf/datasources.cf
  if [[ $? -ne 0 ]]
  then
    echo "Error: Modify datasources.cf Failed!"
    exit 112
  fi
done

cp /home/coremail/conf/datasources.cf /home/coremail/var/mainconfig/datasources.cf
banner_end "Done"

banner_front "Edit iplimit.cf"
sed -i '/^$/d' /home/coremail/conf/iplimit.cf
if [[ ${singleType} -eq 0 ]]
then
for((i=1;i<=`expr ${machineNumber}`;i++));
do
  sed -i "s/iprangecount=\"$(($i+2))\"/iprangecount=\"$(($i+3))\"/" /home/coremail/conf/iplimit.cf
  sed -i "/command setting/i\iprange$(($i+3))=\"${machineIP[i]}:a:0:10000\"" /home/coremail/conf/iplimit.cf
  if [[ $? -ne 0 ]]
  then
    echo "Error: Modify iplimit.cf Failed!"
    exit 113
  fi

  sed -i "/nolimit/i\iprange$(($i+3))=\"${machineIP[i]}:a:0:10000\"" /home/coremail/conf/iplimit.cf
  if [[ $? -ne 0 ]]
  then
    echo "Error: Modify iplimit.cf Failed!"
    exit 114
  fi
done
sed -i "/command setting/i\ " /home/coremail/conf/iplimit.cf
sed -i "/nolimit/i\ " /home/coremail/conf/iplimit.cf
fi

cp /home/coremail/conf/iplimit.cf /home/coremail/var/mainconfig/iplimit.cf
banner_end "Done"

banner_front "Edit hosts.cf"
if [[ ${machineNumber} -eq 1 ]]
then
  echo "111111"
elif [[ ${machineNumber} -eq 2 ]]
then
  echo "222222"      
elif [[ ${machineNumber} -eq 3 ]]
then
  echo "#! Encoding UTF-8" > /home/coremail/conf/hosts.cf
  echo "" >> /home/coremail/conf/hosts.cf
  echo "[${machineIP[1]}]" >> /home/coremail/conf/hosts.cf
  echo "IP=\"${machineIP[1]}\"" >> /home/coremail/conf/hosts.cf
  echo "ProgramsList=\"adminsvr,wmsvr,session,pop3svr,scequerysvr,mtasvr,deliveragent,imapsvr,timedsend,convertlog,liveupdate,sysmonitor,mailsms,nginx,mlstsvr,siosvr,LicenseExpiredRemind,mscache,NginxLogRotate,antivirus\"" >> /home/coremail/conf/hosts.cf
  echo "WebServerID=\"1\"" >> /home/coremail/conf/hosts.cf
  echo "WebLoginParameters=\"webprefix=@login\"" >> /home/coremail/conf/hosts.cf
  echo "WMWeight=\"10\"" >> /home/coremail/conf/hosts.cf
  echo "ASQID=\"1\"" >> /home/coremail/conf/hosts.cf
  echo "SESID=\"1\"" >> /home/coremail/conf/hosts.cf
  echo "SESWeight=\"10\"" >> /home/coremail/conf/hosts.cf
  echo "SMTPServerType=\"smtp,mx\"" >> /home/coremail/conf/hosts.cf
  echo "Pop3CheckResource=\"0\"" >> /home/coremail/conf/hosts.cf
  echo "SmtpCheckResource=\"0\"" >> /home/coremail/conf/hosts.cf
  echo "SIOStatNotify=\"1\"" >> /home/coremail/conf/hosts.cf
  echo "SIOID=\"1\"" >> /home/coremail/conf/hosts.cf
  echo "MLSTID=\"1\"" >> /home/coremail/conf/hosts.cf
  echo "MSCacheID=\"1\"" >> /home/coremail/conf/hosts.cf
  echo "AVID=\"1\"" >> /home/coremail/conf/hosts.cf
  echo "" >> /home/coremail/conf/hosts.cf
  echo "[${machineIP[2]}]" >> /home/coremail/conf/hosts.cf
  echo "IP=\"${machineIP[2]}\"" >> /home/coremail/conf/hosts.cf
  echo "ProgramsList=\"adminsvr,wmsvr,session,pop3svr,scequerysvr,mtasvr,deliveragent,imapsvr,convertlog,liveupdate,sysmonitor,mailsms,nginx,mlstsvr,siosvr,LicenseExpiredRemind,mscache,NginxLogRotate,antivirus\"" >> /home/coremail/conf/hosts.cf
  echo "WebServerID=\"2\"" >> /home/coremail/conf/hosts.cf
  echo "WebLoginParameters=\"webprefix=@login\"" >> /home/coremail/conf/hosts.cf
  echo "WMWeight=\"10\"" >> /home/coremail/conf/hosts.cf
  echo "ASQID=\"2\"" >> /home/coremail/conf/hosts.cf
  echo "SESID=\"2\"" >> /home/coremail/conf/hosts.cf
  echo "SESWeight=\"10\"" >> /home/coremail/conf/hosts.cf
  echo "SMTPServerType=\"smtp,mx\"" >> /home/coremail/conf/hosts.cf
  echo "Pop3CheckResource=\"0\"" >> /home/coremail/conf/hosts.cf
  echo "SmtpCheckResource=\"0\"" >> /home/coremail/conf/hosts.cf
  echo "SIOStatNotify=\"1\"" >> /home/coremail/conf/hosts.cf
  echo "SIOID=\"2\"" >> /home/coremail/conf/hosts.cf
  echo "MLSTID=\"2\"" >> /home/coremail/conf/hosts.cf
  echo "MSCacheID=\"2\"" >> /home/coremail/conf/hosts.cf
  echo "AVID=\"2\"" >> /home/coremail/conf/hosts.cf
  echo "" >> /home/coremail/conf/hosts.cf
  echo "[${machineIP[3]}]" >> /home/coremail/conf/hosts.cf
  echo "IP=\"${machineIP[3]}\"" >> /home/coremail/conf/hosts.cf
  echo "ProgramsList=\"RmiServer,mssvr,udsvr,mdsvr,adminsvr,convertlog,udext,sysmonitor,searchsvr,SysScanPeriod\"" >> /home/coremail/conf/hosts.cf
  echo "MDID=\"1\"" >> /home/coremail/conf/hosts.cf
  echo "JAPIID=\"1\"" >> /home/coremail/conf/hosts.cf
  echo "MDWeight=\"10\"" >> /home/coremail/conf/hosts.cf
  echo "UDID=\"1\"" >> /home/coremail/conf/hosts.cf
  echo "UDWeight=\"10\"" >> /home/coremail/conf/hosts.cf
  echo "UDDataDir=\"/home/coremail/var/ud\"" >> /home/coremail/conf/hosts.cf
  echo "UDDiskRate=\"10\"" >> /home/coremail/conf/hosts.cf
  echo "MSID=\"1\"" >> /home/coremail/conf/hosts.cf
  echo "MSWeight=\"10\"" >> /home/coremail/conf/hosts.cf
  echo "MSDataDir=\"/home/coremail/var/ms\"" >> /home/coremail/conf/hosts.cf
  echo "MSDiskRate=\"10\"" >> /home/coremail/conf/hosts.cf
  echo "MSTimeHashDirCount=\"20\"" >> /home/coremail/conf/hosts.cf
  echo "MSUserHashDirCount=\"20\"" >> /home/coremail/conf/hosts.cf
  echo "SearchID=\"1\"" >> /home/coremail/conf/hosts.cf
  echo "SearchDataDir=\"/home/coremail/var/search/data\"" >> /home/coremail/conf/hosts.cf
  echo "SearchDiskRate=\"10\"" >> /home/coremail/conf/hosts.cf
  echo "TrsMSWeight=\"10\"" >> /home/coremail/conf/hosts.cf
  echo "BackupDir=\"/home/coremail/var/backup\"" >> /home/coremail/conf/hosts.cf
  echo "" >> /home/coremail/conf/hosts.cf
elif [[ ${machineNumber} -eq 4 ]]
then
  echo "444444"
fi

cp /home/coremail/conf/hosts.cf /home/coremail/var/mainconfig/hosts.cf
banner_end "Done"

banner_front "Edit coremail.cf"
tmp=`/sbin/ifconfig | sed -n '/inet addr/s/^[^:]*:\([0-9.]\{7,15\}\) .*/\1/p' | sed -n "/${localhostIP}/p"`
if [[ ${tmp} == ${localhostIP} ]]
then
  num=${#machineIP[@]}
  for((i=1;i<num;i++));
  do
    if [[ ${machineIP[i]} == ${localhostIP} ]]
    then
      if [[ ${machineType[i]} -eq 1 ]]
      then
        echo "#! Encoding UTF-8" > /home/coremail/conf/coremail.cf
        echo "" >> /home/coremail/conf/coremail.cf
        echo "[Default]" >> /home/coremail/conf/coremail.cf
        echo "Hostid=\"${localhostIP}\"" >> /home/coremail/conf/coremail.cf
        echo "MainAdminSvrHost=\"${machineIP[3]}\"" >> /home/coremail/conf/coremail.cf
        echo "MainAdminSvrPort=\"6130\"" >> /home/coremail/conf/coremail.cf
        echo "IamMainAdminSvr=\"0\"" >> /home/coremail/conf/coremail.cf
        echo "" >> /home/coremail/conf/coremail.cf
        echo "[Environment]" >> /home/coremail/conf/coremail.cf
        echo "ORACLE_HOME=\"\"" >> /home/coremail/conf/coremail.cf
        echo "ORACLE_BASE=\"\"" >> /home/coremail/conf/coremail.cf
        echo "NLS_LANG=\"\"" >> /home/coremail/conf/coremail.cf
        echo "ORA_NLS33=\"\"" >> /home/coremail/conf/coremail.cf
        echo "" >> /home/coremail/conf/coremail.cf
        echo "[ReloadEnvironment]" >> /home/coremail/conf/coremail.cf
        echo "LD_PRELOAD=\"\$(COREMAIL_HOME)/lib64/libtcmalloc.so.4\"" >> /home/coremail/conf/coremail.cf
        echo "" >> /home/coremail/conf/coremail.cf
      elif [[ ${machineType[i]} -eq 2 ]]
      then
        echo "222222"      
      elif [[ ${machineType[i]} -eq 3 ]]
      then
        echo "#! Encoding UTF-8" > /home/coremail/conf/coremail.cf
        echo "" >> /home/coremail/conf/coremail.cf
        echo "[Default]" >> /home/coremail/conf/coremail.cf
        echo "Hostid=\"${localhostIP}\"" >> /home/coremail/conf/coremail.cf
        echo "MainAdminSvrHost=\"${localhostIP}\"" >> /home/coremail/conf/coremail.cf
        echo "MainAdminSvrPort=\"6130\"" >> /home/coremail/conf/coremail.cf
        echo "IamMainAdminSvr=\"1\"" >> /home/coremail/conf/coremail.cf
        echo "" >> /home/coremail/conf/coremail.cf
        echo "[Environment]" >> /home/coremail/conf/coremail.cf
        echo "ORACLE_HOME=\"\"" >> /home/coremail/conf/coremail.cf
        echo "ORACLE_BASE=\"\"" >> /home/coremail/conf/coremail.cf
        echo "NLS_LANG=\"\"" >> /home/coremail/conf/coremail.cf
        echo "ORA_NLS33=\"\"" >> /home/coremail/conf/coremail.cf
        echo "" >> /home/coremail/conf/coremail.cf
        echo "[ReloadEnvironment]" >> /home/coremail/conf/coremail.cf
        echo "LD_PRELOAD=\"\$(COREMAIL_HOME)/lib64/libtcmalloc.so.4\"" >> /home/coremail/conf/coremail.cf
        echo "" >> /home/coremail/conf/coremail.cf
      elif [[ ${machineType[i]} -eq 4 ]]
      then
        echo "444444"
      fi
    fi
  done
fi
banner_end "Done"

banner_front "Edit cmctrl.sh"
tmp=`/sbin/ifconfig | sed -n '/inet addr/s/^[^:]*:\([0-9.]\{7,15\}\) .*/\1/p' | sed -n "/${localhostIP}/p"`
if [[ ${tmp} == ${localhostIP} ]]
then
  num=${#machineIP[@]}
  for((i=1;i<num;i++));
  do
    if [[ ${machineIP[i]} == ${localhostIP} ]]
    then
      if [[ ${machineType[i]} -eq 1 ]]
      then
        `sed -i 's/CONTROL_MYSQL=\"1\"/CONTROL_MYSQL=\"0\"/' /home/coremail/sbin/cmctrl.sh`
      elif [[ ${machineType[i]} -eq 2 ]]
      then
        echo "222222"      
      elif [[ ${machineType[i]} -eq 3 ]]
      then
        echo "No change"
      elif [[ ${machineType[i]} -eq 4 ]]
      then
        echo "444444"
      fi
    fi
  done
fi
banner_end "Done"

banner_front "Set Startup"
\cp /home/coremail/sbin/cmctrl.sh /etc/init.d/coremail
chkconfig --add coremail
chkconfig coremail on
banner_end "Done"

banner_front "Copy 'coremail' Folder To Other Machine"
yum install -y rsync-3.0.6-12.el6.x86_64
for((j=1;j<`expr ${machineNumber}`;j++));
do
  ssh -p ${remoteMachinePort[j]} root@${remoteMachine[j]} "yum install -y rsync-3.0.6-12.el6.x86_64"
  rsync -aSvH -e "ssh -p ${remoteMachinePort[j]}" /home/coremail root@${remoteMachine[j]}:/home
  
  for((i=1;i<=`expr ${machineNumber}`;i++));
  do

    if [[ ${machineIP[i]} == ${remoteMachine[j]} ]]
    then
      if [[ ${machineType[i]} -eq 1 ]]
      then
        ssh -p ${remoteMachinePort[j]} root@${remoteMachine[j]} "sed -i 's/.*CONTROL_MYSQL=\"\([0-9]*\)\".*/CONTROL_MYSQL=\"0\"/' /home/coremail/sbin/cmctrl.sh && \
        sed -i 's/\(Hostid=\).*/Hostid=\"${remoteMachine[j]}\"/' /home/coremail/conf/coremail.cf && \
        sed -i 's/\(IamMainAdminSvr=\).*/IamMainAdminSvr=\"0\"/' /home/coremail/conf/coremail.cf && \
	yum install -y libtool-ltdl-2.2.6-15.5.el6.x86_64 && \ 
	cd /home/coremail/install/options/clamav/ && \ 
	./install.sh && \ 	
        \\cp /home/coremail/sbin/cmctrl.sh /etc/init.d/coremail && \
        chkconfig --add coremail && \
        chkconfig coremail on && \
        useradd coremail && \
        chown coremail:coremail /home/coremail -R && \
        service postfix stop && \
        chkconfig postfix off && \
        setenforce 0 && \
        sed -i 's/SELINUX=enforcing/SELINUX=disabled/' /etc/selinux/config && \
        service iptables stop && \
        chkconfig iptables off"
      elif [[ ${machineType[i]} -eq 2 ]]
      then
        ssh -p ${remoteMachinePort[j]} root@${remoteMachine[j]} "sed -i 's/.*CONTROL_MYSQL=\"\([0-9]*\)\".*/CONTROL_MYSQL=\"0\"/' /home/coremail/sbin/cmctrl.sh"
        ssh -p ${remoteMachinePort[j]} root@${remoteMachine[j]} "sed -i 's/\(Hostid=\).*/Hostid=\"${remoteMachine[j]}\"/' /home/coremail/conf/coremail.cf"
        ssh -p ${remoteMachinePort[j]} root@${remoteMachine[j]} "sed -i 's/\(IamMainAdminSvr=\).*/IamMainAdminSvr=\"0\"/' /home/coremail/conf/coremail.cf"
      elif [[ ${machineType[i]} -eq 3 ]]
      then
        ssh -p ${remoteMachinePort[j]} root@${remoteMachine[j]} "sed -i 's/.*CONTROL_MYSQL=\"\([0-9]*\)\".*/CONTROL_MYSQL=\"1\"/' /home/coremail/sbin/cmctrl.sh && \
        sed -i 's/\(Hostid=\).*/Hostid=\"${remoteMachine[j]}\"/' /home/coremail/conf/coremail.cf && \
        sed -i 's/\(IamMainAdminSvr=\).*/IamMainAdminSvr=\"1\"/' /home/coremail/conf/coremail.cf && \
        \\cp /home/coremail/sbin/cmctrl.sh /etc/init.d/coremail && \
        chkconfig --add coremail && \
        chkconfig coremail on && \
        useradd coremail && \
        chown coremail:coremail /home/coremail -R && \
        service postfix stop && \
        chkconfig postfix off && \
        setenforce 0 && \
        sed -i 's/SELINUX=enforcing/SELINUX=disabled/' /etc/selinux/config && \
        service iptables stop && \
        chkconfig iptables off"
      elif [[ ${machineType[i]} -eq 4 ]]
      then
        echo "444444"
      fi
    elif [[ ${machineType[i]} -eq 2 ]]
    then
      echo "222222"      
    elif [[ ${machineType[i]} -eq 3 ]]
    then
      echo "No change"
    elif [[ ${machineType[i]} -eq 4 ]]
    then
      echo "444444"
    fi
  
  done
done
banner_end "Done"

banner_front "Congratulations!"
banner_end "Everything Is Done!"
