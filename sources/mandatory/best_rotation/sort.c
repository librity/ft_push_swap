/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/10 14:00:57 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	find_min_mid_max(t_min_max_sort_vars *v)
{
	t_dlist	*clone;

	clone = clone_stack(a());
	free_quick_sort_stack(&clone);
	v->min = find_min_int_in_a();
	v->mid_start = get_int_by_index(&clone, total_size() / 3);
	v->mid_end = get_int_by_index(&clone, total_size() * 2 / 3);
	v->mid = v->mid_start + ((v->mid_end - v->mid_start) / 2);
	v->max = find_max_int_in_a();
	ft_dlst_free(&clone);
}

static void	push_min_mid_groups_to_b(t_min_max_sort_vars v)
{
	int	a_top;
	int	size;

	size = a_size();
	while (size || size > 3)
	{
		a_top = first_int_of_a();
		if (a_top > v.min && a_top < v.mid_start)
		{
			execute(PUSH_TO_B);
			execute(ROTATE_B);
		}
		else if (
			a_top >= v.mid_start
			&& a_top <= v.mid_end
			&& a_top != v.mid)
			execute(PUSH_TO_B);
		else if (
			(a_top > v.mid_end && a_top <= v.max)
			|| (a_top == v.min || a_top == v.mid))
			execute(ROTATE_A);
		size--;
	}
}

static void	push_max_group_to_b(t_min_max_sort_vars v)
{
	int			code;
	int			i;
	int			tmp;

	i = a_size();
	while (i--)
	{
		tmp = first_int_of_a();
		code = 1;
		if (tmp != v.max && tmp != v.mid && tmp != v.min)
		{
			execute(PUSH_TO_B);
			code = 0;
		}
		if (code)
		{
			execute(ROTATE_A);
		}
	}
}

static void	push_groups_to_b(void)
{
	t_min_max_sort_vars	v;

	find_min_mid_max(&v);
	push_min_mid_groups_to_b(v);
	push_max_group_to_b(v);
	three_sort();
}

void	best_rotation_sort(void)
{
	push_groups_to_b();
	push_by_best_rotation();
	rotate_min_to_top_of_a();
}
