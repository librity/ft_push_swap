/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/20 22:36:33 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_operation_cb	resolve_callback_or_die(char *operation)
{
	if (ft_streq(operation, SWAP_A))
		return (sa);
	if (ft_streq(operation, SWAP_B))
		return (sb);
	if (ft_streq(operation, SWAP_A_AND_B))
		return (ss);
	if (ft_streq(operation, PUSH_TO_A))
		return (pa);
	if (ft_streq(operation, PUSH_TO_B))
		return (pb);
	if (ft_streq(operation, ROTATE_A))
		return (ra);
	if (ft_streq(operation, ROTATE_B))
		return (rb);
	if (ft_streq(operation, ROTATE_A_AND_B))
		return (rr);
	if (ft_streq(operation, REVERSE_ROTATE_A))
		return (rra);
	if (ft_streq(operation, REVERSE_ROTATE_B))
		return (rrb);
	if (ft_streq(operation, REVERSE_ROTATE_A_AND_B))
		return (rrr);
	die();
	return (NULL);
}

void	execute(char *operation)
{
	void	(*callbalk)(void);

	callbalk = resolve_callback_or_die(operation);
	callbalk();
	log_stacks();
}
