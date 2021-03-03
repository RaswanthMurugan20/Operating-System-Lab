#!/bin/sh
sub=`cut -d "," -f2 $1 | sort -u`
echo "NAME" $sub
for i in `cut -d "," -f1 $1 | sort -u`
do
   marks=`grep $i $1 |cut -d "," -f3`   
   echo $i $marks
done  

