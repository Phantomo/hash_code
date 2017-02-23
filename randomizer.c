/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 12:40:58 by dkovalen          #+#    #+#             */
/*   Updated: 2017/02/23 17:43:09 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int		check(int temp, int *arr, int len)
{
	int		i;

	i = 0;
	while (i < len)
		if (temp == arr[i++])
			return (0);
	return (1);
}

int		main(int argc, char const *argv[])
{
	int		from;
	int		to;
	int		many;
	int		*arr;
	int		i;
	int		temp;

	if (argc < 4)
		return (0);
	from = atoi(argv[1]);
	to = atoi(argv[2]);
	many = atoi(argv[3]);
	arr = (int *)malloc(sizeof(int) * many);
	i = 0;
	srand(time(NULL));
	while (i < many)
	{
		temp = rand() % to + from;
		while (check(temp, arr, i) == 0)
			temp = rand() % to + from;
		arr[i] = temp;
		i++;
	}
	i = 0;
	while (i < many)
	{
		if (i + 1 == many)
			printf("%d\n", arr[i++]);
		else
			printf("%d ", arr[i++]);
	}
	return (0);
}


 $ARG="'../usefull/rand 1 100 100'";