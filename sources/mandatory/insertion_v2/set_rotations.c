/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rotations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/11 16:17:11 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	set_total(t_rotation *r)
{
	r->total = r->ra + r->rb + r->rr + r->rra + r->rrb + r->rrr;
}

void	set_up_up_rotation(t_rotation *r, int b_index, int a_index)
{
	r[UP_UP].rb = b_index;
	r[UP_UP].ra = a_index;
	if (r[UP_UP].rb > r[UP_UP].ra)
		r[UP_UP].rr = r[UP_UP].ra;
	else
		r[UP_UP].rr = r[UP_UP].rb;
	r[UP_UP].ra -= r[UP_UP].rr;
	r[UP_UP].rb -= r[UP_UP].rr;
	set_total(&r[UP_UP]);
}

void	set_down_down_rotation(t_rotation *r, int b_index, int a_index)
{
	r[DOWN_DOWN].rra = count_a() - a_index;
	r[DOWN_DOWN].rrb = count_b() - b_index;
	if (r[DOWN_DOWN].rrb > r[DOWN_DOWN].rra)
		r[DOWN_DOWN].rrr = r[DOWN_DOWN].rra;
	else
		r[DOWN_DOWN].rrr = r[DOWN_DOWN].rrb;
	r[DOWN_DOWN].rra -= r[DOWN_DOWN].rrr;
	r[DOWN_DOWN].rrb -= r[DOWN_DOWN].rrr;
	set_total(&r[DOWN_DOWN]);
}

void	set_up_down_rotation(t_rotation *r, int b_index, int a_index)
{
	r[UP_DOWN].ra = a_index;
	r[UP_DOWN].rrb = count_b() - b_index;
	set_total(&r[UP_DOWN]);
}

void	set_down_up_rotation(t_rotation *r, int b_index, int a_index)
{
	r[DOWN_UP].rra = count_a() - a_index;
	r[DOWN_UP].rb = b_index;
	set_total(&r[DOWN_UP]);
}
