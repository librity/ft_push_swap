/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/24 21:05:28 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static bool	significant_is_one(int number, int bit_index)
{
	return ((number >> bit_index) & 1);
}

static void	sort_by_nth_bit(int bit_index)
{
	int	j;
	int	a_first;

	j = 0;
	while (j < get_stack_size())
	{
		a_first = get_first_int_of_a();
		if (significant_is_one(a_first, bit_index))
			execute("ra");
		else
			execute("pb");
		++j;
	}
}

static void	push_all_to_a(void)
{
	while (*b())
		execute("pa");
}

void	radix_sort(void)
{
	int	bit_index;

	bit_index = 0;
	while (!is_sorted())
	{
		sort_by_nth_bit(bit_index);
		push_all_to_a();
		++bit_index;
	}
}
