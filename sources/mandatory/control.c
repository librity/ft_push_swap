/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:14:41 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/19 15:58:56 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_push_swap	*c(void)
{
	static t_push_swap	__control_instance;

	return (&__control_instance);
}

t_list	*a(void)
{
	return (c()->a);
}

t_list	*b(void)
{
	return (c()->b);
}

void	free_memory(void)
{
	ft_free_lalloc(&(c()->free_me));
}
