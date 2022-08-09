/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:52:19 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/27 18:30:59 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	find_max_int(t_dlist **stack)
{
	t_dlist	*node;
	int		max;

	max = NORMALIZE_MIN;
	node = *stack;
	while (node != NULL)
	{
		if (get_int(node) > max)
			max = get_int(node);
		node = node->next;
	}
	return (max);
}

t_dlist	*find_max_node(t_dlist **stack)
{
	t_dlist	*node;
	int		max;

	max = find_max_int(stack);
	node = *stack;
	while (node != NULL)
	{
		if (get_int(node) == max)
			return (node);
		node = node->next;
	}
	return (NULL);
}

int	find_max_index(t_dlist **stack)
{
	t_dlist	*node;
	int		index;

	index = 0;
	node = find_max_node(stack);
	if (node == NULL)
		return (DLIST_BAD_INDEX_CODE);
	while (node->prev != NULL)
	{
		node = node->prev;
		index++;
	}
	return (index);
}
