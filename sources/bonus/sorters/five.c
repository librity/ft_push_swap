/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:33:02 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/27 20:41:20 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	rotate_min_to_top(void)
{
	int		min_index;

	min_index = find_min_index_in_a();
	if (min_index == 0)
		return ;
	rotate_to_top_of_a(min_index);
}

static void	push_mins_to_b(void)
{
	while (a_size() > 3)
	{
		rotate_min_to_top();
		execute(PUSH_TO_B);
	}
}

void	five_sort(void)
{
	push_mins_to_b();
	three_sort();
	push_all_to_a();
}
