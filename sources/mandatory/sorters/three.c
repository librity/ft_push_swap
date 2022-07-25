/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:33:02 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/25 12:58:23 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	handle_biggest(void)
{
	t_dlist	*biggest;

	biggest = find_max_node_in_a();
	if (is_first_node(biggest))
		execute(ROTATE_A);
	else if (is_middle_node(biggest))
		execute(REVERSE_ROTATE_A);
}

void	three_sort(void)
{
	if (is_sorted())
		return ;
	handle_biggest();
	two_sort();
}
