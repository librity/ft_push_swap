/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bubble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/27 00:53:02 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	free_bubble_sort(t_dlist **stack)
{
	t_dlist	*i;
	t_dlist	*j;

	i = *stack;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (get_int(i) > get_int(j))
				swap_ints(i, j);
			j = j->next;
		}
		i = i->next;
	}
}

void	free_bubble_sort_a(void)
{
	free_bubble_sort(a());
	log_state();
}
