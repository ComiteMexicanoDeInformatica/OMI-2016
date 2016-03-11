#!/bin/bash
#for i in `seq 0 9`;
#do
#  time ./solutions/Xpts < cases/small.$i.in > /dev/null
#done

echo 25pts
for i in `seq 0 9`;
do
  echo $i
  time ./solutions/25pts < cases/tiny.$i.in | ./validator
done


