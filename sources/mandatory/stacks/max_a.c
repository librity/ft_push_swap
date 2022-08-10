/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:52:19 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/09 21:05:37 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_dlist	*find_max_node_in_a(void)
{
	return (find_max_node(a()));
}

int	find_max_index_in_a(void)
{
	return (find_max_index(a()));
}

int	find_max_int_in_a(void)
{
	return (find_max_int(a()));
}

void	rotate_max_to_top_of_a(void)
{
	int	max_index;

	max_index = find_max_index_in_a();
	rotate_to_top_of_a(max_index);
}
