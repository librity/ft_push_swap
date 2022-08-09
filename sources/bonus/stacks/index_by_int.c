/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_by_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 23:41:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/26 16:09:28 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	get_int_by_index(t_dlist **stack, int index)
{
	return (get_int(ft_dlst_get_safe(stack, index)));
}

int	get_a_int_by_index(int index)
{
	return (get_int_by_index(a(), index));
}

int	get_b_int_by_index(int index)
{
	return (get_int_by_index(b(), index));
}

int	first_int_of_a(void)
{
	return (get_int(*a()));
}

int	first_int_of_b(void)
{
	return (get_int(*b()));
}
