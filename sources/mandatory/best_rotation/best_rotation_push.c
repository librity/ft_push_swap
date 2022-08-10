/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_rotation_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/10 13:54:30 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_rotation	find_best_rotation(void)
{
	t_rotation	best;
	t_rotation	current;
	int			size;
	int			i;

	i = 0;
	size = b_size();
	best = get_rotation(get_b_int_by_index(i), i);
	while (i < size)
	{
		current = get_rotation(get_b_int_by_index(i), i);
		if (current.total < best.total)
			best = current;
		++i;
	}
	return (best);
}

static void	execute_rotation(t_rotation rotation)
{
	execute_n_times(ROTATE_A, rotation.ra);
	execute_n_times(ROTATE_B, rotation.rb);
	execute_n_times(ROTATE_A_AND_B, rotation.rr);
	execute_n_times(REVERSE_ROTATE_A, rotation.rra);
	execute_n_times(REVERSE_ROTATE_B, rotation.rrb);
	execute_n_times(REVERSE_ROTATE_A_AND_B, rotation.rrr);
}

void	push_by_best_rotation(void)
{
	t_rotation	best_rotation;

	while (b_size() > 0)
	{
		best_rotation = find_best_rotation();
		execute_rotation(best_rotation);
		execute(PUSH_TO_A);
	}
}
