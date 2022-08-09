/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/09 19:47:20 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

static void	execute_operation(void *operation_vp)
{
	t_operation_cb	operation;

	operation = (t_operation_cb)operation_vp;
	operation();
}

void	execute_operations(void)
{
	ft_dlstiter(*operations(), &execute_operation);
}
