/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 23:41:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/11 13:57:10 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_dlist	*last_of_a(void)
{
	return (ft_dlstlast(*a()));
}

int	last_int_of_a(void)
{
	return (get_int(last_of_a()));
}

t_dlist	*last_of_b(void)
{
	return (ft_dlstlast(*b()));
}

int	last_int_of_b(void)
{
	return (get_int(last_of_b()));
}
