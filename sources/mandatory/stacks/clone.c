/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 23:33:39 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/23 17:19:13 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	clone_stack(t_dlist **from, t_dlist **to)
{
	t_dlist *node;
	int		*number;

	node = *from;
	while (node != NULL)
	{
		number = ft_lalloc(lalloc(), sizeof(int));
		*number = get_int(node);
		ft_dlst_cadd_back_lalloc(lalloc(), to, number);
		node = node->next;
	}
}
