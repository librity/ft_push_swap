/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunked_insertion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/27 20:00:03 by lpaulo-m         ###   ########.fr       */
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

static void	rotate_next_to_top(int chunk_start, int chunk_end)
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
		rotate_to_top_of_a(hold_first_index);
	else
		rotate_to_top_of_a(hold_last_index);
}

void	handle_max_push(void)
{
	int	max_index;

	max_index = find_max_index_in_b();
	rotate_to_top_of_b(max_index);
	execute(PUSH_TO_B);
}

void	handle_min_push(void)
{
	int	min_index;

	min_index = find_min_index_in_b();
	rotate_to_top_of_b(min_index);
	execute(PUSH_TO_B);
}

static int	find_intermediate(void)
{
	t_dlist	*clone;
	t_dlist	*node;
	int		a_top;
	int		intermediate;

	clone = clone_stack(b());
	free_quick_sort_stack(&clone);
	a_top = first_int_of_a();
	node = ft_dlstlast(clone);
	while (node != NULL)
	{
		intermediate = get_int(node);
		if (intermediate < a_top)
		{
			ft_dlst_free(&clone);
			return (intermediate);
		}
		node = node->prev;
	}
	ft_dlst_free(&clone);
	return (-1);
}

static int	find_intermediate_index(void)
{
	t_dlist	*node;
	int		intermediate;
	int		intermediate_index;

	intermediate = find_intermediate();
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

static void	handle_intermediate_push(void)
{
	int	intermediate_index;

	intermediate_index = find_intermediate_index();
	rotate_to_top_of_b(intermediate_index);
	execute(PUSH_TO_B);
}

static void	handle_best_push(void)
{
	int	a_top;
	int	min;
	int	max;

	if (b_size() < 2)
		return (execute(PUSH_TO_B));
	a_top = first_int_of_a();
	min = find_min_int_in_b();
	max = find_max_int_in_b();
	if (a_top > max)
		return (handle_max_push());
	if (a_top < min)
		return (handle_max_push());
	handle_intermediate_push();
}

void	chunked_insertion_sort(int chunk_size)
{
	int	chunks;
	int	chunk_start;
	int	chunk_end;
	int	cycles;
	int	max_index;

	chunks = (get_total_size() / chunk_size) + 1;
	while (chunks > 0)
	{
		chunk_start = chunk_size * (chunks - 1);
		chunk_end = chunk_start + chunk_size - 1;
		cycles = chunk_size;
		while (cycles > 0 && first_of_a() != NULL)
		{
			rotate_next_to_top(chunk_start, chunk_end);
			handle_best_push();
			cycles--;
		}
		chunks--;
	}
	while (first_of_b() != NULL)
	{
		max_index = find_max_index_in_b();
		rotate_to_top_of_b(max_index);
		execute(PUSH_TO_A);
	}
}
