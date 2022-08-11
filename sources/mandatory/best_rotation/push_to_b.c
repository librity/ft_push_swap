/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/11 13:41:59 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static bool	is_min_mid_or_max(t_groups v, int a_top)
{
	if (a_top == v.min)
		return (true);
	if (a_top == v.mid)
		return (true);
	if (a_top == v.max)
		return (true);
	return (false);
}

static bool	belongs_to_end(t_groups v, int a_top)
{
	if (a_top > v.mid_end && a_top < v.max)
		return (true);
	return (false);
}

static bool	belongs_to_start(t_groups v, int a_top)
{
	if (a_top > v.min && a_top < v.mid_start)
		return (true);
	return (false);
}

void	push_min_mid_groups_to_b(t_groups v)
{
	int	a_top;
	int	target_size;

	target_size = v.max - v.mid_end + 2;
	while (count_a() > target_size)
	{
		a_top = first_int_of_a();
		if (is_min_mid_or_max(v, a_top) || belongs_to_end(v, a_top))
		{
			execute(ROTATE_A);
			continue ;
		}
		execute(PUSH_TO_B);
		if (belongs_to_start(v, a_top))
			execute(ROTATE_B);
	}
}

void	push_max_group_to_b(t_groups v)
{
	int	a_top;

	while (count_a() > 3)
	{
		a_top = first_int_of_a();
		if (is_min_mid_or_max(v, a_top))
		{
			execute(ROTATE_A);
			continue ;
		}
		execute(PUSH_TO_B);
	}
}
