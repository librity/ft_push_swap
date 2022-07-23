/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/22 22:27:50 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	bubble_sort(t_dlist	*stack)
{
	t_dlist	*i;
	t_dlist	*j;
	int		auxiliary;

	i = stack;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (get_int(i) > get_int(j))
			{
				auxiliary = get_int(i);
				set_int(i, get_int(j));
				set_int(j, auxiliary);
			}
			j = j->next;
		}
		i = i->next;
	}
}
