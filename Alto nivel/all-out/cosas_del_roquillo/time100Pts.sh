#!/bin/bash
#for i in `seq 0 9`;
#do
#  time ./solutions/Xpts < cases/small.$i.in > /dev/null
#done

echo 100pts
for i in `seq 0 9`;
do
  echo $i
  time ./100A < cases/big.$i.in | ./validator
done


