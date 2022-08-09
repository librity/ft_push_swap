/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:34:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/09 19:46:45 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

static void	initialize(int argc, char **argv)
{
	initialize_control(argc, argv);
	handle_arguments();
	log_state();
	normalize_a();
}

static void	sort(void)
{
	receive_operations();
	execute_operations();
	validate_sort();
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
