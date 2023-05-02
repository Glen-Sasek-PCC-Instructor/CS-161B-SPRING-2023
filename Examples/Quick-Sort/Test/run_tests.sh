#! /bin/bash

P=${1:-../*.cpp }

pushd $(find $0 -printf "%h") > /dev/null

if [ -f main ]
then
  rm main
fi

clang++ -o main -g -Wno-everything $P

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
      diff -w -i -B "Expected/$t" "$TMP" && echo "[OK]"
    else 
      cat "$TMP"
    fi
  done
  rm $TMP
  rm main
fi

echo

popd > /dev/null


