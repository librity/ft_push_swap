/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/20 17:32:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_dlist	*resolve_stack(char label)
{
	if (label == A_STACK_LABEL)
		return (*a());
	if (label == B_STACK_LABEL)
		return (*b());
	die();
	return (NULL);
}

static void	s(char label)
{
	t_dlist	*stack;
	int		*aux;

	stack = resolve_stack(label);
	if (stack == NULL)
		return ;
	if (stack->next == NULL)
		return ;
	aux = stack->content;
	stack->content = stack->next->content;
	stack->next->content = aux;
}

void	sa(void)
{
	s('a');
	ft_putendl_fd("sa", STDOUT_FILENO);
}

void	sb(void)
{
	s('b');
	ft_putendl_fd("sb", STDOUT_FILENO);
}

void	ss(void)
{
	s('a');
	s('b');
	ft_putendl_fd("ss", STDOUT_FILENO);
}
