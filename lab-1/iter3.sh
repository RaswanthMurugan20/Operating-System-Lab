#!/bin/bash
mkdir courses
touch ./courses/base.csv 

stud=`cut -d "," -f1 $1 | sort -ur`

CS=`cut -d "," -f1 $1 | grep "^111" | sort -ur`
CE=`cut -d "," -f1 $1 | grep "^101" | sort -ur`
EE=`cut -d "," -f1 $1 | grep "^121" | sort -ur`
ME=`cut -d "," -f1 $1 | grep "^131" | sort -ur`

touch csb.csv ceb.csv meb.csv eeb.csv
touch CS.csv CE.csv EE.csv ME.csv

`sort -ur $1 | awk -F',' '!seen[$1,$2]++' > ./courses/base.csv`

`echo "" >> csb.csv`
for k in $CS
 do
 `echo "$k" >> csb.csv`
 done

`echo "" >> ceb.csv`
for k in $CE
 do
 `echo "$k" >> ceb.csv`
 done

`echo "" >> eeb.csv`
for k in $EE
 do
 `echo "$k" >> eeb.csv`
 done

`echo "" >> meb.csv`
for k in $ME
 do
 `echo "$k" >> meb.csv`
 done



#for j in `cut -d "," -f2 $1 | sort -u`
#do
#   touch ./courses/$j.csv
#   `echo ",$j" >> ./courses/$j.csv`

   if [ "${j:0:2}" = "CE" ]; then
    s=$CE
    c="CE"
    b="ceb"  
   elif [ "${j:0:2}" = "CS" ]; then
    s=$CS
    c="CS"
    b="csb"
   elif [ "${j:0:2}" = "EE" ]; then
    s=$EE
    c="EE"
    b="eeb"
   else
    s=$ME
    c="ME"
    b="meb"
   fi

   for i in $s
    do
       mark=`grep "$i,$j" ./courses/base.csv | cut -d "," -f3` 
      `echo "$i,$mark" >> ./courses/$j.csv`
    done

   #`join -t "," $b.csv ./courses/$j.csv > $c.csv`
   #`cat $c.csv > $b.csv`

#done

rm csb.csv ceb.csv meb.csv eeb.csv

