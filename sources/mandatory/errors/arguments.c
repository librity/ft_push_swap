/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/19 17:25:24 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	validate_argc(void)
{
	if (c()->argc > 1)
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

void	unique_or_die(int number)
{
	ft_printf("DEGUB: %i\n", number);
}

void	validate_argv(void)
{
	char	**argv;
	int	current;

	argv = c()->argv + 1;
	while (*argv != NULL)
	{
		number_or_die(*argv);
		current = int_or_die(*argv);
		unique_or_die(current);
		argv++;
	}
}
