/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 18:20:34 by hbally            #+#    #+#             */
/*   Updated: 2018/12/29 18:56:05 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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

static char		*fractoa(double *fract_part, size_t p, char *int_string) // why fract part is a pointer ??
{
	char		*fract_string;
	char		*concat_result;
	int			digit;
	size_t		len;

	len = 1;
	if (!(fract_string = ft_strnew(p > 0 ? 1 : 0)))
		return (NULL);
	fract_string[0] = p > 0 ? '.' : '\0';
	while ((len < p + 1 && len < 1081) || *fract_part > 0.0)
	{
		if (!(ft_str_realloc(fract_string, ++len)))
			return (NULL);
		*fract_part *= 10;
		digit = (int)(*fract_part);
		fract_string[len - 1] = '0' + digit;
		*fract_part -= (double)digit;
	}
	concat_result = ft_strjoin(int_string, fract_string);
	free(int_string);
	free(fract_string);
	return (concat_result);
}

char			*dtoa(double n, size_t p)
{
	char				*result;
	unsigned long long	int_part;
	double				frac_part;
	int					neg;

	neg = 1;
	if (n < 0)
	{
		n *= -1;
		neg = -1;
	}
	frac_part = get_frac_part(n);
	if (frac_part < 0)
		return (NULL);
	int_part = (unsigned long long)(frac_part - (n - frac_part));
	if ((result = ft_ulltoa(int_part * neg)))
	{
		if ((result = fractoa(&frac_part, p, result)))
			return (round_floatstr(result, p));
		else
			free(result);
	}
	return (NULL);
}
