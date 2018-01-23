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

echo "Install clamav..."
yum install libtool-ltdl-2.2.6-15.5.el6.x86_64
cp cmXT5.0.7-1_clamav_RHEL6_x86_64.tar.gz /home/coremail/
cd /home/coremail/
tar zxvf ./cmXT5.0.7-1_clamav_RHEL6_x86_64.tar.gz
cd /home/coremail/install/options/clamav/
./install.sh

echo "Get Machine Infor..."
read -p "Input Machine Number:" machineNumber
echo "Machine Number is: $machineNumber"

databaseMachine=0
singleType=0
singleIP=0

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
  sed -i '/FreeIPList/{s/"/,${machineIP[i]}"/2}' /home/coremail/conf/programs.cf
  if [[ $? -ne 0 ]]
  then
    echo "Error: Modify programs.cf Failed!"
    exit 1009
  fi
EOF
done

cp /home/coremail/conf/programs.cf /home/coremail/var/mainconfig/programs.cf

echo "Edit datasources.cf..."
for((i=1;i<=`expr ${machineNumber}`;i++));
do
  sed -i 's/Server="127.0.0.1"/Server="${databaseMachine}"/' /home/coremail/conf/datasources.cf
  if [[ $? -ne 0 ]]
  then
    echo "Error: Modify datasources.cf Failed!"
    exit 1009
  fi
EOF
done

cp /home/coremail/conf/datasources.cf /home/coremail/var/mainconfig/datasources.cf

echo "Edit iplimit.cf..."
arriprange=("iprange4" "iprange5" "iprange6" "iprange7" "iprange8" "iprange9" "iprange10" "iprange11" "iprange12")
if [[ ${singleType} -eq 0 ]]
then
for((i=1;i<=`expr ${machineNumber}`;i++));
do
  sed -i '/\command setting/i\${arriprange[i]}="${machineIP[i]}:a:0:10000"' /home/coremail/conf/iplimit.cf
  if [[ $? -ne 0 ]]
  then
    echo "Error: Modify iplimit.cf Failed!"
    exit 1009
  fi
  sed -i '/\nolimit/i\${arriprange[i]}="${machineIP[i]}:a:0:10000"' /home/coremail/conf/iplimit.cf
  if [[ $? -ne 0 ]]
  then
    echo "Error: Modify iplimit.cf Failed!"
    exit 1010
  fi
EOF
done
fi

cp /home/coremail/conf/iplimit.cf /home/coremail/var/mainconfig/iplimits.cf




