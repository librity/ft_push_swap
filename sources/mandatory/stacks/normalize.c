/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:14:25 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/27 18:53:25 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	normalize_ith_node(t_dlist *clone, t_dlist *i)
{
	t_dlist	*j;
	int		normalizer;

	j = clone;
	normalizer = NORMALIZE_MIN;
	while (j != NULL)
	{
		if (get_int(i) > get_int(j))
			normalizer++;
		j = j->next;
	}
	set_int(i, normalizer);
}

static void	normalize_stack(t_dlist **stack)
{
	t_dlist	*clone;
	t_dlist	*i;

	clone = clone_stack(stack);
	i = *stack;
	while (i != NULL)
	{
		normalize_ith_node(clone, i);
		i = i->next;
	}
	ft_dlst_free(&clone);
}

void	normalize_a(void)
{
	normalize_stack(a());
	log_normalized();
}
