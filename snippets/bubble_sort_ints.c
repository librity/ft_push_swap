/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort_ints.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:28:13 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/18 19:34:23 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc bubble_sort_ints.c && ./a.out

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define RAND_UP_TO 100

static void	bubble_sort_ints(int *int_array, int size)
{
	int	iterator;
	int	jterator;
	int	auxiliary;

	iterator = 0;
	while (iterator < size)
	{
		jterator = iterator + 1;
		while (jterator < size)
		{
			if (int_array[iterator] > int_array[jterator])
			{
				auxiliary = int_array[iterator];
				int_array[iterator] = int_array[jterator];
				int_array[jterator] = auxiliary;
			}
			jterator++;
		}
		iterator++;
	}
}

static void	put_int_array(int *int_array, int size)
{
	int	iterator;

	iterator = 0;
	while (iterator < size)
	{
		printf("%d ", int_array[iterator]);
		iterator++;
	}
	printf("\n");
}

static void	seed_int_array(int *int_array, int size)
{
	int	iterator;

	iterator = 0;
	while (iterator < SIZE)
	{
		int_array[iterator] = rand() % RAND_UP_TO;
		iterator++;
	}
}

int	main(void)
{
	int	ints[SIZE];
	int	iterator;

	srand(time(NULL));
	seed_int_array(ints, SIZE);

	printf("=== UNSORTED ===\n");
	put_int_array(ints, SIZE);

	bubble_sort_ints(ints, SIZE);
	printf("=== SORTED ===\n");
	put_int_array(ints, SIZE);
	return (0);
}
