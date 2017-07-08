/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 22:46:58 by mdeville          #+#    #+#             */
/*   Updated: 2017/07/08 21:51:03 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	sastantua(int size);
int		ft_atoi(const char *str);

int		main(int argc, const char *argv[])
{
	int param;

	if (argc < 2 || argc > 2)
	{
		return (0);
	}
	param = ft_atoi(argv[1]);
	if (param <= 0)
	{
		return (0);
	}
	sastantua(param);
	return (0);
}
