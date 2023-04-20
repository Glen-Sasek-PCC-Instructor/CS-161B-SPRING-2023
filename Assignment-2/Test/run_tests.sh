#! /bin/bash

P=${1:-'../*.cpp '}

pushd $(find $0 -printf "%h") > /dev/null

# Verify Header
head -n 3 "$P"

echo -e "\nREQUIRED FUNCTION NAMES:"
while IFS= read -r line; 
do
  if grep -q "$line" "$P" 
  then
    true # Do nothing, successfully!
  else
    echo '[--] '$line
  fi
done < required-function-names.txt

echo -e "\nREQUIRED FUNCTION PROTOTYPES:"

while IFS= read -r line; 
do
  if grep -q "$line" "$P"
  then
    # echo -n "[OK] "
    # grep "$line" "$P"
    true
  else
    echo "[--] "$(grep "$line" required-function-prototypes.txt)
  fi
done < required-function-prototypes-regex.txt

if [ -f main ]
then
  rm main
fi

g++ -o main "$P"

if [ -f main ]
then
  TMP=$(mktemp)
  trap 'rm -f $TMP' EXIT
  for t in test*txt
  do
    echo -e "\n\n~~~~~$t~~~~~"
    ./main < $t > $TMP
    if [ -f "Expected/$t" ]
    then
      diff -w <(grep -i -a encoded "Expected/$t") <(grep -i -a encoded  "$TMP")
    else 
      cat "$TMP"
    fi
  done
  rm $TMP
  rm main
fi

echo

popd > /dev/null


