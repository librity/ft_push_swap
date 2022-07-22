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

	int		new_int;

	t_dlist	*a;
	t_dlist	*b;

	t_list	*lalloc;
}		t_push_swap;

typedef void	(*t_operation_cb)(void);

/******************************************************************************\
 * CONTROL
\******************************************************************************/

t_push_swap	*c(void);
void		initialize_control(int argc, char **argv);

t_dlist		**a(void);
t_dlist		**b(void);
t_list		**lalloc(void);

int			argc(void);
char		**argv(void);

void		free_memory(void);

/******************************************************************************\
 * STACKS
\******************************************************************************/

void		handle_arguments(void);

void		validate_argc(void);

void		parse_argv(void);
void		number_or_die(char *str);
int			int_or_die(char *str);

bool		is_sorted(void);

/******************************************************************************\
 * STACKS
\******************************************************************************/

void		sa(void);
void		sb(void);
void		ss(void);

void		pa(void);
void		pb(void);

void		ra(void);
void		rb(void);
void		rr(void);

void		rra(void);
void		rrb(void);
void		rrr(void);

void		execute(char *operation);

void		inspect_stacks(void);
void		put_sort_status(void);

/******************************************************************************\
 * LOGGERS
\******************************************************************************/

void		log_state(void);

/******************************************************************************\
 * ERRORS
\******************************************************************************/

void		die(void);

#endif
