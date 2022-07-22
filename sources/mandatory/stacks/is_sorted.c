/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 23:41:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/22 15:04:49 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	get_content(t_dlist *node)
{
	return (*(int *)(node->content));
}

static int	get_next_content(t_dlist *node)
{
	return (*(int *)(node->next->content));
}

bool	is_sorted(void)
{
	t_dlist	*node;
	int		current;
	int		next;

	if (*b() != NULL)
		return (false);
	node = *a();
	while (node->next != NULL)
	{
		current = get_content(node);
		next = get_next_content(node);
		if (current > next)
			return (false);
		node = node->next;
	}
	return (true);
}
