/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:52:19 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/27 18:27:54 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	find_min_int(t_dlist **stack)
{
	t_dlist	*node;
	int		min;

	min = find_max_int(stack);
	node = *stack;
	while (node != NULL)
	{
		if (get_int(node) < min)
			min = get_int(node);
		node = node->next;
	}
	return (min);
}

t_dlist	*find_min_node(t_dlist **stack)
{
	t_dlist	*node;
	int		min;

	min = find_min_int(stack);
	node = *stack;
	while (node != NULL)
	{
		if (get_int(node) == min)
			return (node);
		node = node->next;
	}
	return (NULL);
}

int	find_min_index(t_dlist **stack)
{
	t_dlist	*node;
	int		index;

	node = find_min_node(stack);
	index = 0;
	if (node == NULL)
		return (DLIST_BAD_INDEX_CODE);
	while (node->prev != NULL)
	{
		node = node->prev;
		index++;
	}
	return (index);
}
