/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/20 22:02:52 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	handle_swap(char *operation)
{
	if (ft_streq(operation, SWAP_A))
		sa();
	if (ft_streq(operation, SWAP_B))
		sb();
	if (ft_streq(operation, SWAP_A_AND_B))
		ss();
}

static void	handle_push(char *operation)
{
	if (ft_streq(operation, PUSH_TO_A))
		pa();
	if (ft_streq(operation, PUSH_TO_B))
		pb();
}

static void	handle_rotate(char *operation)
{
	if (ft_streq(operation, ROTATE_A))
		ra();
	if (ft_streq(operation, ROTATE_B))
		rb();
	if (ft_streq(operation, ROTATE_A_AND_B))
		rr();
}

// static void	handle_reverse_rotate(char *operation)
// {
// 	if (ft_streq(operation, REVERSE_ROTATE_A))
// 		rra();
// 	if (ft_streq(operation, REVERSE_ROTATE_B))
// 		rrb();
// 	if (ft_streq(operation, REVERSE_ROTATE_A_AND_B))
// 		rrr();
// }

void	execute(char *operation)
{
	handle_swap(operation);
	handle_push(operation);
	handle_rotate(operation);
	// handle_reverse_rotate(operation);
	log_stacks();
}
