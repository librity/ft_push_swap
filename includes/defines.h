/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:20:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/23 17:40:43 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define VERBOSE 0

/******************************************************************************\
 * STACKS
\******************************************************************************/

# define A_STACK_LABEL 'a'
# define B_STACK_LABEL 'b'

# define SWAP_A "sa"
# define SWAP_B "sb"
# define SWAP_A_AND_B "ss"

# define PUSH_TO_A "pa"
# define PUSH_TO_B "pb"

# define ROTATE_A "ra"
# define ROTATE_B "rb"
# define ROTATE_A_AND_B "rr"

# define REVERSE_ROTATE_A "rra"
# define REVERSE_ROTATE_B "rrb"
# define REVERSE_ROTATE_A_AND_B "rrr"

/******************************************************************************\
 * ERRORS
\******************************************************************************/

# define ERR_GENERIC "Error\n"
# define ERR_NULL_POINTER "ERROR: critical null pointer"

#endif
