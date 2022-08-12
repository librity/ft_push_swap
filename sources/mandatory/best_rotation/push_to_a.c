/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/11 18:21:32 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	execute_rotation(t_rotation rotation)
{
	execute_n_times(ROTATE_A, rotation.ra);
	execute_n_times(ROTATE_B, rotation.rb);
	execute_n_times(ROTATE_A_AND_B, rotation.rr);
	execute_n_times(REVERSE_ROTATE_A, rotation.rra);
	execute_n_times(REVERSE_ROTATE_B, rotation.rrb);
	execute_n_times(REVERSE_ROTATE_A_AND_B, rotation.rrr);
}

static t_rotation	find_best_rotation(void)
{
	t_rotation	best;
	t_rotation	current;
	t_dlist		*b_node;
	int			b_index;

	b_node = first_of_b();
	b_index = 0;
	best = get_rotation(get_int(b_node), b_index);
	while (b_node != NULL)
	{
		if (best.total <= GOOD_ENOUGH_ROTATION)
			return (best);
		current = get_rotation(get_int(b_node), b_index);
		if (current.total < best.total)
			best = current;
		b_index++;
		b_node = b_node->next;
	}
	return (best);
}

void	push_to_a_by_best_rotation(void)
{
	t_rotation	best_rotation;

	while (*b() != NULL)
	{
		best_rotation = find_best_rotation();
		execute_rotation(best_rotation);
		execute(PUSH_TO_A);
	}
}
