#! /bin/bash

pushd $(find $0 -printf "%h") > /dev/null

# Verify Header
head -n 3 ../*.cpp 

echo -e "\nREQUIRED FUNCTION NAMES:"
while IFS= read -r line; 
do
  grep -q "$line" ../*.cpp && echo -n "[OK] " || echo -n '[--] '
  echo $line
done < required-function-names.txt

echo -e "\nREQUIRED FUNCTION PROTOTYPES:"

while IFS= read -r line; 
do
  if grep -q "$line" ../*.cpp
  then
    echo -n "[OK] "
    grep "$line" ../*.cpp
  else
    echo "[--] " $(grep "$line" required-function-prototypes.txt)
  fi
done < required-function-prototypes-regex.txt

if [ -f ../main ]
then
  rm ../main
fi

g++ -o ../main ../*.cpp

if [ -f ../main ]
then
  for t in test*txt
  do
    echo -e "\n\n~~~~~$t~~~~~"
    ../main < $t
  done
  rm ../main
fi

echo

popd > /dev/null


