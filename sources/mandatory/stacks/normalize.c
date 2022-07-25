/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:14:25 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/24 23:37:01 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	normalize_stack(t_dlist **stack)
{
	t_dlist	*clone;
	t_dlist	*i;
	t_dlist	*j;
	int		count;

	clone = NULL;
	clone_stack(stack, &clone);
	i = *stack;
	while (i != NULL)
	{
		j = clone;
		count = NORMALIZE_MIN;
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

void	normalize_a(void)
{
	normalize_stack(a());
	if (verbose())
		ft_blueb_endl(NORMALIZE_MESSAGE);
	log_state();
}
