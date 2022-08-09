/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ints.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 23:09:49 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/25 00:35:19 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	number_or_die(char *str)
{
	if (ft_strlen(str) > ARG_MAX_LENGTH)
		die();
	if (ft_is_plus_or_minus(*str))
		str++;
	if (!ft_isdigit(*str))
		die();
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
