/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 00:54:03 by mdeville          #+#    #+#             */
/*   Updated: 2017/07/08 23:10:25 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putchar(char c);

int		calculate_width(int stage)
{
	if (stage < 0)
	{
		return (-1);
	}
	if (stage == 0)
	{
		return (7);
	}
	return (2 * (2 + (stage - 1) / 2) +
			calculate_width(stage - 1) +
			2 * (stage + 3));
}

void	print_stage(int stage)
{
	int i;
	int j;
	int height;
	int width;

	height = 3 + stage;
	width = calculate_width(stage);
	printf("largueur : %d\n", width);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < height - 1 - i)
		{
			ft_putchar(' ');
			j++;
		}
		while (j < width)
		{
			ft_putchar('*');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	sastantua(int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("etage : %d\n", i);
		print_stage(i++);
	}
}
