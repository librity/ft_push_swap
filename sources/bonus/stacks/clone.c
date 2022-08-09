/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 23:33:39 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/09 19:20:34 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

t_dlist	*clone_stack(t_dlist **original)
{
	t_dlist	*clone;
	t_dlist	*node;
	int		*number;

	clone = NULL;
	node = *original;
	while (node != NULL)
	{
		number = ft_salloc(sizeof(int));
		*number = get_int(node);
		ft_dlst_cadd_back(&clone, number);
		node = node->next;
	}
	return (clone);
}
