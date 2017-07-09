/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 00:54:03 by mdeville          #+#    #+#             */
/*   Updated: 2017/07/09 16:11:10 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		calculate_width(int stage)
{
	if (stage < 0)
	{
		return (0);
	}
	if (stage == 0)
	{
		return (7);
	}
	return (2 * (2 + (stage - 1) / 2) +
			calculate_width(stage - 1) +
			2 * (stage + 3));
}

char	what_to_print(int i, int j, int *height_width, int pad)
{
	if (j < height_width[0] - 1 - i + pad)
		return (' ');
	if (j == height_width[0] - 1 - i + pad)
		return ('/');
	if (j == height_width[1] - height_width[0] + i + pad)
		return ('\\');
	return ('*');
}

char	door(int stage, int *pos, int *height_width, int pad)
{
	int center;
	int size;

	center = height_width[1] / 2;
	size = (stage / 2);
	if ((pos[0] == 2 + (height_width[0] - 2) / 2 &&
		pos[1] == center + size - 1 && stage > 3))
		return ('$');
	if ((stage == 0 && pos[0] == 2 && pos[1] == 3 + pad) ||
		(stage == 1 && pos[0] == 3 && pos[1] == 9 + pad) ||
		(pos[1] >= center - size && pos[1] <= center + size &&
		pos[0] > 1 + stage % 2 && stage > 1))
		return ('|');
	return (what_to_print(pos[0], pos[1], height_width, pad));
}

void	print_stage(int stage, int size, int *height_width, int pad)
{
	int pos[2];

	pos[0] = 0;
	while (pos[0] < height_width[0])
	{
		pos[1] = 0;
		while (pos[1] < height_width[1] - height_width[0] + 1 + pos[0] + pad)
		{
			if (stage == size)
				ft_putchar(door(stage, pos, height_width, pad));
			else
				ft_putchar(what_to_print(pos[0], pos[1], height_width, pad));
			pos[1]++;
		}
		ft_putchar('\n');
		pos[0]++;
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
		print_stage(i, size - 1, dim,
					(calculate_width(size - 1) - calculate_width(i)) / 2);
		i++;
	}
}
