/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:34:20 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/19 23:04:42 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	validate_arguments(void)
{
	validate_argc();
	validate_argv();
}

int	main(int argc, char **argv)
{
	initialize_control(argc, argv);
	validate_arguments();
	inspect_stacks();
	sa();
	inspect_stacks();
	sb();
	inspect_stacks();
	ss();
	inspect_stacks();
	ss();
	inspect_stacks();
	return (EXIT_SUCCESS);
}
