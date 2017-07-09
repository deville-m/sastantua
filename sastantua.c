/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 00:54:03 by mdeville          #+#    #+#             */
/*   Updated: 2017/07/09 02:14:33 by mdeville         ###   ########.fr       */
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

int		what_to_print(int i, int j, int *height_width)
{
	if (j < height_width[0] - 1 - i)
		return (' ');
	if (j == height_width[0] - 1 - i)
		return ('/');
	if (j == height_width[1] - height_width[0] + i)
		return ('\\');
	return ('*');
}

void	print_stage(int *height_width)
{
	int i;
	int j;

	i = 0;
	while (i < height_width[0])
	{
		j = 0;
		while (j < height_width[1] - height_width[0] + 1 + i)
		{
			ft_putchar(what_to_print(i, j, height_width));
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	sastantua(int size)
{
	int i;
	int dim[2];

	i = 0;
	while (i < size)
	{
		dim[0] = 3 + i;
		dim[1] = calculate_width(i);
		print_stage(dim);
		i++;
	}
}
