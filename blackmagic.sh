TEST=0
RES=0;
MAX=5500;
COUNT=0

while true;
do
	TEST=$(shuf -i  1-500 -n 500)
	RES=$(./push_swap $TEST | wc -l)
	echo $RES at $COUNT
	((COUNT++))
	if [ $RES -gt $MAX ]; then
		echo "Failed!"
		echo "Failed with $RES\n\n" $TEST > failed.txt # comment if save unwanted
		exit
	fi
done
