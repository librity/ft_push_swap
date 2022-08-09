/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:52:19 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/27 14:50:00 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_dlist	*find_max_node_in_b(void)
{
	return (find_max_node(b()));
}

int	find_max_index_in_b(void)
{
	return (find_max_index(b()));
}

int	find_max_int_in_b(void)
{
	return (find_max_int(b()));
}
