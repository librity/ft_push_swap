/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/20 21:29:51 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	put_int(void *number)
{
	ft_printf("%s%d%s ", G, *(int *)number, RC);
}

static void	inspect_a(void)
{
	ft_cyan("|A: (top) ");
	ft_dlstiter(*a(), &put_int);
	ft_red("(bottom)|\n");
}

static void	inspect_b(void)
{
	ft_cyan("|B: (top) ");
	ft_dlstiter(*b(), &put_int);
	ft_red("(bottom)|\n\n");
}

void	inspect_stacks(void)
{
	inspect_a();
	inspect_b();
}

void	log_stacks(void)
{
	if (VERBOSE)
		inspect_stacks();
}
