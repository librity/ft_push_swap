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

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <defines_bonus.h>
# include <libft.h>

typedef struct s_push_swap
{
	bool		verbose;

	int			argc;
	char		**argv;

	int			new_int;

	t_dlist		*a;
	t_dlist		*b;

	t_dlist		*operations;

	t_list		*lalloc;
}				t_push_swap;

typedef void	(*t_operation_cb)(void);

/******************************************************************************\
 * CONTROL
\******************************************************************************/

t_push_swap		*c(void);
void			initialize_control(int argc, char **argv);

bool			verbose(void);
void			set_verbose(bool verbose);

int				argc(void);
char			**argv(void);

t_dlist			**a(void);
t_dlist			**b(void);

t_dlist			**operations(void);

t_list			**lalloc(void);
void			free_memory(void);

/******************************************************************************\
 * ARGUMENTS
\******************************************************************************/

void			handle_arguments(void);

void			validate_argc(void);

void			parse_argv(void);
void			number_or_die(char *str);
int				int_or_die(char *str);

/******************************************************************************\
 * STDIN
\******************************************************************************/

void			receive_and_execute(void);

/******************************************************************************\
 * OPERATIONS
\******************************************************************************/

void			sa(void);
void			sb(void);
void			ss(void);

void			pa(void);
void			pb(void);

void			ra(void);
void			rb(void);
void			rr(void);

void			rra(void);
void			rrb(void);
void			rrr(void);

void			execute(char *operation);
t_operation_cb	resolve_operation(char *operation);
t_operation_cb	resolve_operation_or_die(char *operation);

/******************************************************************************\
 * STACKS
\******************************************************************************/

void			inspect_stacks(void);
void			put_sort_status(void);

t_dlist			*clone_stack(t_dlist **original);

bool			is_sorted(void);

void			set_int(t_dlist *node, int number);
int				get_int(t_dlist *node);
int				get_next_int(t_dlist *node);

void			normalize_a(void);

/******************************************************************************\
 * LOGGERS
\******************************************************************************/

void			log_state(void);
void			log_normalized(void);

/******************************************************************************\
 * ERRORS
\******************************************************************************/

void			die(void);

#endif
