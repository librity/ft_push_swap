/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_top_of_stacks.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:50:40 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/09 23:11:33 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	handle_rr(int ra_moves, int rb_moves)
{
	int min;
	int rr_count;

	if (ra_moves == 0 || rb_moves == 0)
	{
		execute_n_times(ROTATE_A, ra_moves);
		execute_n_times(ROTATE_B, rb_moves);
		return ;
	}
	min = ft_min_i(ra_moves, rb_moves);
	if (min == ra_moves)
		rr_count = ra_moves;
	else
		rr_count = rb_moves;
	ra_moves -= rr_count;
	rb_moves -= rr_count;
	execute_n_times(ROTATE_A_AND_B, rr_count);
	execute_n_times(ROTATE_A, ra_moves);
	execute_n_times(ROTATE_B, rb_moves);
}

void	handle_rrr(int rra_moves, int rrb_moves)
{
	int min;
	int rrr_count;

	if (rra_moves == 0 || rrb_moves == 0)
	{
		execute_n_times(REVERSE_ROTATE_A, rra_moves);
		execute_n_times(REVERSE_ROTATE_B, rrb_moves);
		return ;
	}
	min = ft_min_i(rra_moves, rrb_moves);
	if (min == rra_moves)
		rrr_count = rra_moves;
	else
		rrr_count = rrb_moves;
	rra_moves -= rrr_count;
	rrb_moves -= rrr_count;
	execute_n_times(REVERSE_ROTATE_A_AND_B, rrr_count);
	execute_n_times(REVERSE_ROTATE_A, rra_moves);
	execute_n_times(REVERSE_ROTATE_B, rrb_moves);
}

void	rotate_to_top_of_stacks(int a_index, int b_index)
{
	int		ra_moves;
	int		rra_moves;
	bool 	ra_wins;

	int		rb_moves;
	int		rrb_moves;
	bool 	rb_wins;

	if (ft_dlst_index_out_of_bounds(a(), a_index))
		return ;
	if (ft_dlst_index_out_of_bounds(b(), b_index))
		return ;

	ra_moves = a_index;
	rra_moves = ft_dlstsize(*a()) - a_index;
	if (rra_moves >= ra_moves)
		ra_wins  = true;
	else
		ra_wins  = false;

	rb_moves = b_index;
	rrb_moves = ft_dlstsize(*b()) - b_index;
	if (rrb_moves >= rb_moves)
		rb_wins  = true;
	else
		rb_wins  = false;

	ft_bdebug(verbose(), "ra_moves = %d", ra_moves);
	ft_bdebug(verbose(), "rra_moves = %d", rra_moves);
	ft_bdebug(verbose(), "ra_wins = %d", ra_wins);

	ft_bdebug(verbose(), "rb_moves = %d", rb_moves);
	ft_bdebug(verbose(), "rrb_moves = %d", rrb_moves);
	ft_bdebug(verbose(), "rb_wins = %d", rb_wins);

	if (ra_wins && rb_wins)
	{
		handle_rr(ra_moves, rb_moves);
		return ;
	}

	if (!ra_wins && !rb_wins)
	{
		handle_rrr(rra_moves, rrb_moves);
		return ;
	}
	rotate_to_top_of_a(a_index);
	rotate_to_top_of_b(b_index);
}
