#!/usr/bin/env bash

set -eu

echo 'Check Version...'
strRelease=`cat /etc/redhat-release`
strGoal="CentOS release 6.9 (Final)"

if [[ $strRelease != *$strGoal* ]]
then
  echo "Error: Wrong Release Version!"
  exit 1000
fi

echo 'Stop & Disable Postfix...'
postExist=`service postfix stop`
if [[ $? -ne 0 ]]
then
  echo "Error: Stop Postfix Failed!"
  exit 1001
fi

postControl=`chkconfig postfix off`
if [[ $? -ne 0 ]]
then
  echo "Error: Disable Postfix Failed!"
  exit 1002
fi

echo 'Disable seLinux...'
selinuxControl=`setenforce 0`
if [[ $? -ne 0 ]]
then
  echo "Error: Stop seLinux Failed!"
  exit 1003
fi

editselinux=`sed -i 's/SELINUX=enforcing/SELINUX=disabled/' /etc/selinux/config`
if [[ $? -ne 0 ]]
then
  echo "Error: Disable seLinux Failed!"
  exit 1004
fi

echo 'Stop & Disable iptables...'
iptablesControl=`service iptables stop && chkconfig iptables off`
if [[ $? -ne 0 ]]
then
  echo "Error: Stop iptables Failed!"
  exit 1005
fi

echo 'Chmod XT Files...'
xtMainFile="cmXT5.0.7-1_ENT_main_RHEL6_x86_64.install.sh"
if [ ! -f "./$xtMainFile" ]; then
  echo "Error: XT Main File Not Found!"
  exit 1006
fi

xtClamavFile="cmXT5.0.7-1_clamav_RHEL6_x86_64.tar.gz"
if [ ! -f "./$xtClamavFile" ]; then
  echo "Error: XT Clamav File Not Found!"
  exit 1007
fi

chmod 755 ./cmXT5.0.7-1_*
if [[ $? -ne 0 ]]
then
  echo "Error: Chmod Failed!"
  exit 1008
fi

./${xtMainFile} -f

echo "Configure Webadmin..."
read -p "Have you done it? ( Yes/No )" tmp

echo "Install clamav..."
yum install libtool-ltdl-2.2.6-15.5.el6.x86_64
cp cmXT5.0.7-1_clamav_RHEL6_x86_64.tar.gz /home/coremail/
cd /home/coremail/
tar zxvf ./cmXT5.0.7-1_clamav_RHEL6_x86_64.tar.gz
cd /home/coremail/install/options/clamav/
./install.sh

#############################################################################################
echo "##########################################"

machineNumber=0
machineType={0}
machineIP={"127.0.0.1"}

databaseMachine=0
singleType=0
singleIP="127.0.0.1"
localhostIP="127.0.0.1"
localhostID=0

echo "Get Machine Infor..."
read -p "Input Machine Number:" machineNumber
echo "Machine Number is: $machineNumber"

echo "Get Localhost Infor..."
read -p "Input Localhost IP:" localhostIP
echo "Localhost Machine is: $localhostIP"

for((i=1;i<=`expr ${machineNumber}`;i++));
do
  read -p "Input Machine Type ( 1 FrontEnd / 2 BackEnd NoDatabase / 3 BackEnd Database / 4 AllInOne ): " machineType[i]
  read -p "Input Machine IP: " machineIP[i]
  echo "Machine Infor is: ${machineType[i]} ${machineIP[i]}"
  if [[ ${machineType[i]} -eq 3 ]]
  then
    echo "Infor: Database Machine!"
    databaseMachine=${machineIP[i]}
  elif [[ ${machineType[i]} -eq 4 ]]
  then 
    echo "Infor: Single Machine!"
    singleType=1
    singleIP=${machineIP[i]}
  fi
done

echo "Modify MySQL..."
passWord=`awk 'NR==2 {print $3}' /home/coremail/bin/mysql_cm | awk '{print substr($0,3)}'`

for((i=1;i<=`expr ${machineNumber}`;i++));
do
  /home/coremail/mysql/bin/mysql -uroot -p${passWord} -h127.0.0.1 -P3308 <<EOF
    use cmxt;
    GRANT ALL PRIVILEGES ON *.* TO 'coremail'@'${machineIP[i]}' IDENTIFIED BY '${passWord}';
EOF
done

echo "Stop All Processes except MySQL..."
/home/coremail/bin/coremail stop all

echo "Edit programs.cf..."
for((i=1;i<=`expr ${machineNumber}`;i++));
do
  sed -i "/FreeIPList/{s/\"/,${machineIP[i]}\"/2}" /home/coremail/conf/programs.cf
  if [[ $? -ne 0 ]]
  then
    echo "Error: Modify programs.cf Failed!"
    exit 1009
  fi
done

cp /home/coremail/conf/programs.cf /home/coremail/var/mainconfig/programs.cf

echo "Edit datasources.cf..."
for((i=1;i<=`expr ${machineNumber}`;i++));
do
  sed -i "s/Server=\"127.0.0.1\"/Server=\"${databaseMachine}\"/" /home/coremail/conf/datasources.cf
  if [[ $? -ne 0 ]]
  then
    echo "Error: Modify datasources.cf Failed!"
    exit 1009
  fi
done

cp /home/coremail/conf/datasources.cf /home/coremail/var/mainconfig/datasources.cf

echo "Edit iplimit.cf..."
sed -i '/^$/d' /home/coremail/conf/iplimit.cf
#arriprange=("iprange4" "iprange5" "iprange6" "iprange7" "iprange8" "iprange9" "iprange10" "iprange11" "iprange12")
if [[ ${singleType} -eq 0 ]]
then
for((i=1;i<=`expr ${machineNumber}`;i++));
do
  sed -i "/\command setting/i\iprange${i+3}=\"${machineIP[i]}:a:0:10000\"\n" /home/coremail/conf/iplimit.cf
  if [[ $? -ne 0 ]]
  then
    echo "Error: Modify iplimit.cf Failed!"
    exit 1009
  fi

  sed -i "/\nolimit/i\iprange${i+3}=\"${machineIP[i]}:a:0:10000\"\n" /home/coremail/conf/iplimit.cf
  if [[ $? -ne 0 ]]
  then
    echo "Error: Modify iplimit.cf Failed!"
    exit 1010
  fi
done
fi

cp /home/coremail/conf/iplimit.cf /home/coremail/var/mainconfig/iplimits.cf

echo "Edit hosts.cf..."
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
  echo "[${machineIP[2]}]" > /home/coremail/conf/hosts.cf
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

echo "Edit coremail.cf..."
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

echo "Edit cmctrl.sh..."
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
        `sed -i 's/CONTROL_MYSQL=\"1\"/CONTROL_MYSQL=\"0\"/' /etc/selinux/config`
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

echo "Start All Processes except MySQL..."
/home/coremail/bin/coremail start all
