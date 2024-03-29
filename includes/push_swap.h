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
	bool		verbose;

	int			argc;
	char		**argv;

	int			new_int;
	int			total_size;

	t_dlist		*a;
	t_dlist		*b;

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

int				total_size(void);
int				get_total_size(void);
void			set_total_size(void);

t_dlist			**a(void);
t_dlist			**b(void);

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
void			execute_n_times(char *operation, int n);

void			push_all_to_a(void);
void			push_all_to_b(void);
void			push_all_to_a_sorted(void);

void			rotate_to_top(char label, int index);
void			rotate_to_top_of_a(int index);
void			rotate_to_top_of_b(int index);

typedef struct s_rotate_to_top_of_stacks_vars
{
	int			a_index;
	int			ra_moves;
	int			rra_moves;
	bool		ra_wins;

	int			b_index;
	int			rb_moves;
	int			rrb_moves;
	bool		rb_wins;
}				t_rotate_to_top_of_stacks_vars;
void			rotate_to_top_of_stacks(int a_index, int b_index);

/******************************************************************************\
 * STACKS
\******************************************************************************/

int				count_a(void);
int				count_b(void);

void			inspect_stacks(void);
void			put_sort_status(void);

t_dlist			*clone_stack_lalloc(t_dlist **original);
t_dlist			*clone_stack(t_dlist **original);

bool			is_sorted(void);

int				get_int(t_dlist *node);
int				get_next_int(t_dlist *node);
int				get_previous_int(t_dlist *node);
void			set_int(t_dlist *node, int number);

int				get_int_by_index(t_dlist **stack, int index);
int				get_a_int_by_index(int index);
int				get_b_int_by_index(int index);
int				first_int_of_a(void);
int				first_int_of_b(void);

int				get_index_by_int(t_dlist **stack, int needle);
int				get_a_index_by_int(int needle);
int				get_b_index_by_int(int needle);

t_dlist			*a_get_node(int index);
t_dlist			*b_get_node(int index);

t_dlist			*first_of_a(void);
t_dlist			*first_of_b(void);

t_dlist			*last_of_a(void);
int				last_int_of_a(void);
t_dlist			*last_of_b(void);
int				last_int_of_b(void);

void			normalize_a(void);

bool			is_first_node(t_dlist *node);
bool			is_middle_node(t_dlist *node);
bool			is_last_node(t_dlist *node);

int				find_max_int(t_dlist **stack);
t_dlist			*find_max_node(t_dlist **stack);
int				find_max_index(t_dlist **stack);

t_dlist			*find_max_node_in_a(void);
int				find_max_index_in_a(void);
int				find_max_int_in_a(void);
void			rotate_max_to_top_of_a(void);

t_dlist			*find_max_node_in_b(void);
int				find_max_index_in_b(void);
int				find_max_int_in_b(void);
void			rotate_max_to_top_of_b(void);

int				find_min_int(t_dlist **stack);
t_dlist			*find_min_node(t_dlist **stack);
int				find_min_index(t_dlist **stack);

t_dlist			*find_min_node_in_a(void);
int				find_min_index_in_a(void);
int				find_min_int_in_a(void);
void			rotate_min_to_top_of_a(void);

t_dlist			*find_min_node_in_b(void);
int				find_min_index_in_b(void);
int				find_min_int_in_b(void);
void			rotate_min_to_top_of_b(void);

void			swap_ints(t_dlist *i_node, t_dlist *j_node);
void			swap_ints_by_index(t_dlist **stack, int i_index, int j_index);

/******************************************************************************\
 * SORTERS
\******************************************************************************/

void			random_sort(void);

void			free_bubble_sort(t_dlist **stack);
void			free_bubble_sort_a(void);
void			bubble_sort(void);

void			free_quick_sort(t_dlist **stack, int start, int end);
void			free_quick_sort_stack(t_dlist **stack);
void			free_quick_sort_a(void);
void			quick_sort(t_dlist **stack, int start, int end);
void			quick_sort_a(void);

void			two_sort(void);
void			three_sort(void);
void			five_sort(void);

void			radix_sort(void);

/******************************************************************************\
 * INSERTION SORT V1
\******************************************************************************/

void			insertion_sort_v1(int chunk_size);
int				get_a_inserted_index(int chunk_start, int chunk_end);
int				get_b_insertion_index(int a_next_index);

/******************************************************************************\
 * INSERTION SORT V2
\******************************************************************************/

typedef struct s_groups
{
	int			min;
	int			mid_start;
	int			mid;
	int			mid_end;
	int			max;
}				t_groups;
void			insertion_sort_v2(void);

void			push_min_mid_groups_to_b(t_groups v);
void			push_max_group_to_b(t_groups v);

typedef struct s_rotation
{
	int			ra;
	int			rb;
	int			rr;

	int			rra;
	int			rrb;
	int			rrr;

	int			total;
}				t_rotation;
void			insert_in_a_by_best_rotation(void);

typedef enum e_direction
{
	UP_UP = 0,
	DOWN_DOWN = 1,
	UP_DOWN = 2,
	DOWN_UP = 3,
	FIRST = UP_UP,
	SECOND = DOWN_DOWN,
	LAST = DOWN_UP
}				t_direction;
t_rotation		get_rotation(int b_int, int b_index);
void			set_up_up_rotation(t_rotation *r, int b_index, int a_index);
void			set_down_down_rotation(t_rotation *r, int b_index, int a_index);
void			set_up_down_rotation(t_rotation *r, int b_index, int a_index);
void			set_down_up_rotation(t_rotation *r, int b_index, int a_index);
int				find_a_insertion_index(int b_int);

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
