#! /bin/bash

g++ main.cpp && ./a.out

if [ -f ./a.out ]
then
  rm ./a.out
fi


