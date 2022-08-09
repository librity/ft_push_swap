/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/27 18:54:01 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	log_state(void)
{
	if (verbose())
	{
		inspect_stacks();
		put_sort_status();
		ft_endl();
	}
}

void	log_normalized(void)
{
	if (verbose())
		ft_blueb_endl(NORMALIZE_MESSAGE);
	log_state();
}
