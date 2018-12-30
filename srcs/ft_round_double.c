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

#include <stdio.h> //debug

static int		is_rounded(char *s, size_t i, int jump_point)
{
	if ((s[i] == '5' &&
			s[i - (1 + jump_point)] % 2 != 0) ||
				(s[i] >= '6' && s[i] <= ':'))
		return (1);
	return (0);
}

static char		*cut_precision(char *s, size_t p)
{
	size_t		len;

	len = 0;
	while (s[len] && s[len] != '.')
		len++;
	if (p > 0)
	{
		len++;
		if (p > 1000)
			p = 1000;
		while (p-- > 0)
			len++;
	}
	s = ft_str_realloc(s, len);
	while (len > 0)
	{
		if (s[len - 1] == '\0')
			s[len - 1] = '0';
		len--;
	}
	return (s);
}

static char		*add_digit(char *s, size_t len)
{
	int			i;
	char		*new;

	printf("adding digit\n");//debug
	if ((new = ft_str_realloc(s, len + 1)))
	{
		ft_memmove(&(new[1]), new, len);
		new[0] = '1';
		i = 0;
		while (new[++i])
			if (new[i] != '.')
				new[i] = '0';
		printf("result > \n%s\n", new);//debug
		return (new);
	}
	return (NULL);
}

static char		*final_rounding_pass(char *s, size_t len, int round_intpart)
{
	int			i;
	size_t		j;

	i = (int)len;
	while (--i > 0)
	{
		if (s[i] == ':' ||
				(round_intpart && s[i - 1] == '.' && is_rounded(s, i, 1)))
		{
			s[i - (1 + (s[i - 1] == '.'))] += 1;
			j = (size_t)i;
			while (j < len)
			{
				if (s[j] != '.')
					s[j] = '0';
				j++;
			}
		}
	}
	if (s[0] == ':')
		s = add_digit(s, len);
	return (s);
}

char			*ft_round_double(char *s, size_t p)
{
	size_t		len;
	size_t		point_pos;
	int			i;	
	size_t		j;

	len = ft_strlen(s);
	point_pos = 0;
	while (s[point_pos] && s[point_pos - 1] != '.')
		point_pos++;
	i = (int)len - 1;
	while (i >= 0 && s[i] != '.' && (size_t)i >= point_pos + p)
	{
		printf("%c\n", s[i]);
		if (is_rounded(s, i, 0))
		{
			s[i - 1] += 1;
			j = (size_t)i;
			while (j < len)
				s[j++] = '0';
		}
		i--;
		printf("%s\n", s);
	}
	if ((s = final_rounding_pass(s, len, p == 0)))
		s = cut_precision(s, p);
	return (s);
}
