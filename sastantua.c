/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 00:54:03 by mdeville          #+#    #+#             */
/*   Updated: 2017/07/08 22:36:08 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		calculate_width(int stage)
{
	if (stage < 1)
	{
		return (-1);
	}
	if (stage == 1)
	{
		return (7);
	}
	return (2 * (2 + (stage - 2) / 2) +
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
	i = 0;
	while (i++ < height)
	{
		j = 0;
		while (j++ < height - 1 - i)
			ft_putchar(' ');
		while (j++ < width)
			ft_putchar('*');
		ft_putchar('\n');
	}
}

void	sastantua(int size)
{
	int i;

	i = 1;
	while (i <= size)
	{
		print_stage(i);
		i++;
	}
}
