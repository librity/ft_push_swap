/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:17:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/20 18:12:42 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// static t_dlist	*resolve_stacks(char label)
// {
// 	if (label == A_STACK_LABEL)
// 		return (*a());
// 	if (label == B_STACK_LABEL)
// 		return (*b());
// 	die();
// }

// static void	p(char label)
// {
// 	t_dlist	*stack;
// 	int		*aux;

// 	stack = resolve_stack(label);
// 	if (stack == NULL)
// 		return ;
// 	if (stack->next == NULL)
// 		return ;
// 	aux = stack->content;
// 	stack->content = stack->next->content;
// 	stack->next->content = aux;
// }

void	pa(void)
{
	t_dlist	*pushed;

	if (*b() == NULL)
		return ;
	pushed = *b();
	*b() = pushed->next;
	if (*b() != NULL)
		(*b())->prev = NULL;
	ft_dlstadd_front(a(), pushed);
	ft_putendl_fd("pa", STDOUT_FILENO);
}

void	pb(void)
{
	t_dlist	*pushed;

	if (*a() == NULL)
		return ;
	pushed = *a();
	*a() = pushed->next;
	if (*a() != NULL)
		(*a())->prev = NULL;
	// ft_printf("DEGUB: \n");
	ft_dlstadd_front(b(), pushed);
	ft_putendl_fd("pb", STDOUT_FILENO);
}
