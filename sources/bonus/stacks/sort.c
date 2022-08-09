/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 23:41:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/09 19:50:15 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

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

void	validate_sort(void)
{
	if (is_sorted())
	{
		ft_putstr(SORTED_MESSAGE);
		return ;
	}
	ft_putstr(UNSORTED_MESSAGE);
}
