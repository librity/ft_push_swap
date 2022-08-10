/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_by_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 23:41:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/10 00:54:49 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	get_index_by_int(t_dlist **stack, int needle)
{
	t_dlist	*node;
	int		index;

	node = *stack;
	index = 0;
	while (node != NULL)
	{
		if (get_int(node) == needle)
			return (index);
		index++;
		node = node->next;
	}
	return (-1);
}

int	get_a_index_by_int(int needle)
{
	return (get_index_by_int(a(), needle));
}

int	get_b_index_by_int(int needle)
{
	return (get_index_by_int(b(), needle));
}
