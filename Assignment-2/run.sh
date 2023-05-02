#! /bin/bash

clang++ -g -Wno-everything main.cpp && ./a.out

if [ -f ./a.out ]
then
  rm ./a.out
fi


