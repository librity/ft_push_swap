/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_of_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/17 11:29:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static bool	within_chunk(t_dlist *node, int chunk_start, int chunk_end)
{
	if (get_int(node) < chunk_start)
		return (false);
	if (get_int(node) > chunk_end)
		return (false);
	return (true);
}

static int	find_hold_first_index(int chunk_start, int chunk_end)
{
	t_dlist	*node;
	int		hold_first_index;

	hold_first_index = 0;
	node = first_of_a();
	while (node != NULL)
	{
		if (within_chunk(node, chunk_start, chunk_end))
			break ;
		hold_first_index++;
		node = node->next;
	}
	return (hold_first_index);
}

static int	find_hold_last_index(int chunk_start, int chunk_end)
{
	t_dlist	*node;
	int		hold_last_index;

	hold_last_index = count_a() - 1;
	node = last_of_a();
	while (node != NULL)
	{
		if (within_chunk(node, chunk_start, chunk_end))
			break ;
		hold_last_index--;
		node = node->prev;
	}
	return (hold_last_index);
}

int	get_a_inserted_index(int chunk_start, int chunk_end)
{
	int	hold_first_index;
	int	hold_last_index;
	int	hold_first_moves;
	int	hold_last_moves;

	hold_first_index = find_hold_first_index(chunk_start, chunk_end);
	hold_last_index = find_hold_last_index(chunk_start, chunk_end);
	hold_first_moves = hold_first_index;
	hold_last_moves = count_a() - hold_last_index + 1;
	if (hold_last_moves >= hold_first_moves)
		return (hold_first_index);
	return (hold_last_index);
}
