/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_floatstr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 18:48:05 by hbally            #+#    #+#             */
/*   Updated: 2018/12/29 18:57:37 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 **	Rounds to nearest, ties go to the nearest value with an even
 **	least-significant digit
 */

static char		*add_digit(char *s, size_t len)
{
	int			i;
	char		*new;

	if ((new = ft_str_realloc(s, len + 1)))
	{
		ft_memmove(&(s[1]), s, len);
		s[0] = '1';
		i = 0;
		while (s[++i])
			if (s[i] != '.')
				s[i] = '0';
		return (new);
	}
	return (NULL);
}

static char		*final_pass(char *s, size_t len, int round_intpart)
{
	int			i;
	size_t		j;

	i = (int)len;
	while (--i > 0)
	{
		if (s[i] == ':' || (round_intpart && s[i - 1] == '.' &&
					((s[i] == '5' && s[i - 2] % 2 != 0) ||
					 (s[i] >= '6' && s[i] <= ':'))))
		{
			if (s[i - 1] != '.')
				s[i - 1] += 1;
			else
				s[i - 2] += 1;
			j = (size_t)i;
			while (j < len)
			{
				if (s[j] != '.')
					s[j] = '0';
			}
		}
	}
	if (s[0] == ':')
		s = add_digit(s, len);
	return (s);
}

char			*round_floatstr(char *s, size_t p)
{
	size_t		len;
	size_t		point_index;
	int			i;	
	size_t		j;

	len = ft_strlen(s);
	point_index = 0;
	while (s[point_index] && s[point_index] != '.')
		point_index++;
	i = (int)len;
	while (--i >= 0 && s[i] != '.' && (size_t)i > point_index + p)
	{
		if ((s[i] == '5' && s[i - 1] % 2 != 0) ||
				(s[i] >= '6' && s[i] <= ':'))
		{
			s[i - 1] += 1;
			j = (size_t)i;
			while (j < len && j <= point_index + p)
				s[j++] = '0';
		}
	}
	if ((s = final_pass(s, len, p <= 0)) && (point_index + p + 1 < len))
		s[point_index + p + 1] = '\0';
	return (s);
}
