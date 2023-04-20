#! /bin/bash

pushd "$1" > /dev/null

for x in *.pdf; 
do 
  mv "$x" $(echo $x | awk '{print $3 "-" $6 "-" $7}' | awk -F '-' '{print $1 "-" $3 ".pdf"}');
done

for x in *.cpp; 
do 
  mv "$x" $(echo $x | awk '{print $3 "-" $6 "-" $7}' | awk -F '-' '{print $1 "-" $3 ".pdf"}');
done

popd > dev/null