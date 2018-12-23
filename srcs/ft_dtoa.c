/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 18:20:34 by hbally            #+#    #+#             */
/*   Updated: 2018/12/23 16:42:32 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	get_frac_part(double n)
{
	long long sub;

	if (n > (double)0x7FFFFFFFFFFFFFFFll)
		return (-1.0);
	sub = (long long)n;
	n -= (double)sub;
	return (n);
}

static char		*fractoa(double n, int precision, char *int_string)
{
	char		*fract_string;
	char		*concat_result;
	int			digit;
	int			len;

	len = 1;
	if (!(fract_string = ft_strnew(precision > 0 ? 1 : 0)))
		return (NULL);
	fract_string[0] = precision > 0 ? '.' : '\0';
	while (n != 0 && len < precision + 1 && len < 1080)
	{
		if (!(ft_str_realloc(fract_string, ++len)))
			return (NULL);
		n *= 10;
		digit = (int)n;
		fract_string[len - 1] = '0' + digit;
		n -= (double)digit;
	}
	concat_result = ft_strjoin(int_string, fract_string);
	free(int_string);
	free(fract_string);
	return (concat_result);
}

/*
**	Rounds to nearest, ties go to the nearest value with and even
**	least-significant digit
*/

static char		*round(char *s, int precision)
{
	int			len;
	
	if (precision > 0)
	{
		len = ft_strlen(s);
	}
}

char			*dtoa(double n, int precision)
{
	char		*result;
	long		int_part;
	double		frac_part;
	int			neg;

	neg = 1;
	if (n < 0)
	{
		n *= -1;
		neg = -1;
	}
	frac_part = get_frac_part(double n);
	if (frac_part < 0)
		return (NULL);
	int_part = (long)(frac_part - (n - frac_part));
	if ((result = ft_ltoa(int_part * neg)))
	{
		if ((result = fractoa(frac_part, precision, result)))
			return (round(result, precision));
		else
			free(result);
	}
	return (NULL);
}
