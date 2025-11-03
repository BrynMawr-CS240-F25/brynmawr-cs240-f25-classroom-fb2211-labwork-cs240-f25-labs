#! /usr/bin/bash

if [ "$#" -ne 1 ]; then
   echo "usage: $0 <basename>"
   exit 0
fi

sed 's/\/\/.*//' asm/$1.hack > .tmp1.txt
sed 's/\/\/.*//' hack/$1.hack > .tmp2.txt
diff --ignore-all-space .tmp1.txt .tmp2.txt 
if [ "$?" -eq 0 ]; then
  echo "asm/$1.hack and hack/$1.hack are identical"
fi
