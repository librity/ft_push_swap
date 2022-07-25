/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:33:02 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/24 23:39:06 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	push_mins_to_b(void)
{
	int	min_index;
	int	min_a;

	while (a_size() > 3)
	{
		min_a = find_min_int_in_a();
		min_index = find_min_index_in_a();
		if (min_index != 0)
		{
			if (min_index > a_size() / 2)
				while (get_first_int_of_a() != min_a)
					execute("rra");
			else
				while (get_first_int_of_a() != min_a)
					execute("ra");
		}
		execute("pb");
	}
}

void	five_sort(void)
{
	push_mins_to_b();
	three_sort();
	push_all_to_a();
}
