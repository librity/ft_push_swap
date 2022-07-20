/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/19 22:20:17 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	validate_argc(void)
{
	if (argc() > 1)
		return ;
	die();
}

void	number_or_die(char *str)
{
	if (ft_is_plus_or_minus(*str))
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str != '\0')
		die();
}

int	int_or_die(char *str)
{
	long	number;

	number = ft_atol(str);
	if (number > INT_MAX)
		die();
	if (number < INT_MIN)
		die();
	return ((int)number);
}

void	add_to_a(void)
{
	t_dlist	*new;
	int		*integer;

	integer = ft_lalloc(free_me(), sizeof(int));
	*integer = c()->new_int;
	new = ft_dlstnew_safe(integer);
	if (*a() == NULL)
		*a() = new;
	else
		ft_dlstadd_back(a(), new);
	ft_add_lalloc(free_me(), new);
}

static void	check_unique(void *number)
{
	int		current;

	current = *(int *)number;
	if (current == c()->new_int)
		die();
}

void	unique_or_die(void)
{
	ft_dlstiter(*a(), &check_unique);
}

void	validate_argv(void)
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
