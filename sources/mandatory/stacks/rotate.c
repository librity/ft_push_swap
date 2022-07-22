/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/21 22:26:18 by lpaulo-m         ###   ########.fr       */
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

static void	r_(char label)
{
	t_dlist	**stack;
	t_dlist	*moved;

	stack = resolve_stack(label);
	if (*stack == NULL)
		return ;
	if ((*stack)->next == NULL)
		return ;
	moved = ft_dlst_pluck_first(stack);
	ft_dlstadd_back(stack, moved);
}

void	ra(void)
{
	r_('a');
	ft_putendl_fd("ra", STDOUT_FILENO);
}

void	rb(void)
{
	r_('b');
	ft_putendl_fd("rb", STDOUT_FILENO);
}

void	rr(void)
{
	r_('a');
	r_('b');
	ft_putendl_fd("rr", STDOUT_FILENO);
}
