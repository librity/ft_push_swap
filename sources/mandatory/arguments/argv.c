/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/24 17:18:24 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	check_unique(void *number)
{
	int		current;

	current = *(int *)number;
	if (current == c()->new_int)
		die();
}

static void	unique_or_die(void)
{
	ft_dlstiter(*a(), &check_unique);
}

static void	add_to_a(void)
{
	int		*integer_p;

	integer_p = ft_lalloc(lalloc(), sizeof(int));
	*integer_p = c()->new_int;
	ft_dlst_cadd_back_lalloc(lalloc(), a(), integer_p);
}

void	parse_argv(void)
{
	char	**args;

	args = argv() + 1;
	while (*args != NULL)
	{
		number_or_die(*args);
		c()->new_int = int_or_die(*args);
		unique_or_die();
		add_to_a();
		args++;
	}
}
