/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 22:04:34 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/09 21:10:04 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push_all_to_a(void)
{
	while (first_of_b() != NULL)
		execute(PUSH_TO_A);
}

void	push_all_to_b(void)
{
	while (first_of_a() != NULL)
		execute(PUSH_TO_B);
}

void	push_all_to_a_sorted(void)
{
	int	max_index;

	while (first_of_b() != NULL)
	{
		max_index = find_max_index_in_b();
		rotate_to_top_of_b(max_index);
		execute(PUSH_TO_A);
	}
}
