/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:33:02 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/25 13:04:53 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	rotate_untill_min_on_top(char *rotation)
{
	int	min_a;

	min_a = find_min_int_in_a();
	while (get_first_int_of_a() != min_a)
		execute(rotation);
}

static bool	min_is_halfway_down(int min_index)
{
	return (min_index > a_size() / 2);
}

static void	rotate_min_to_top(void)
{
	int		min_index;
	char	*rotation;

	min_index = find_min_index_in_a();
	if (min_index == 0)
		return ;
	if (min_is_halfway_down(min_index))
		rotation = REVERSE_ROTATE_A;
	else
		rotation = ROTATE_A;
	rotate_untill_min_on_top(rotation);
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
