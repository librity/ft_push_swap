/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/09 17:25:32 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

t_operation_cb	resolve_operation(char *operation)
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
	return (NULL);
}

t_operation_cb	resolve_operation_or_die(char *operation)
{
	t_operation_cb	callbalk;

	callbalk = resolve_operation(operation);
	if (callbalk == NULL)
		die();
	return (callbalk);
}

void	execute(char *operation)
{
	t_operation_cb	callbalk;

	callbalk = resolve_operation_or_die(operation);
	callbalk();
	log_state();
}
