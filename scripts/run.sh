# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 19:02:23 by lpaulo-m          #+#    #+#              #
#    Updated: 2022/07/25 18:25:46 by lpaulo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP_DIR=""
PUSH_SWAP=""
CHECKER=""

# Value of INT_MAX is +2147483647.
# Value of INT_MIN is -2147483648.

# Black, Red, Green, Yellow, Blue, Purple, Cyan, White
BK="\033[0;30m"
R="\033[0;31m"
G="\033[0;32m"
Y="\033[0;33m"
B="\033[0;34m"
P="\033[0;35m"
C="\033[0;36m"
W="\033[0;37m"
# Bold
BKB="\033[1;30m"
RB="\033[1;31m"
GB="\033[1;32m"
YB="\033[1;33m"
BB="\033[1;34m"
PB="\033[1;35m"
CB="\033[1;36m"
WB="\033[1;37m"
# Reset Color
RC="\033[0m"

divider() {
	echo -e "${P}=======================================================${RC}"
}

separator() {
	divider
	echo
}

bad_stacks_banner() {
	divider
	echo -e "${RB}BAD STACKS: (SHOULD PRINT \"Error\\\\n\" AND RETURN 1) ${RC}"
	separator
}

empty_stacks_banner() {
	divider
	echo -e "${GB}EMPTY STACK: (SHOULDN'T PRINT ANYTHING AND RETURN 0) ${RC}"
	separator
}

good_stacks_banner() {
	divider
	echo -e "${GB}GOOD STACKS: (CHECKER SHOULD RETURN \"OK\\\\n\") ${RC}"
	separator
}

run_ps() {
	STACK="$1"

	echo -e "${C}EXECUTING: ./push_swap $STACK${RC}"
	./push_swap $STACK

	echo -e "${Y}RETURN: ${YB}$?${RC}"
	separator
}

run_checker() {
	echo -e "${C}EXECUTING: ./push_swap $1${RC}"
	CHECKER_RESULT=$(./push_swap $1 | ./scripts/checker_linux $1)

	echo -en "${Y}CHECKER: "
	if [ "$CHECKER_RESULT" == "OK" ]; then
		echo -en "${GB}OK${RC}"
	else
		echo -en "${RB}KO${RC}"
	fi
	echo -e "${RC}"
}

count_moves() {
	echo -en "${B}MOVES: ${BB}"
	./push_swap $1 | wc -l
	echo -e "${RC}"
}

run_ps_with_checker() {
	run_checker "$1"
	count_moves "$1"
	separator
}

make re || exit

################################################################################
# BAD STACKS
################################################################################

# bad_stacks_banner

# run_ps "2 one 3"
# run_ps "2 1.1 3"
# run_ps "2 1 -3.2"
# run_ps "2 +2147483648 3"
# run_ps "2 2147483648 3"
# run_ps "2 -2147483649 3"
# run_ps "2 2 3"
# run_ps "1 2 2 3"
# run_ps "3 2 1 3"
# run_ps "999999999999999999999999999999999999999999999999999999999999"
# run_ps "1 2 3 456	42	13	4684 -99999999999999999999999999999999999999999999999999999999999"
# run_ps "-50	- "

################################################################################
# EMPTY STACK
################################################################################

# empty_stacks_banner
# run_ps ""

################################################################################
# GOOD STACKS
################################################################################

# good_stacks_banner

run_ps_with_checker "1"

run_ps_with_checker "1 2"
run_ps_with_checker "2 1"

run_ps_with_checker "2 +2147483647 3"
run_ps_with_checker "2 2147483647 3"
run_ps_with_checker "2 -2147483648 3"
run_ps_with_checker "-2147483648 -2147483647 2147483647"
run_ps_with_checker "-2147483648 2147483647 -2147483647"
run_ps_with_checker "-2147483647 -2147483648 2147483647"
run_ps_with_checker "-2147483647 2147483647 -2147483648"
run_ps_with_checker "-2147483647 2147483647 -2147483648"
run_ps_with_checker "2147483647 -2147483647 -2147483648"

run_ps_with_checker "1 2 3"
run_ps_with_checker "2 1 3"
run_ps_with_checker "5 0 2"
run_ps_with_checker "2 5 0"
run_ps_with_checker "0 5 2"
run_ps_with_checker "3 2 1"
run_ps_with_checker "3 1 2"

run_ps_with_checker "1 5 2 4 3"
run_ps_with_checker "9680 577 2599 743 4127"
run_ps_with_checker "-2147483647 2147483647 -2147483648 0 9487 "

run_ps_with_checker "2 1 3 6 5 8"
run_ps_with_checker "1 2 3 5 6 8"
run_ps_with_checker "1 2 3 5 8 6"
run_ps_with_checker "2 1 3 6 5 10 8"

run_ps_with_checker "-2 23 -20 39 -33 -21 -46 10 17 -13 37 -24 -35 -19 15 8 -8 \
4 6 -44 -38 -11 -40 -22 -47 43 41 -1 29 48 28 -37 -45 11 -7 -26 30 26 -12 -14 \
-39 3 22 31 -25 -34 -42 21 -23 49 13 27 -9 -17 32 35 16 -41 38 -3 -29 44 33 42 \
46 -31 9 40 19 24 1 -48 2 50 18 -4 12 36 -6 45 -32 -30 14 47 -27 -5 20 -28 -49 \
-10 0 -36 -16 -18 5 7 34 -43 -15 25"

run_ps_with_checker "$(ruby -e "puts (1..10).to_a.shuffle.join(' ')")"
run_ps_with_checker "$(ruby -e "puts (1..500).to_a.shuffle.join(' ')")"
run_ps_with_checker "$(ruby -e "puts (1..1000).to_a.shuffle.join(' ')")"
run_ps_with_checker "$(ruby -e "puts (1..10000).to_a.shuffle.join(' ')")"
