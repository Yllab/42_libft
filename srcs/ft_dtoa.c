/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 18:20:34 by hbally            #+#    #+#             */
/*   Updated: 2018/12/29 19:05:50 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"




#include <stdio.h> //DEBUG

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

char			*ft_dtoa(double n, size_t p)
{
	char				*result;
	unsigned long long	int_part;
	double				fract_part;
	int					neg;

	neg = 1;
	if (n < 0)
	{
		n *= -1;
		neg = -1;
	}
	fract_part = get_fract_part(n);
	if (fract_part < 0)
		return (NULL);
	int_part = (unsigned long long)(fract_part - (n - fract_part));
	printf("%f\n", fract_part);
	printf("%lld\n", int_part);
	exit(0);
	if ((result = ft_ulltoa(int_part * neg)))
	{
		if ((result = fractoa(&fract_part, p, result)))
			return (round_floatstr(result, p));
		else
			free(result);
	}
	return (NULL);
}
