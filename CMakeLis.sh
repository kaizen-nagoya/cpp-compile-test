#!/bin/bash
cp $1/CMakeLists.txt .
cd basics
cat myfirstmain.cpp | sed s/myfirst/myfirst2/ > m.cpp
mv m.cpp myfirstmain.cpp
cd ..
mv ./deduce/initlist.cpp ./deduce/initlist2.cpp
while read line
do
  cp $1/CMakeLists.txt.$line ./$line/CMakeLists.txt
done < $2
