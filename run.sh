#! /bin/bash

this_path=$(realpath $0)

dirs=$(mktemp)
find -mindepth 1 -maxdepth 1 -type d -not -name ".*" -not -name "Examples" -printf "%P\n" | sort > $dirs

menu () {
  clear
  awk '{print "[" FNR "] " $0}' $dirs
  if [ -d 'Examples' ]
  then
    echo [E] Examples
  fi
  echo [M] Menu
  echo [Q] Quit / Previous Directory
}

menu

while true
do
  read -p "SELECT [OPTION]: " n
  
  if [ $n = q -o $n = Q ]
  then
    break
  elif [ $n = e -o $n = E ]
  then
    d=Examples
  elif [ $n = m -o $n = M ]
  then
    menu
    continue
  else
    d=$(sed -n ${n}p $dirs)
  fi
  
  pushd "${d[*]}" > /dev/null
  
  if [ -f run.sh ]
  then
    echo -e "\n"
    ./run.sh
    echo -e "\n"
    popd > /dev/null  
  else
    $this_path # Recursive: Run this run.sh in selected working directory
    popd > /dev/null 
    menu
  fi
done

if [ -f $dirs ]
then
  rm $dirs
fi

