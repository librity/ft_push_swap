/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 21:11:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/25 12:58:31 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	two_sort(void)
{
	t_dlist	*first;
	t_dlist	*second;

	first = get_first_node_of_a();
	second = first->next;
	if (get_int(first) > get_int(second))
		execute(SWAP_A);
}
