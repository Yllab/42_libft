/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 11:38:52 by hbally            #+#    #+#             */
/*   Updated: 2018/12/31 11:39:11 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"

/*
** Length is represented as a bit code
** ...00001 > hh (1)
** ...00010 > h (2)
** ...00100 > ll (4)
** ...01000 > l (8)
** ...10000 > L (10)
*/

static int		dispatcher_integer(char c,
									va_list *args,
									t_index *params,
									char **s)
{
	if (c == 'f')
	{
		if (params->length & 0x10)
			return (baker_longdouble(va_arg(*args, long double), params, s));
		return (baker_double(va_arg(*args, double), params, s));
	}
	return (1);
}

static int		dispatcher_integer(char c,
									va_list *args,
									t_index *params,
									char **s)
{
	if (c == 'p')
		return (baker_pointer(va_arg(*args, void*), params, s));
	if (c == 'd' || c == 'i' || c == 'o' || c == 'x' || c == 'X' || c == 'u')
	{
		if (params->length & 0x4)
			return (baker_longlong(va_arg(*args, long long), params, s));
		if (params->length & 0x8)
			return (baker_long(va_arg(*args, long), params, s));
		return (baker_int(va_arg(*args, int), params, s));
	}
	return (1);
}

static int		dispatcher_str(char c,
								va_list *args,
								t_index *params,
								char **s)
{
	if (c == '%')
	{	
		params->type = 'c';
		return (baker_char('%', params, s));
	}
	if (c == 'c')
		return (baker_char(va_arg(*args, int), params, s));
	if (c == 's')
		return (baker_string(va_arg(*args, char*), params, s));
	return (1);
}

int				dispatcher(char c, va_list *args, t_index *params, char **s)
{
	params->type = c;
	if (dispatcher_str(c, args, params, s))
		return (1);
	else if (dispatcher_integer(c, args, params, s))
		return (1);
	else if (dispatcher_double(c, args, params, s))
		return (1);
	params->type = '\0';
	return (0);
}
