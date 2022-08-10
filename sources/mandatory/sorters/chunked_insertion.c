/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunked_insertion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/09 22:04:02 by lpaulo-m         ###   ########.fr       */
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

	hold_last_index = a_size() - 1;
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

static int	get_a_next_index(int chunk_start, int chunk_end)
{
	int	hold_first_index;
	int	hold_last_index;
	int	hold_first_moves;
	int	hold_last_moves;

	hold_first_index = find_hold_first_index(chunk_start, chunk_end);
	hold_last_index = find_hold_last_index(chunk_start, chunk_end);
	hold_first_moves = hold_first_index;
	hold_last_moves = a_size() - hold_last_index + 1;
	if (hold_last_moves >= hold_first_moves)
		return (hold_first_index);
	return (hold_last_index);
}

static int	find_intermediate(int a_next)
{
	t_dlist	*clone;
	t_dlist	*node;
	int		intermediate;

	clone = clone_stack(b());
	free_quick_sort_stack(&clone);
	node = ft_dlstlast(clone);
	while (node != NULL)
	{
		intermediate = get_int(node);
		if (intermediate < a_next)
		{
			ft_dlst_free(&clone);
			return (intermediate);
		}
		node = node->prev;
	}
	ft_dlst_free(&clone);
	return (-1);
}

static int	find_intermediate_index(int a_next)
{
	t_dlist	*node;
	int		intermediate;
	int		intermediate_index;

	intermediate = find_intermediate(a_next);
	node = first_of_b();
	intermediate_index = 0;
	while (node != NULL)
	{
		if (get_int(node) == intermediate)
			return (intermediate_index);
		intermediate_index++;
		node = node->next;
	}
	return (-1);
}

static int	get_b_index(int a_next)
{
	int	min;
	int	max;

	min = find_min_int_in_b();
	max = find_max_int_in_b();
	if (a_next > max)
		return (find_max_index_in_b());
	if (a_next < min)
		return (find_max_index_in_b());
	return (find_intermediate_index(a_next));
}

static void	push_chunk_to_b(int cycles, int chunk)
{
	int	chunk_start;
	int	chunk_end;
	int	a_next;
	int	a_next_index;
	int	b_next_index;

	chunk_start = cycles * (chunk - 1);
	chunk_end = chunk_start + cycles - 1;
	while (cycles > 0 && first_of_a() != NULL)
	{
		a_next_index = get_a_next_index(chunk_start, chunk_end);
		if (ft_dlst_index_out_of_bounds(a(), a_next_index))
			return ;
		if (b_size() < 2)
		{
			rotate_to_top_of_a(a_next_index);
			execute(PUSH_TO_B);
			cycles--;
			continue ;
		}
		a_next = get_a_int_by_index(a_next_index);
		b_next_index = get_b_index(a_next);

		rotate_to_top_of_a(a_next_index);
		rotate_to_top_of_b(b_next_index);
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

void	chunked_insertion_sort(int chunk_size)
{
	push_chunks_to_b(chunk_size);
	push_all_to_a_sorted();
}
