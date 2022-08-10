/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/10 13:52:03 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int		get_insert_index(int num)
{
	int		i;

	i = 0;
	while (get_a_int_by_index(i) < num
		|| (i > 0 && get_a_int_by_index(i -1) > num)
		|| (
			i == 0
			&& get_a_int_by_index(a_size() - 1) > num
		))
	{
		i++;
	}
	return (i);
}


static void	first_step(t_rotation *solve, int i, int insert_index)
{
	solve[UP].rb = i;
	solve[UP].ra = insert_index;
	if (solve[UP].rb > solve[UP].ra)
		solve[UP].rr = solve[UP].ra;
	else
		solve[UP].rr = solve[UP].rb;
	solve[UP].ra -= solve[UP].rr;
	solve[UP].rb -= solve[UP].rr;
	solve[UP].total = solve[UP].ra + solve[UP].rb + solve[UP].rr;
	solve[DOWN].rra = a_size() - insert_index;
	solve[DOWN].rrb = b_size() - i;
	if (solve[DOWN].rrb > solve[DOWN].rra)
		solve[DOWN].rrr = solve[DOWN].rra;
	else
		solve[DOWN].rrr = solve[DOWN].rrb;
	solve[DOWN].rra -= solve[DOWN].rrr;
	solve[DOWN].rrb -= solve[DOWN].rrr;
	solve[DOWN].total = solve[DOWN].rra + solve[DOWN].rrb +
		solve[DOWN].rrr;
}

static void	second_step(t_rotation *solve, int i, int insert_index)
{
	solve[UP_DOWN].ra = insert_index;
	solve[UP_DOWN].rrb = b_size() - i;
	solve[UP_DOWN].total = solve[UP_DOWN].ra + solve[UP_DOWN].rrb;
	solve[DOWN_UP].rra = a_size() - insert_index;
	solve[DOWN_UP].rb = i;
	solve[DOWN_UP].total = solve[DOWN_UP].rra + solve[DOWN_UP].rb;
}

t_rotation		get_rotation(int num, int i)
{
	t_rotation			rotations[4];
	t_direction			current_direction;
	t_direction			best_direction;
	int					least_rotations;
	int 				insert_index;

	ft_bzero(rotations, sizeof(t_rotation) * 4);
	insert_index = get_insert_index(num);
	first_step(rotations, i, insert_index);
	second_step(rotations, i, insert_index);
	current_direction = FIRST;
	least_rotations = rotations[FIRST].total;
	best_direction = current_direction;
	while (current_direction <= LAST)
	{
		if (rotations[current_direction].total < least_rotations)
		{
			best_direction = current_direction;
			least_rotations = rotations[current_direction].total;
		}
		current_direction++;
	}
	return (rotations[best_direction]);
}
