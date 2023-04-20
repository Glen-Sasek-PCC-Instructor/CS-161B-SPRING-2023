#! /bin/bash

# .Grading-Utilities/test-all.sh .temp/A2 Assignment-2

source_file_path=$(realpath "$1")

test_path=$(realpath "$2")/Test/run_tests.sh

pushd $source_file_path > /dev/null

for x in *.cpp; 
do 
  if [[ $x < $3 ]]
  then
    continue;
  fi
  echo "FILE: $x"
  $test_path $(realpath "$x" )
  read -p "Press enter to continue..."
done

popd > dev/null