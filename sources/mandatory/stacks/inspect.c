/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/19 21:19:17 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	put_int(void *number)
{
	ft_printf("%d ", *(int *)number);
}

static void	inspect_a(void)
{
	ft_printf("|A: ");
	ft_dlstiter(*a(), &put_int);
	ft_printf("|\n");
}

static void	inspect_b(void)
{
	ft_printf("|B: ");
	ft_dlstiter(*b(), &put_int);
	ft_printf("|\n");
}

void	inspect_stacks(void)
{
	inspect_a();
	inspect_b();
}
