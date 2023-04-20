#! /bin/bash

source_file_path=$(realpath "$1")

test_path=$(realpath "$2")/Test/run_tests.sh

pushd $source_file_path > /dev/null

for x in *.cpp; 
do 
  $test_path $(realpath "$x" )
  read -p "Press enter to continue..."
done

popd > dev/null