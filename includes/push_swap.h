/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:30:54 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/25 10:32:28 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <defines.h>
# include <libft.h>

typedef struct s_push_swap
{
	int		argc;
	char	**argv;

	t_list	*a;
	t_list	*b;

	t_list	*free_me;
}		t_push_swap;

/******************************************************************************\
 * CONTROL
\******************************************************************************/

t_push_swap	*c(void);
void		initialize_control(int argc, char **argv);
t_list		*a(void);
t_list		*b(void);
void		free_memory(void);

/******************************************************************************\
 * ERRORS
\******************************************************************************/

void		validate_argc(void);
void		validate_argv(void);

void		die(void);

#endif
