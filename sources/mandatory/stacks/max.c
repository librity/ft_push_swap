/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:52:19 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/24 21:53:49 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	find_max_int(t_dlist *node)
{
	int	max;

	max = NORMALIZE_MIN;
	while (node != NULL)
	{
		if (get_int(node) > max)
			max = get_int(node);
		node = node->next;
	}
	return (max);
}

t_dlist	*find_max_node(t_dlist *node)
{
	int	max;

	max = find_max_int(node);
	while (node != NULL)
	{
		if (get_int(node) == max)
			return (node);
		node = node->next;
	}
	return (NULL);
}

t_dlist	*find_max_node_in_a(void)
{
	return (find_max_node(*a()));
}
