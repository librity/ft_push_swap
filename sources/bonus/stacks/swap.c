/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/27 00:51:30 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap_ints(t_dlist *i_node, t_dlist *j_node)
{
	int	aux;

	aux = get_int(i_node);
	set_int(i_node, get_int(j_node));
	set_int(j_node, aux);
}

void	swap_ints_by_index(t_dlist **stack, int i_index, int j_index)
{
	t_dlist	*i_node;
	t_dlist	*j_node;

	i_node = ft_dlst_get_safe(stack, i_index);
	j_node = ft_dlst_get_safe(stack, j_index);
	swap_ints(i_node, j_node);
}
