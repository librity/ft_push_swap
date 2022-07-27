/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:52:19 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/27 14:50:09 by lpaulo-m         ###   ########.fr       */
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
