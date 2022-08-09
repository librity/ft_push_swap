/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:47:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/09 19:46:52 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

static t_operation_cb	resolve_operation(char *operation)
{
	if (ft_streq(operation, SWAP_A))
		return (sa);
	if (ft_streq(operation, SWAP_B))
		return (sb);
	if (ft_streq(operation, SWAP_A_AND_B))
		return (ss);
	if (ft_streq(operation, PUSH_TO_A))
		return (pa);
	if (ft_streq(operation, PUSH_TO_B))
		return (pb);
	if (ft_streq(operation, ROTATE_A))
		return (ra);
	if (ft_streq(operation, ROTATE_B))
		return (rb);
	if (ft_streq(operation, ROTATE_A_AND_B))
		return (rr);
	if (ft_streq(operation, REVERSE_ROTATE_A))
		return (rra);
	if (ft_streq(operation, REVERSE_ROTATE_B))
		return (rrb);
	if (ft_streq(operation, REVERSE_ROTATE_A_AND_B))
		return (rrr);
	return (NULL);
}

static void	add_operation(char *line)
{
	t_operation_cb	operation;

	operation = resolve_operation(line);
	if (operation == NULL)
	{
		free(line);
		die();
	}
	ft_dlst_cadd_back_lalloc(lalloc(), operations(), operation);
}

void	receive_operations(void)
{
	int		status;
	char	*line;

	while (true)
	{
		status = ft_get_next_line(STDIN_FILENO, &line);
		if (status == GNL_ERROR)
			die();
		if (status == GNL_FOUND_EOF)
			return (free(line));
		add_operation(line);
		free(line);
	}
}
