/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/17 11:34:28 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	find_min_mid_max(t_groups *v)
{
	v->min = find_min_int_in_a();
	v->mid_start = total_size() / 4;
	v->mid = total_size() / 2;
	v->mid_end = total_size() * 3 / 4;
	v->max = find_max_int_in_a();
}

static void	push_groups_to_b(void)
{
	t_groups	v;

	find_min_mid_max(&v);
	push_min_mid_groups_to_b(v);
	push_max_group_to_b(v);
	three_sort();
}

void	insertion_sort_v2(void)
{
	push_groups_to_b();
	insert_in_a_by_best_rotation();
	rotate_min_to_top_of_a();
}
