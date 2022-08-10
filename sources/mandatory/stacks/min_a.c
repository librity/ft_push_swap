/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:52:19 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/09 21:06:28 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_dlist	*find_min_node_in_a(void)
{
	return (find_min_node(a()));
}

int	find_min_index_in_a(void)
{
	return (find_min_index(a()));
}

int	find_min_int_in_a(void)
{
	return (find_min_int(a()));
}

void	rotate_min_to_top_of_a(void)
{
	int	min_index;

	min_index = find_min_index_in_a();
	rotate_to_top_of_a(min_index);
}
