/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/11 14:05:32 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static bool	is_insertion_index(int a_index, int b_int, int a_last)
{
	int	a_int;

	a_int = get_a_int_by_index(a_index);
	if (a_int < b_int)
		return (false);
	if (a_index == 0)
		if (a_last > b_int)
			return (false);
	if (a_index > 0)
		if (get_a_int_by_index(a_index - 1) > b_int)
			return (false);
	return (true);
}

int	find_a_insertion_index(int b_int)
{
	int	a_index;
	int	a_last;

	a_index = 0;
	a_last = last_int_of_a();
	while (true)
	{
		if (is_insertion_index(a_index, b_int, a_last))
			break ;
		a_index++;
		continue ;
	}
	return (a_index);
}
