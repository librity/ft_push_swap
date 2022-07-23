/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 23:41:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/22 22:16:16 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
		current = get_int(node);
		next = get_next_int(node);
		if (current > next)
			return (false);
		node = node->next;
	}
	return (true);
}
