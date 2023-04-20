#! /bin/bash

g++ -g *.cpp  *.h && ./a.out

if [ -f ./a.out ]
then
  rm ./a.out
fi


