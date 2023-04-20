#! /bin/bash

f=$(mktemp)

g++ main.cpp && ./a.out < test.txt > $f

diff test-out.txt $f

rm $f


if [ -f ./a.out ]
then
  rm ./a.out
fi


