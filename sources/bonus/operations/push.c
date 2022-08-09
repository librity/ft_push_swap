/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/09 19:18:53 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

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
	pushed = ft_dlst_pluck_first(origin(label));
	ft_dlstadd_front(destination(label), pushed);
}

void	pa(void)
{
	p_('a');
}

void	pb(void)
{
	p_('b');
}
