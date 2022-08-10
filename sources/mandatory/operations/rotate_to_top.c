/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:50:40 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/09 21:04:59 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static char	*resolve_r(char label)
{
	if (label == A_STACK_LABEL)
		return (ROTATE_A);
	if (label == B_STACK_LABEL)
		return (ROTATE_B);
	die();
	return (NULL);
}

static char	*resolve_rr(char label)
{
	if (label == A_STACK_LABEL)
		return (REVERSE_ROTATE_A);
	if (label == B_STACK_LABEL)
		return (REVERSE_ROTATE_B);
	die();
	return (NULL);
}

static t_dlist	**resolve_stack(char label)
{
	if (label == A_STACK_LABEL)
		return (a());
	if (label == B_STACK_LABEL)
		return (b());
	die();
	return (NULL);
}

static void	rotate_to_top(char label, int index)
{
	t_dlist	**stack;
	char	*r;
	char	*rr;
	int		r_moves;
	int		rr_moves;

	stack = resolve_stack(label);
	if (ft_dlst_index_out_of_bounds(stack, index))
		return ;
	r = resolve_r(label);
	rr = resolve_rr(label);
	r_moves = index;
	rr_moves = ft_dlstsize(*stack) - index;
	if (rr_moves >= r_moves)
		return (execute_n_times(r, r_moves));
	execute_n_times(rr, rr_moves);
}

void	rotate_to_top_of_a(int index)
{
	rotate_to_top('a', index);
}

void	rotate_to_top_of_b(int index)
{
	rotate_to_top('b', index);
}
