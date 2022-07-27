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
	bool	verbose;

	int		argc;
	char	**argv;

	int		new_int;
	int		total_size;

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

bool		verbose(void);
void		set_verbose(bool verbose);

int			argc(void);
char		**argv(void);

int			get_total_size(void);
void		set_total_size(void);

t_dlist		**a(void);
t_dlist		**b(void);

t_list		**lalloc(void);
void		free_memory(void);

/******************************************************************************\
 * ARGUMENTS
\******************************************************************************/

void		handle_arguments(void);

void		validate_argc(void);

void		parse_argv(void);
void		number_or_die(char *str);
int			int_or_die(char *str);

/******************************************************************************\
 * OPERATIONS
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

void		push_all_to_a(void);
void		push_all_to_b(void);

/******************************************************************************\
 * STACKS
\******************************************************************************/

int			a_size(void);
int			b_size(void);

void		inspect_stacks(void);
void		put_sort_status(void);

t_dlist		*clone_stack_lalloc(t_dlist **original);
t_dlist		*clone_stack(t_dlist **original);

bool		is_sorted(void);

void		set_int(t_dlist *node, int number);

int			get_int(t_dlist *node);
int			get_next_int(t_dlist *node);
int			get_previous_int(t_dlist *node);

int			get_int_by_index(t_dlist **stack, int index);
int			get_a_int_by_index(int index);
int			get_b_int_by_index(int index);
int			first_int_of_a(void);
int			first_int_of_b(void);

t_dlist		*first_of_a(void);
t_dlist		*first_of_b(void);

void		normalize_a(void);

bool		is_first_node(t_dlist *node);
bool		is_middle_node(t_dlist *node);
bool		is_last_node(t_dlist *node);

int			find_max_int(t_dlist *node);
t_dlist		*find_max_node(t_dlist *node);
t_dlist		*find_max_node_in_a(void);

int			find_min_int(t_dlist *node);
t_dlist		*find_min_node(t_dlist *node);
int			find_min_index(t_dlist *node);

t_dlist		*find_min_node_in_a(void);
int			find_min_index_in_a(void);
int			find_min_int_in_a(void);

void		swap_ints(t_dlist *i_node, t_dlist *j_node);
void		swap_ints_by_index(t_dlist **stack, int i_index, int j_index);

/******************************************************************************\
 * SORTERS
\******************************************************************************/

void		random_sort(void);

void		two_sort(void);
void		three_sort(void);
void		five_sort(void);

void		free_bubble_sort(t_dlist **stack);
void		free_bubble_sort_a(void);
void		bubble_sort(void);

void		radix_sort(void);

void		free_quick_sort(t_dlist **stack, int start, int end);
void		free_quick_sort_a(void);
void		quick_sort(void);

/******************************************************************************\
 * LOGGERS
\******************************************************************************/

void		log_state(void);

/******************************************************************************\
 * ERRORS
\******************************************************************************/

void		die(void);

#endif
