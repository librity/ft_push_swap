/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/21 22:26:09 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_dlist	**resolve_stack(char label)
{
	if (label == A_STACK_LABEL)
		return (a());
	if (label == B_STACK_LABEL)
		return (b());
	die();
	return (NULL);
}

static void	rr_(char label)
{
	t_dlist	**stack;
	t_dlist	*moved;

	stack = resolve_stack(label);
	if (*stack == NULL)
		return ;
	if ((*stack)->next == NULL)
		return ;
	moved = ft_dlst_pluck_last(stack);
	ft_dlstadd_front(stack, moved);
}

void	rra(void)
{
	rr_('a');
	ft_putendl_fd("rra", STDOUT_FILENO);
}

void	rrb(void)
{
	rr_('b');
	ft_putendl_fd("rrb", STDOUT_FILENO);
}

void	rrr(void)
{
	rr_('a');
	rr_('b');
	ft_putendl_fd("rrr", STDOUT_FILENO);
}
