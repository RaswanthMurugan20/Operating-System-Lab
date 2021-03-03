#!/bin/bash

## Modify the above line to point to bash executable in your system

## ROLL NUMBERS OF THE TEAM-MATES ##
#    1.111801056 
#    2.111801028 
#    3.111801006 
#    4.111801022 
### 
#time: -
#real	9m41.557s
#user	9m39.011s
#sys	0m23.310s

## Write your script below this line ##

mkdir courses
touch ./courses/base.csv 


for j in `cut -d "," -f2 $1 | sort -u`
do
   touch ./courses/$j.csv
   `grep $j $1 | sort -ur > ./courses/base.csv`
   `awk -F',' '!seen[$1]++' ./courses/base.csv > ./courses/$j.csv`  
done

rm ./courses/base.csv

touch base.csv CS.csv CE.csv ME.csv EE.csv

CE=`ls ./courses/ | grep "^CE"`
CS=`ls ./courses/ | grep "^CS"`
EE=`ls ./courses/ | grep "^EE"`
ME=`ls ./courses/ | grep "^ME"`

####################################
for k in CS EE CE ME
do
  X=`ls ./courses/ | grep "^$k"`  
  for i in $X
  do	  
    `cat ./courses/$i >> base.csv`   
  done

  tempa="ROLL NO"
  for j in `cut -d "," -f2 base.csv | sort -u`
  do
    tempa+=", $j"	
  done
  `echo "$tempa" >> $k.csv`

  for p in `cut -d "," -f1 base.csv | sort -u`
  do
    temp="" 
    for q in $X
    do    
      mark=`grep $p ./courses/$q | cut -d "," -f3` 
      temp+=", $mark"
    done
  `echo "$p$temp" >> $k.csv`
  done
  rm base.csv
  touch base.csv
done

rm base.csv
