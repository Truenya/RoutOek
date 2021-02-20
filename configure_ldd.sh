#!/usr/bin/sh
#sudo echo $pwd >> /etc/ld.so.conf/readoekrout.conf
dir_path="$(pwd)/csv-parser/include/internal/"
cd /etc/ld.so.conf.d/ || exit
echo "$dir_path">readoekrout.conf
ldconfig
