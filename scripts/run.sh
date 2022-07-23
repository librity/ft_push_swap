# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 19:02:23 by lpaulo-m          #+#    #+#              #
#    Updated: 2022/07/23 17:57:30 by lpaulo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
	printf "${P}=======================================================${RC}\n"
	echo
}

make re || exit
divider

################################################################################
# ERRORS
################################################################################

# ./push_swap ; echo "RETURN: $?" ; divider
# ./push_swap 2 one 3 ; echo "RETURN: $?" ; divider
# ./push_swap 2 1.1 3 ; echo "RETURN: $?" ; divider
# ./push_swap 2 1 -3.2 ; echo "RETURN: $?" ; divider

# ./push_swap 2 +2147483647 3 ; echo "RETURN: $?" ; divider
# ./push_swap 2 +2147483648 3 ; echo "RETURN: $?" ; divider

# ./push_swap 2 2147483647 3 ; echo "RETURN: $?" ; divider
# ./push_swap 2 2147483648 3 ; echo "RETURN: $?" ; divider

# ./push_swap 2 -2147483648 3 ; echo "RETURN: $?" ; divider
# ./push_swap 2 -2147483649 3 ; echo "RETURN: $?" ; divider

# ./push_swap 2 2 3 ; echo "RETURN: $?" ; divider
# ./push_swap 1 2 2 3 ; echo "RETURN: $?" ; divider
# ./push_swap 3 2 1 3 ; echo "RETURN: $?" ; divider

################################################################################
# VALID STACKS
################################################################################

# ./push_swap 1 ; echo "RETURN: $?" ; divider
# ./push_swap 1 2 ; echo "RETURN: $?" ; divider
# ./push_swap 2 1 ; echo "RETURN: $?" ; divider
# ./push_swap 1 2 3 ; echo "RETURN: $?" ; divider
# ./push_swap 2 1 3 ; echo "RETURN: $?" ; divider
# ./push_swap 2 1 3 6 5 8 ; echo "RETURN: $?" ; divider
# ./push_swap 9680 577 2599 743 4127 ; echo "RETURN: $?" ; divider
# ./push_swap 2 1 3 6 5 10 8 ; echo "RETURN: $?" ; divider
# ./push_swap 1 2 3 5 6 8 ; echo "RETURN: $?" ; divider
# ./push_swap 1 2 3 5 8 6 ; echo "RETURN: $?" ; divider
# ./push_swap 3 2 1 ; echo "RETURN: $?" ; divider
# ./push_swap 3 1 2 ; echo "RETURN: $?" ; divider

LIST=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')")
./push_swap $LIST | ./scripts/checker_linux $LIST
./push_swap $LIST | wc -l
divider

# LIST=$(ruby -e "puts (1..1000).to_a.shuffle.join(' ')")
# ./push_swap $LIST | ./scripts/checker_linux $LIST
# ./push_swap $LIST | wc -l
# divider

# LIST=$(ruby -e "puts (1..10000).to_a.shuffle.join(' ')")
# ./push_swap $LIST | ./scripts/checker_linux $LIST
# ./push_swap $LIST | wc -l
# divider
