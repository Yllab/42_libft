/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:13:13 by hbally            #+#    #+#             */
/*   Updated: 2019/01/17 14:12:46 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

int				ft_asprintf(char **ret, const char *format, ...)
{
	va_list		args;
	t_index		params;

	ft_bzero(&params, sizeof(t_index));
	params.asprintf = 1;
	if (!ret)
		return (0);
	*ret = NULL;
	if (format && *format)
	{
		va_start(args, format);
		params.buf = ft_strnew(0);
		if (!params.buf)
			return (0);
		while (format[params.fmt_head])
		{
			if (format[params.fmt_head] == '%')
				printer_fmt(format, &params, &args);
			params.fmt_head++;
		}
		printer_fmt(format, &params, &args);
		va_end(args);
		*ret = params.buf;
	}
	return (params.buf ? params.head : 0);
}
