/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:14:25 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/23 17:15:11 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	normalize_stack(t_dlist *stack)
{
	t_dlist *i;
	t_dlist *j;
	int	count;

	i = stack;
	while (i != NULL)
	{
		j = stack;
		count = 1;
		while (j != NULL)
		{
			if (get_int(i) > get_int(j))
				count++;
			j = j->next;
		}
		set_int(i, count);
		i = i->next;
	}
}
