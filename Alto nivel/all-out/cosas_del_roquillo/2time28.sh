echo 100pts
for i in `seq 0 9`;
do
  echo $i
  rm data.in
  cp cases/big.$i.in data.in
  time ./solutions/100B < data.in | ./validator
done


