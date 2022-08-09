/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_and_execute.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:47:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/09 17:31:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

void	receive_and_execute(void)
{
	int		status;
	char	*line;

	while (true)
	{
		status = ft_get_next_line(STDIN_FILENO, &line);
		if (status == GNL_ERROR)
			die();
		if (status == GNL_FOUND_EOF)
		{
			free(line);
			return ;
		}
		execute(line);
		free(line);
	}
}
