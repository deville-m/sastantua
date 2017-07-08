/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 09:51:42 by mdeville          #+#    #+#             */
/*   Updated: 2017/07/07 12:00:08 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int		is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\12');
}

int		is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int		test_char(char *c, int *begin, int *stop, int *is_negative)
{
	if ((is_whitespace(*c) || *c == '+') && *begin == 0)
	{
		return (0);
	}
	if (*c == '-' && *begin == 0 && is_digit(*(c + 1)))
	{
		*is_negative = 1;
		return (0);
	}
	if (!(is_digit(*c)))
	{
		*stop = 1;
		return (0);
	}
	if (is_digit(*c))
	{
		*begin = 1;
		return (*c - '0');
	}
	return (0);
}

int		ft_atoi(char *str)
{
	int i;
	int result;
	int begin_stop[2];
	int is_negative;
	int tmp;

	begin_stop[0] = 0;
	is_negative = 0;
	begin_stop[1] = 0;
	i = 0;
	result = 0;
	while (i < ft_strlen(str) && begin_stop[1] == 0)
	{
		tmp = test_char(str + i, begin_stop, begin_stop + 1, &is_negative);
		result = (begin_stop[1]) ? result : result * 10 + tmp;
		i++;
	}
	result = (is_negative) ? -result : result;
	return (result);
}
