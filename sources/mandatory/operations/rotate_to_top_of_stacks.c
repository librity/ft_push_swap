/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_top_of_stacks.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:50:40 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/09 23:33:11 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	handle_rotations(t_rotate_to_top_of_stacks_vars v)
{
	int	min;
	int	rr_count;

	min = ft_min_i(v.ra_moves, v.rb_moves);
	if (min == v.ra_moves)
		rr_count = v.ra_moves;
	else
		rr_count = v.rb_moves;
	v.ra_moves -= rr_count;
	v.rb_moves -= rr_count;
	execute_n_times(ROTATE_A_AND_B, rr_count);
	execute_n_times(ROTATE_A, v.ra_moves);
	execute_n_times(ROTATE_B, v.rb_moves);
}

static void	handle_reverse_rotations(t_rotate_to_top_of_stacks_vars v)
{
	int	min;
	int	rrr_count;

	min = ft_min_i(v.rra_moves, v.rrb_moves);
	if (min == v.rra_moves)
		rrr_count = v.rra_moves;
	else
		rrr_count = v.rrb_moves;
	v.rra_moves -= rrr_count;
	v.rrb_moves -= rrr_count;
	execute_n_times(REVERSE_ROTATE_A_AND_B, rrr_count);
	execute_n_times(REVERSE_ROTATE_A, v.rra_moves);
	execute_n_times(REVERSE_ROTATE_B, v.rrb_moves);
}

static void	calculate_moves(t_rotate_to_top_of_stacks_vars *v)
{
	v->ra_moves = v->a_index;
	v->rra_moves = ft_dlstsize(*a()) - v->a_index;
	if (v->rra_moves >= v->ra_moves)
		v->ra_wins = true;
	else
		v->ra_wins = false;
	v->rb_moves = v->b_index;
	v->rrb_moves = ft_dlstsize(*b()) - v->b_index;
	if (v->rrb_moves >= v->rb_moves)
		v->rb_wins = true;
	else
		v->rb_wins = false;
}

static bool	indexes_within_bounds(int a_index, int b_index)
{
	if (ft_dlst_index_out_of_bounds(a(), a_index))
		return (false);
	if (ft_dlst_index_out_of_bounds(b(), b_index))
		return (false);
	return (true);
}

void	rotate_to_top_of_stacks(int a_index, int b_index)
{
	t_rotate_to_top_of_stacks_vars	v;

	v.a_index = a_index;
	v.b_index = b_index;
	if (!indexes_within_bounds(a_index, b_index))
		return ;
	calculate_moves(&v);
	if (v.ra_wins && v.rb_wins)
		return (handle_rotations(v));
	if (!v.ra_wins && !v.rb_wins)
		return (handle_reverse_rotations(v));
	rotate_to_top_of_a(a_index);
	rotate_to_top_of_b(b_index);
}
