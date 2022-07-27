/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_getters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 23:41:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/27 10:24:15 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_dlist	*first_of_a(void)
{
	return (*a());
}

t_dlist	*first_of_b(void)
{
	return (*b());
}

t_dlist	*a_get_node(int index)
{
	return (ft_dlst_get_safe(a(), index));
}

t_dlist	*b_get_node(int index)
{
	return (ft_dlst_get_safe(b(), index));
}
