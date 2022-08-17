/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_of_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/17 11:33:07 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	find_insertion(int inserted)
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
		if (intermediate < inserted)
		{
			ft_dlst_free(&clone);
			return (intermediate);
		}
		node = node->prev;
	}
	ft_dlst_free(&clone);
	return (-1);
}

static int	find_insertion_index(int inserted)
{
	int		intermediate;

	intermediate = find_insertion(inserted);
	return (get_b_index_by_int(intermediate));
}

int	get_b_insertion_index(int inserted_index)
{
	int	inserted;
	int	min;
	int	max;

	inserted = get_a_int_by_index(inserted_index);
	min = find_min_int_in_b();
	max = find_max_int_in_b();
	if (inserted > max)
		return (find_max_index_in_b());
	if (inserted < min)
		return (find_max_index_in_b());
	return (find_insertion_index(inserted));
}
