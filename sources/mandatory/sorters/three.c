/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:33:02 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/24 21:14:18 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	handle_biggest(void)
{
	t_dlist	*biggest;

	biggest = find_biggest_node_in_a();
	if (is_first_node(biggest))
		execute("ra");
	else if (is_middle_node(biggest))
		execute("rra");
}

void	three_sort(void)
{
	if (is_sorted())
		return ;
	handle_biggest();
	two_sort();
}
