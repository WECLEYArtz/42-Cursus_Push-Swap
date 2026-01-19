#!/bin/bash

MAX=5500;

TEST=0
RES=0;
CHECKER=0;
COUNT=0

while true;
do
	TEST=$(seq -500 500 | shuf -n 500 | tr "\n" " ")
	RES=$(./push_swap $TEST | wc -l)
	CHECKER=$(./push_swap $TEST | ./checker_linux $TEST)
	echo $RES at $COUNT is $CHECKER
	((COUNT++))
	if [ $RES -gt $MAX ]; then
		echo "Failed!"
		echo "Failed with $RES\n\n" $TEST > failed.txt # comment if save unwanted
		exit
	fi
done
