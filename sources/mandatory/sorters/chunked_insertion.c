/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunked_insertion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/27 17:53:36 by lpaulo-m         ###   ########.fr       */
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
	ft_debug("hold_first = %d", get_int(node));
	ft_debug("hold_first_index = %d", hold_first_index);
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
	ft_debug("hold_last = %d", get_int(node));
	ft_debug("hold_last_index = %d", hold_last_index);
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
	if (first_int_of_a() < chunk_start || first_int_of_a() > chunk_end)
		ft_debug("BAD hold first/last rotations!");
}

static void	handle_max_push(void)
{
	int	min_index;

	min_index = find_max_index_in_b();
	rotate_to_top_of_b(min_index);
	execute(PUSH_TO_B);
}

static void	handle_min_push(void)
{
	int	max_index;

	max_index = find_max_index_in_b();
	rotate_to_top_of_b(max_index);
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
	node = clone;
	while (node != NULL)
	{
		intermediate = get_int(node);
		if (intermediate > a_top)
		{
			ft_dlst_free(&clone);
			return (intermediate);
		}
		node = node->next;
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
	ft_debug("intermediate = %d", intermediate);
	if (intermediate == -1)
		ft_debug("error finding intermediate");
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
	ft_debug("intermediate_index = %d", intermediate_index);
	if (intermediate_index == -1)
		ft_debug("error finding intermediate index");
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
	ft_debug("a_top = %d", a_top);
	ft_debug("min = %d", min);
	ft_debug("max = %d", max);
	if (a_top > max)
	{
		ft_debug("handle_max_push");
		return (handle_max_push());
	}
	if (a_top < min)
	{
		ft_debug("handle_min_push");
		return (handle_min_push());
	}
	ft_debug("handle_intermediate_push");
	handle_intermediate_push();
}

void	chunked_insertion_sort(void)
{
	int	chunk_start;
	int	chunk_end;
	int	cycles;

	chunk_start = NORMALIZE_MIN;
	chunk_end = 19;
	cycles = 20;
	while (cycles)
	{
		rotate_next_to_top(chunk_start, chunk_end);
		ft_debug("END A ROTATIONS");
		handle_best_push();
		ft_debug("========== cycle %d end ==========\n", cycles);
		cycles--;
	}
}
