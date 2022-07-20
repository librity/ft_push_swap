# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 19:02:23 by lpaulo-m          #+#    #+#              #
#    Updated: 2022/07/20 12:59:50 by lpaulo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

make re || exit ; echo "================" ;

# ./push_swap ; echo "RETURN: $?" ; echo "================" ;
# ./push_swap 2 one 3 ; echo "RETURN: $?" ; echo "================" ;
# ./push_swap 2 1.1 3 ; echo "RETURN: $?" ; echo "================" ;
# ./push_swap 2 1 -3.2 ; echo "RETURN: $?" ; echo "================" ;

# ./push_swap 2 +2147483647 3 ; echo "RETURN: $?" ; echo "================" ;
# ./push_swap 2 +2147483648 3 ; echo "RETURN: $?" ; echo "================" ;

# ./push_swap 2 2147483647 3 ; echo "RETURN: $?" ; echo "================" ;
# ./push_swap 2 2147483648 3 ; echo "RETURN: $?" ; echo "================" ;

# ./push_swap 2 -2147483648 3 ; echo "RETURN: $?" ; echo "================" ;
# ./push_swap 2 -2147483649 3 ; echo "RETURN: $?" ; echo "================" ;

# ./push_swap 2 2 3 ; echo "RETURN: $?" ; echo "================" ;
# ./push_swap 1 2 2 3 ; echo "RETURN: $?" ; echo "================" ;
# ./push_swap 3 2 1 3 ; echo "RETURN: $?" ; echo "================" ;

# ./push_swap 1 ; echo "RETURN: $?" ; echo "================" ;
# ./push_swap 1 2 3 ; echo "RETURN: $?" ; echo "================" ;
# ./push_swap 2 1 3 ; echo "RETURN: $?" ; echo "================" ;
./push_swap 2 1 3 6 5 8 ; echo "RETURN: $?" ; echo "================" ;
# ./push_swap 3 2 1 ; echo "RETURN: $?" ; echo "================" ;
# ./push_swap 3 1 2 ; echo "RETURN: $?" ; echo "================" ;
