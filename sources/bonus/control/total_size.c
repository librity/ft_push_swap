/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:14:41 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/24 23:31:27 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	get_total_size(void)
{
	return (c()->total_size);
}

void	set_total_size(void)
{
	c()->total_size = ft_dlstsize(*a());
}
