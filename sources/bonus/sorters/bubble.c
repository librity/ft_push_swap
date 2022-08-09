/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/25 19:12:00 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	push_smallest_to_b(void)
{
	t_dlist	*first;
	t_dlist	*second;

	while (first_of_a()->next != NULL)
	{
		first = first_of_a();
		second = first->next;
		if (get_int(first) < get_int(second))
		{
			execute(PUSH_TO_B);
			continue ;
		}
		execute(SWAP_A);
		execute(PUSH_TO_B);
	}
}

void	bubble_sort(void)
{
	while (!is_sorted())
	{
		push_smallest_to_b();
		push_all_to_a();
	}
}
