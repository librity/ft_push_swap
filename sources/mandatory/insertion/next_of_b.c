/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_of_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/10 13:46:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	find_intermediate(int a_next)
{
	t_dlist	*clone;
	t_dlist	*node;
	int		intermediate;

	clone = clone_stack(b());
	free_quick_sort_stack(&clone);
	node = ft_dlstlast(clone);
	while (node != NULL)
	{
		intermediate = get_int(node);
		if (intermediate < a_next)
		{
			ft_dlst_free(&clone);
			return (intermediate);
		}
		node = node->prev;
	}
	ft_dlst_free(&clone);
	return (-1);
}

static int	find_intermediate_index(int a_next)
{
	int		intermediate;

	intermediate = find_intermediate(a_next);
	return (get_b_index_by_int(intermediate));
}

int	insertion_get_next_of_b_index(int a_next_index)
{
	int	a_next;
	int	min;
	int	max;

	a_next = get_a_int_by_index(a_next_index);
	min = find_min_int_in_b();
	max = find_max_int_in_b();
	if (a_next > max)
		return (find_max_index_in_b());
	if (a_next < min)
		return (find_max_index_in_b());
	return (find_intermediate_index(a_next));
}
