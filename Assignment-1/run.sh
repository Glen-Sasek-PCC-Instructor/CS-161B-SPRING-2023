#! /bin/bash

clang++ -o main -g -Wno-everything main.cpp && ./main

if [ -f ./main ]
then
  rm ./main
fi


