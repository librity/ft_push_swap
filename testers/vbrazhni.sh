#!/bin/bash

# SOURCE: https://github.com/VBrazhnik/Push_swap/blob/master/benchmark.sh

PUSH_SWAP_DIR=..
PUSH_SWAP=../push_swap
CHECKER=./checker_linux

MAX=0
ITERATIONS=0
LIMIT=700
FILE=problem_100.txt
SUM=0

for i in {1..1000}; do
	export ARG=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')")
	if $PUSH_SWAP $ARG | $CHECKER $ARG | grep -q KO; then
		echo "Error!"
		echo $ARG
		break
	fi
	NUMBER="$($PUSH_SWAP $ARG | wc -l | sed 's/ //g')"
	if [ "$NUMBER" -gt "$LIMIT" ]; then
		echo $NUMBER >>$FILE
		echo $ARG >>$FILE
	fi
	if [ "$NUMBER" -gt "$MAX" ]; then
		MAX=$NUMBER
	fi
	echo $i ":" $NUMBER
	let SUM+=$NUMBER
	let ITERATIONS+=1
done

echo "AVG: $(($SUM / $ITERATIONS))"
echo "MAX: " $MAX
