/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/09 16:54:37 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

static t_dlist	**resolve_stack(char label)
{
	if (label == A_STACK_LABEL)
		return (a());
	if (label == B_STACK_LABEL)
		return (b());
	die();
	return (NULL);
}

static void	s_(char label)
{
	t_dlist	**stack;
	t_dlist	*first;
	t_dlist	*second;

	stack = resolve_stack(label);
	if (*stack == NULL)
		return ;
	if ((*stack)->next == NULL)
		return ;
	first = ft_dlst_pluck_first(stack);
	second = ft_dlst_pluck_first(stack);
	ft_dlstadd_front(stack, first);
	ft_dlstadd_front(stack, second);
}

void	sa(void)
{
	s_('a');
}

void	sb(void)
{
	s_('b');
}

void	ss(void)
{
	s_('a');
	s_('b');
}
