#!/bin/bash

# SOURCE: https://github.com/wwwwelton/push_swap/blob/master/tester.sh

PUSH_SWAP_DIR=..
PUSH_SWAP=../push_swap
CHECKER=./checker_linux

make -C $PUSH_SWAP_DIR re
make -C $PUSH_SWAP_DIR bonus
clear

printf "\n"
echo "3 => max 3"
echo "==="
count=50
for i in $(seq $count); do
	ARGS=$(ruby -e "puts (0..2).to_a.shuffle.join(' ')")
	$PUSH_SWAP $ARGS | wc -l | tr '\n' ' '
	echo -n "| "
	$PUSH_SWAP $ARGS | $CHECKER $ARGS
done

printf "\n"
echo "100 => max 700"
echo "==="
count=50
for i in $(seq $count); do
	ARGS=$(ruby -e "puts (0..99).to_a.shuffle.join(' ')")
	$PUSH_SWAP $ARGS | wc -l | tr '\n' ' '
	echo -n "| "
	$PUSH_SWAP $ARGS | $CHECKER $ARGS
done

printf "\n"
echo "500 => max 5500"
echo "==="
count=50
for i in $(seq $count); do
	ARGS=$(ruby -e "puts (0..499).to_a.shuffle.join(' ')")
	$PUSH_SWAP $ARGS | wc -l | tr '\n' ' '
	echo -n "| "
	$PUSH_SWAP $ARGS | $CHECKER $ARGS
done
printf "\n"
