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
