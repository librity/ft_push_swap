/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/27 00:51:51 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	division(t_dlist **stack, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	pivot = get_int_by_index(stack, (start + end) / 2);
	i = start;
	j = end;
	while (true)
	{
		while (get_int_by_index(stack, i) < pivot)
			i++;
		while (get_int_by_index(stack, j) > pivot)
			j--;
		if (i >= j)
			return (j);
		swap_ints_by_index(stack, i, j);
	}
}

void	free_quick_sort(t_dlist **stack, int start, int end)
{
	int	division_index;

	if (start < 0)
		return ;
	if (end < 0)
		return ;
	if (start >= end)
		return ;
	division_index = division(stack, start, end);
	free_quick_sort(stack, start, division_index);
	free_quick_sort(stack, division_index + 1, end);
}

void	free_quick_sort_a(void)
{
	free_quick_sort(a(), 0, a_size() - 1);
	log_state();
}
