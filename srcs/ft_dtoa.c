/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 18:20:34 by hbally            #+#    #+#             */
/*   Updated: 2018/12/29 19:33:24 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"




#include <stdio.h> //DEBUG

static double	get_fract_part(double n)
{
	long long sub;

	if (n > (double)0x7FFFFFFFFFFFFFFFll)
		return (-1.0f);
	sub = (long long)n;
	n -= (double)sub;
	return (n);
}

static char		*fractoa(double fract_part, size_t p, char *int_string) // why fract part is a pointer ??
{
	char		*fract_string;
	char		*concat_result;
	int			digit;
	size_t		len;

	len = 0;
	if (!(fract_string = ft_strnew(p > 0 ? ++len : len)))
		return (NULL);
//	fract_string = (char*)ft_memalloc(200);//debug
	if (p > 0)
		fract_string[0] = '.';
	while ((len < p + 1 && len < 1081) || fract_part > .0f)
	{
		if (!(ft_str_realloc(fract_string, ++len)))
			return (NULL);
//		++len;//debug
		fract_part *= 10;
		digit = (int)(fract_part);
		fract_string[len - 1] = '0' + digit;
		printf("fract_string = %s\n", fract_string);
		fract_part -= (double)digit;
	}
	printf("done\n");
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

	if (n < 0)
		n *= -1;
	fract_part = get_fract_part(n);
	if (fract_part < .0f || n < .0f)
		return (NULL);
	int_part = (unsigned long long)(n - fract_part);
	printf("%f\n", fract_part);
	printf("%lld\n", int_part);
	if ((result = ft_ulltoa(int_part)))
	{
		if ((result = fractoa(fract_part, p, result)))
			return (round_floatstr(result, p));
		else
		{
			ft_putstr("ERROR\n");
			free(result);
		}
	}
	return (NULL);
}
