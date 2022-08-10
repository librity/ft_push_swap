/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/10 01:20:54 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	handle_first_two_pushes(int a_next_index)
{
	rotate_to_top_of_a(a_next_index);
	execute(PUSH_TO_B);
}

static void	push_chunk_to_b(int cycles, int chunk)
{
	int	chunk_start;
	int	chunk_end;
	int	a_next_index;
	int	b_next_index;

	chunk_start = cycles * (chunk - 1);
	chunk_end = chunk_start + cycles - 1;
	while (cycles > 0 && first_of_a() != NULL)
	{
		a_next_index = insertion_get_next_of_a_index(chunk_start, chunk_end);
		if (ft_dlst_index_out_of_bounds(a(), a_next_index))
			return ;
		if (b_size() < 2)
		{
			handle_first_two_pushes(a_next_index);
			cycles--;
			continue ;
		}
		b_next_index = insertion_get_next_of_b_index(a_next_index);
		rotate_to_top_of_stacks(a_next_index, b_next_index);
		execute(PUSH_TO_B);
		cycles--;
	}
}

static void	push_chunks_to_b(int chunk_size)
{
	int	chunks;

	chunks = (get_total_size() / chunk_size) + 1;
	while (chunks > 0)
	{
		push_chunk_to_b(chunk_size, chunks);
		chunks--;
	}
}

void	insertion_sort(int chunk_size)
{
	push_chunks_to_b(chunk_size);
	push_all_to_a_sorted();
}
