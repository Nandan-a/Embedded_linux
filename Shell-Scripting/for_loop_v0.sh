times=0
for num in {1..10..2}
do
echo "current num = $num"
times=$(( $times + 1 )) 
done
echo "total_iteration = $times"

times=0
for num in {1..10}
do
echo "current num = $num"
times=$(( $times + 1 )) 
done
echo "total_iteration = $times"
#-------------------Third way----------------#
start=2
for (( count=$start; count<=5; count++ ))
do
    echo "current count = $count"
done 