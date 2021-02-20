#!/usr/bin/sh
make -j 999 install
dir_path="$(pwd)/csv-parser/include/internal/"
cd /etc/ld.so.conf.d/ || exit
echo "$dir_path">readoekrout.conf
ldconfig
