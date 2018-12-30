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

/*
** This dtoa only supports doubles between LLONG_MIN and LLONG_MAX
** and doesnt support special values.
*/

static double	get_fract_part(double n)
{
	long long sub;

	if (n > (double)0x7FFFFFFFFFFFFFFFll)
		return (-1.0f);
	sub = (long long)n;
	n -= (double)sub;
	return (n);
}

static size_t	get_fract_len(double fract_part)
{
	size_t		i;
	int			digit;

	i = 1;
	while (fract_part > .0f)
	{
		fract_part *= 10;
		digit = (int)(fract_part);
		fract_part -= (double)digit;
		i++;
	}
	return (i);
}

static char		*fractoa(double fract_part, char *int_string)
{
	char		*fract_string;
	char		*concat_result;
	int			digit;
	size_t		len;
	size_t		i; 

	len = get_fract_len(fract_part);
	if (!(fract_string = ft_strnew(len)))
		return (NULL);
	fract_string[0] = '.';
	i = 1;
	while (i < len)
	{
		fract_part *= 10;
		digit = (int)(fract_part);
		fract_string[i] = '0' + digit;
		fract_part -= (double)digit;
	}
	concat_result = ft_strjoin(int_string, fract_string);
	free(int_string);
	free(fract_string);
	return (concat_result);
}

char			*ft_dtoa(double n)
{
	unsigned long long	int_part;
	double				fract_part;
	char				*result;

	if (n < 0)
		n *= -1;
	fract_part = get_fract_part(n);
	if (fract_part < .0f || n < .0f)
		return (NULL);
	int_part = (unsigned long long)(n - fract_part);
	if ((result = ft_ulltoa(int_part)))
	{
		if ((result = fractoa(fract_part, result)))
			return (result);
		else
			free(result);
	}
	return (NULL);
}
