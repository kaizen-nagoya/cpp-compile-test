#!/bin/bash
./s.sh > pwd.txt
cdir=`cat pwd.txt`
echo ${cdir}
cp CMakeLis.sh $1
cp dir $1
pwd
cd $1
pwd
./CMakeLis.sh ${cdir} dir
cmake CMakeLists.txt
make
