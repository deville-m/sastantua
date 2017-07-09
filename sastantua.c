/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 00:54:03 by mdeville          #+#    #+#             */
/*   Updated: 2017/07/09 13:46:55 by mdeville         ###   ########.fr       */
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

char	print_door(int stage, int *pos, int *height_width, int pad)
{
	int center;

	center = calculate_width(stage) / 2;
	if ((height_width[1] == 7 && pos[0] == 2 + pad && pos[1] == 3 + pad))
		return ('|');
	return (center);
}

char	what_to_print(int stage, int *pos, int *height_width, int pad)
{
	char c_door;

	c_door = print_door(stage, pos, height_width, pad);
	if (c_door == '$' || c_door == '|')
		return (c_door);
	if (pos[1] < height_width[0] - 1 - pos[0] + pad)
		return (' ');
	if (pos[1] == height_width[0] - 1 - pos[0] + pad)
		return ('/');
	if (pos[1] == height_width[1] - height_width[0] + pos[0] + pad)
		return ('\\');
	return ('*');
}

void	print_stage(int stage, int *height_width, int pad)
{
	int pos[2];

	pos[0] = 0;
	while (pos[0] < height_width[0])
	{
		pos[1] = 0;
		while (pos[1] < height_width[1] - height_width[0] + 1 + pos[0] + pad)
		{
			ft_putchar(what_to_print(stage, pos, height_width, pad));
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
		print_stage(i, dim,
					(calculate_width(size - 1) - calculate_width(i)) / 2);
		i++;
	}
}
