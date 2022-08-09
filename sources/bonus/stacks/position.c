/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:33:02 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/25 14:58:13 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

bool	is_first_node(t_dlist *node)
{
	return (node->prev == NULL);
}

bool	is_middle_node(t_dlist *node)
{
	return (node->prev != NULL && node->next != NULL);
}

bool	is_last_node(t_dlist *node)
{
	return (node->next == NULL);
}
