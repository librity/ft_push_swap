/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:52:19 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/09 21:04:42 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_dlist	*find_min_node_in_b(void)
{
	return (find_min_node(b()));
}

int	find_min_index_in_b(void)
{
	return (find_min_index(b()));
}

int	find_min_int_in_b(void)
{
	return (find_min_int(b()));
}

void	rotate_min_to_top_of_b(void)
{
	int	min_index;

	min_index = find_min_index_in_b();
	rotate_to_top_of_b(min_index);
}
