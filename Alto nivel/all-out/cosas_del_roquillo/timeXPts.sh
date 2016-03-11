#!/bin/bash
#for i in `seq 0 9`;
#do
#  time ./solutions/Xpts < cases/small.$i.in > /dev/null
#done

echo Xpts
for i in `seq 0 9`;
do
  echo $i
  time ./solutions/Xpts < cases/small.$i.in > /dev/null
done


