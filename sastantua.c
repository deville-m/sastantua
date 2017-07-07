/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 00:54:03 by mdeville          #+#    #+#             */
/*   Updated: 2017/07/08 01:46:58 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putchar.h"

int calculate_width(int stage)
{
	if (stage < 1)
	{
		return (-1);
	}
	if (stage == 1)
	{
		return (7);
	}
	return (2 * (3 + (stage - 2) / 2) + calculate_width(stage - 1));
}

void print_stage(int stage)
{
	int i;
	int j;
	int height;
	int width;

	i = 0;
	j = 0;
	height = 3 + stage;
	width = calculate_width(stage);
	while(i < 3 + stage)
	{
		while(j < calculate_width(stage)
		{
			ft_putchar('*');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void sastantua(int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		print_stage(i++);
	}
}
