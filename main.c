/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:34:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/17 11:42:32 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	initialize(int argc, char **argv)
{
	initialize_control(argc, argv);
	handle_arguments();
	log_state();
	normalize_a();
}

static void	sort(void)
{
	if (is_sorted())
		return ;
	if (get_total_size() <= 5)
		return (five_sort());
	insertion_sort_v2();
}

static void	cleanup(void)
{
	free_memory();
}

int	main(int argc, char **argv)
{
	initialize(argc, argv);
	sort();
	cleanup();
	return (EXIT_SUCCESS);
}
