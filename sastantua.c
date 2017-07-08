/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 00:54:03 by mdeville          #+#    #+#             */
/*   Updated: 2017/07/09 00:50:56 by mdeville         ###   ########.fr       */
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

int		what_to_print(int i, int j, int height, int width)
{
	if (j < height - 1 - i)
		return (' ');
	if (j == height - 1 - i)
		return ('/');
	if (j == width - height + i)
		return ('\\');
	return ('*');
}

void	print_stage(int stage, int height, int width)
{
	int i;
	int j;
	int height;
	int width;

	height = 3 + stage;
	width = calculate_width(stage);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width - height + 1 + i)
		{
			ft_putchar(what_to_print(i, j, height, width));
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	sastantua(int size)
{
	int i;
	int j;
	int k;
	int dim[2];

	i = 0;
	while (i < size)
	{
		dim[0] = 3 + i;
		dim[1] = calculate_width(i);
		j = 0;
		while (j < dim[0])
		{
			k = 0;
			while (k < dim[1])
			{
				ft_putchar(' ');
			}
		}
		print_stage(i++, dim[0], dim[1]);
	}
}
