/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:52:19 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/24 21:03:23 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	find_biggest_int(t_dlist *node)
{
	int	biggest;

	biggest = NORMALIZE_MIN;
	while (node != NULL)
	{
		if (get_int(node) > biggest)
			biggest = get_int(node);
		node = node->next;
	}
	return (biggest);
}

t_dlist	*find_biggest_node(t_dlist *node)
{
	int	biggest;

	biggest = find_biggest_int(node);
	while (node != NULL)
	{
		if (get_int(node) == biggest)
			return (node);
		node = node->next;
	}
	return (NULL);
}

t_dlist	*find_biggest_node_in_a(void)
{
	return (find_biggest_node(*a()));
}
