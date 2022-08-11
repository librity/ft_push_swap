/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/11 13:41:59 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	swap_push_and_restore(int first_rotations, int second_rotations)
{
	execute(PUSH_TO_B);
	execute(SWAP_B);
	execute(PUSH_TO_A);
	execute_n_times(REVERSE_ROTATE_A, second_rotations);
	execute(PUSH_TO_A);
	execute_n_times(REVERSE_ROTATE_A, first_rotations);
}

static void	swap_with_operations(int i_index, int j_index)
{
	t_dlist	*i_target;
	t_dlist	*j_target;
	int		first_rotations;
	int		second_rotations;

	first_rotations = 0;
	second_rotations = 0;
	i_target = a_get_node(i_index);
	j_target = a_get_node(j_index);
	while (first_of_a() != i_target)
	{
		execute(ROTATE_A);
		first_rotations++;
	}
	execute(PUSH_TO_B);
	while (first_of_a() != j_target)
	{
		execute(ROTATE_A);
		second_rotations++;
	}
	swap_push_and_restore(first_rotations, second_rotations);
}

static int	partition(t_dlist **stack, int start, int end)
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
		swap_with_operations(i, j);
	}
}

void	quick_sort(t_dlist **stack, int start, int end)
{
	int	division_index;

	if (start < 0)
		return ;
	if (end < 0)
		return ;
	if (start >= end)
		return ;
	division_index = partition(stack, start, end);
	quick_sort(stack, start, division_index);
	quick_sort(stack, division_index + 1, end);
}

void	quick_sort_a(void)
{
	quick_sort(a(), 0, count_a() - 1);
}
