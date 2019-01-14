/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:13:36 by hbally            #+#    #+#             */
/*   Updated: 2019/01/14 11:11:19 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"
#include "libft.h"

/*
** This function sends output to buffer for asprintf & to stdout for printf
*/

void				write_buff(char *to_add,
								size_t len,
								t_index *params)
{
	size_t			swap;

	if (params->asprintf)
	{	
		if (params->buf)
		{
			swap = params->head;
			params->head = params->head_old + len;
			params->head_old = swap;
			if ((params->buf = ft_str_realloc(s, params->head)))
				ft_strncpy(&(params->buf[params->head_old]), to_add, len);
		}
		else
			ft_putstr("Malloc error.\n");
	}
	else if (!params->asprintf)
		write(1, to_add, len);
}

/*
**	--- printer_arg() ---
**
**	Prints arguments to printf with the correct format
**
**	Pipe order :
**
**	Right align (default) :
**	(width or prefix(1)) > (int_precision) > value > (float_precision)
**
**	Left align :
**	(prefix(1)) > (int_precision) > value > (float_precision) > (width)
**
**	(1) : prefix applies one of ('-', '+', ' ', '0/0x/0X')
**
** Flag is represented as a bit code
** ...00001 > #
** ...00010 > 0
** ...00100 > -
** ...01000 > sp
** ...10000 > +
*/

static int			arg_prefixes(const char *s, const char c, t_index *params)
{
	int				printed;

	printed = 0;
	special_handler(s, c, params);
	if (!(params->flags & 0x4) && (!(params->flags & 0x2) ||
			(c != 'f' && params->precision != -1)))
	{
		printed += width(s, c, params, 1);
		printed += prefix(params, s, c, 1);
	}
	else
	{
		printed += prefix(params, s, c, 1);
		if (!(params->flags & 0x4))
			printed += width(s, c, params, 1);
	}
	return (printed);
}

int					printer_arg(const char *s, const char c, t_index *params)
{
	int				printed;

	printed = arg_prefixes(s, c, params);
	printed += (c != 's' && c != 'c' && c != 'f') ? int_precision(params) : 0;
	if ((write(1, s, params->size) == -1))
		return (printed);
	printed += params->size;
	printed += (c == 'f') ? float_precision(s, params) : 0;
	printed += (params->flags & 0x4) ? width(s, c, params, 1) : 0;
	return (printed);
}

/*
**	--- printer_filler() ---
**	Prints filler chars ' ' or '0' when needed by width
**	or precision.
*/

int					printer_filler(const char c, long long len)
{
	char			*buffer;
	int				i;

	if (len <= 999999)
	{
		buffer = ft_strnew(len);
		if (buffer)
		{
			i = 0;
			while (i < len)
			{
				buffer[i] = c;
				i++;
			}
			write(1, buffer, len);
			free(buffer);
			return ((int)len);
		}
	}
	return (0);
}

/*
**	--- printer_fmt() ---
**	Prints format in between arguments.
*/

void				printer_fmt(const char *format,
								t_index *params,
								va_list *args)
{
	params->fmt_head = params->fmt_head - params->fmt_head_old;
	write_buff(&(format[params->fmt_head_old]),
				params->fmt_head - params->fmt_head_old,
				params);
	if (format[params->fmt_head])
	{
		parser(format, params, args);
		params->fmt_head_old = params->fmt_head + 1;
	}
	else
		params->fmt_head_old = 0;
}
