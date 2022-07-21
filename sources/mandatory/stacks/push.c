/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/20 22:41:15 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_dlist	**origin(char label)
{
	if (label == A_STACK_LABEL)
		return (b());
	if (label == B_STACK_LABEL)
		return (a());
	die();
	return (NULL);
}

static t_dlist	**destination(char label)
{
	if (label == A_STACK_LABEL)
		return (a());
	if (label == B_STACK_LABEL)
		return (b());
	die();
	return (NULL);
}

static void	p_(char label)
{
	t_dlist	*pushed;

	if (*origin(label) == NULL)
		return ;
	pushed = *origin(label);
	*origin(label) = pushed->next;
	if (*origin(label) != NULL)
		(*origin(label))->prev = NULL;
	ft_dlstadd_front(destination(label), pushed);
}

void	pa(void)
{
	p_('a');
	ft_putendl_fd("pa", STDOUT_FILENO);
}

void	pb(void)
{
	p_('b');
	ft_putendl_fd("pb", STDOUT_FILENO);
}
