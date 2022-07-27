/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/26 15:39:30 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// static bool	smaller_than_pivot_in_stack(t_dlist *node, int pivot_int)
// {
// 	while (node)
// 	{
// 		if (get_int(node) < pivot_int)
// 			return (true);
// 		node = node->next;
// 	}
// 	return (false);
// }

// static int	division(int *array, int start, int end)
// {
// 	int	pivot;
// 	int	i;
// 	int	temp;
// 	int	j;

// 	pivot = array[end];
// 	i = start - 1;
// 	j = start;
// 	while (j < end)
// 	{
// 		if (array[j] <= pivot)
// 		{
// 			i++;
// 			temp = array[i];
// 			array[i] = array[j];
// 			array[j] = temp;
// 		}
// 		j++;
// 	}
// 	temp = array[i + 1];
// 	array[i + 1] = array[end];
// 	array[end] = temp;
// 	return (i + 1);
// }

// void	quick_sort(int *array, int start, int end)
// {
// 	int	q;

// 	if (start < end)
// 	{
// 		q = division(array, start, end);
// 		quick_sort(array, start, q - 1);
// 		quick_sort(array, q + 1, end);
// 	}
// }
