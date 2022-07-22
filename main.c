/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:34:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/22 14:29:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	initialize(int argc, char **argv)
{
	initialize_control(argc, argv);
	handle_arguments();
	log_state();
}

// static void	sort(void)
// {
// 	execute("sa");
// 	execute("pb");
// 	execute("pb");
// 	execute("pb");
// 	// execute("pb");
// 	// execute("pb");
// 	// execute("pb");
// 	execute("ra");
// 	execute("rb");
// 	execute("rr");
// 	execute("rr");
// 	execute("rr");
// 	execute("rr");
// 	execute("rr");
// 	execute("rr");
// 	execute("rr");
// 	execute("rr");
// 	execute("rr");
// 	execute("rr");
// 	execute("rr");
// 	execute("rr");
// }
static void	sort(void)
{
	execute("sa");
	execute("pb");
	execute("pb");
	execute("pb");
	execute("sa");
	execute("pa");
	execute("pa");
	execute("pa");
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
