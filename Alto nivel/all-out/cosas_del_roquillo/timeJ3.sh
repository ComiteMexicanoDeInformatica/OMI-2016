echo 100pts
for i in `seq 0 9`;
do
  echo $i
  /usr/bin/time ./solutions/100ptsB < cases/big.$i.in | ./altval2
done


