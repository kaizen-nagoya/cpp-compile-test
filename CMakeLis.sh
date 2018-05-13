#!/bin/bash
cp $1/CMakeLists.txt .
mv ./deduce/initlist.cpp ./deduce/initlist2.cpp
while read line
do
cp $1/CMakeLists.txt.$line ./$line/CMakeLists.txt
done < $2
