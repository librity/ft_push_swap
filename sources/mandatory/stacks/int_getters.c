/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_getters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 23:41:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/25 19:11:27 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	get_int(t_dlist *node)
{
	return (*(int *)(node->content));
}

int	get_next_int(t_dlist *node)
{
	return (*(int *)(node->next->content));
}

int	get_previous_int(t_dlist *node)
{
	return (*(int *)(node->prev->content));
}

int	first_int_of_a(void)
{
	return (get_int(*a()));
}
