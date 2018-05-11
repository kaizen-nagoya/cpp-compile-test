#!/bin/bash
while read line
do
  echo "cp CMakeLists.txt ./$line/CMakeLists.txt"
done < ./$1
