/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/09 19:19:12 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

static void	put_int(void *number)
{
	ft_printf("%s%d%s ", GB, *(int *)number, RC);
}

static void	inspect_a(void)
{
	ft_cyan("|A: (top) ");
	ft_dlstiter(*a(), &put_int);
	ft_purple("(bottom)|\n");
}

static void	inspect_b(void)
{
	ft_cyan("|B: (top) ");
	ft_dlstiter(*b(), &put_int);
	ft_purple("(bottom)|\n");
}

void	inspect_stacks(void)
{
	inspect_a();
	inspect_b();
}

void	put_sort_status(void)
{
	ft_yellow("Is sorted: ");
	if (is_sorted())
		ft_greenb_endl("YES");
	else
		ft_redb_endl("NO");
}
