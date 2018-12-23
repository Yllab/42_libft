/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 18:20:34 by hbally            #+#    #+#             */
/*   Updated: 2018/12/22 19:09:16 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	get_right(double n) //assumes positive and <= LONG_MAX
{
	long long sub;

	sub = (long long)n;
	n -= (double)sub;
	return (n);
}

static double	get_left(double n, double fract_part)
{
	return (n - fract_part);
}

char			*dtoa(double n, int precision)
{
	char		*result;

}
