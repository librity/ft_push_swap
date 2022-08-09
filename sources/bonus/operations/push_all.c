/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 22:04:34 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/27 15:54:02 by lpaulo-m         ###   ########.fr       */
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
