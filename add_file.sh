#!/bin/bash
# WARNING: $1 must not end with symbol \, it should be like this, E:\code\linux
# WARNING: the path should be in ""
#change linux file path to windows form for using with source insight
# SI can using the filelist to add files, no need to add files by cliking the mouse
# $1 is window dir ie. E:\code\linux it can not   end with symbol \
PWD=$(pwd)
FILE=SI.txt
echo ${FILE}

PREFIX=$(echo "$1")

echo $PREFIX
PRE=$(echo ${PREFIX}|sed 's/\\/\\\\/g')
echo ${PRE}


find src -name "*.c" > FILE

sed "s/^/$PRE\\\/g" FILE |sed  's/\//\\/g' > tmp.txt 

