/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort_strs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 20:52:09 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/18 19:34:50 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_string(char *string)
{
	while (*string)
	{
		write(1, string, 1);
		string++;
	}
	write(1, "\n", 1);
}

void	swap_strings(char **first, char **second)
{
	char	*auxiliary;

	auxiliary = *first;
	*first = *second;
	*second = auxiliary;
}

int	my_strcmp(char *s1, char *s2)
{
	char	s1_current;
	char	s2_current;
	int		iterator;

	iterator = 0;
	s1_current = s1[0];
	s2_current = s2[0];
	while (s1_current != '\0' || s2_current != '\0')
	{
		if (s1_current < s2_current)
			return (-1);
		else if (s1_current > s2_current)
			return (1);
		iterator++;
		s1_current = s1[iterator];
		s2_current = s2[iterator];
	}
	return (0);
}

void	sort_arguments(int argument_count, char **arguments)
{
	char	**sorted_arguments;
	int		iterator;
	int		jterator;

	sorted_arguments = arguments;
	iterator = 0;
	while (iterator < argument_count)
	{
		jterator = iterator + 1;
		while (jterator < argument_count)
		{
			if (my_strcmp(sorted_arguments[iterator],
							sorted_arguments[jterator]) > 0)
				swap_strings(&sorted_arguments[iterator],
								&sorted_arguments[jterator]);
			jterator++;
		}
		iterator++;
	}
}

int	main(int argc, char **argv)
{
	int	current_argument;

	argv++;
	sort_arguments(argc - 1, argv);
	current_argument = 1;
	while (current_argument < argc)
	{
		put_string(*argv);
		current_argument++;
		argv++;
	}
	return (0);
}
