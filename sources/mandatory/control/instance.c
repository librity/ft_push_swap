/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:14:41 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/19 20:54:24 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_push_swap	*c(void)
{
	static t_push_swap	__control_instance;

	return (&__control_instance);
}

void	initialize_control(int argc, char **argv)
{
	c()->argc = argc;
	c()->argv = argv;
}

t_dlist	**a(void)
{
	return (&(c()->a));
}

t_dlist	**b(void)
{
	return (&(c()->b));
}

t_list	**free_me(void)
{
	return (&(c()->free_me));
}
