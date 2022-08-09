/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/25 20:36:01 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static char	*random_command(void)
{
	int			random_index;
	const char	*commands[11] = {
		SWAP_A,
		SWAP_B,
		SWAP_A_AND_B,
		PUSH_TO_A,
		PUSH_TO_B,
		ROTATE_A,
		ROTATE_B,
		ROTATE_A_AND_B,
		REVERSE_ROTATE_A,
		REVERSE_ROTATE_B,
		REVERSE_ROTATE_A_AND_B};

	random_index = ft_prand() % 11;
	return ((char *)commands[random_index]);
}

void	random_sort(void)
{
	while (!is_sorted())
		execute(random_command());
}
