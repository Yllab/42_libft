/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:13:36 by hbally            #+#    #+#             */
/*   Updated: 2019/01/14 14:39:32 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

#include <stdio.h>//

/*
** This function sends output to buffer for asprintf & to stdout for printf
** params->head is the index of '\0' in the buffer (params->buf)
*/

void				write_buff(const char *to_add, size_t len, t_index *params)
{
	if (len > 0)
	{
//		printf("In write_buff : head_old is %zu, head is %zu, len(to_add) is %zu\n", params->head_old, params->head, len);

		params->head_old = params->head;
		params->head = params->head + len;

//		printf("In write_buff : Updated : head_old is %zu, head is %zu\n", params->head_old, params->head);

		if (params->asprintf && params->buf)
			if ((params->buf = ft_str_realloc(params->buf, params->head)))
			{
//				printf("In write_buff : realloced with len %zu\n", params->head);
//				printf("In write_buff : copying %zu at index %zu\n", len, params->head_old);

				ft_strncpy(&(params->buf[params->head_old]), to_add, len);
			}
		if (!params->asprintf)
			write(1, to_add, len);
	}
}


/*
**	--- printer_fmt() ---
**	Prints format in between arguments.
*/

void				printer_fmt(const char *format,
								t_index *params,
								va_list *args)
{
//	printf("In printer_fmt : fmt_head is %zu\n", params->fmt_head);//
//	printf("In printer_fmt : Entering write_buff\n");//
	write_buff(&(format[params->fmt_head_old]),
				params->fmt_head - params->fmt_head_old,
				params);
	if (format[params->fmt_head])
	{
		parser(format, params, args);
		params->fmt_head_old = params->fmt_head + 1;
//		printf("In printer_fmt : updated fmt_head_old > %zu\n", params->fmt_head_old);//
	}
	else
	{
//		printf("In printer_fmt : End of fmt\n");//
		params->fmt_head_old = 0;
	}
}

/*
**	--- printer_filler() ---
**	Prints filler chars ' ' or '0' when needed by width
**	or precision.
*/

void				printer_filler(char c, long long len, t_index *params)
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
			write_buff(buffer, len, params);
			free(buffer);
		}
		else
			params->buf = NULL;
	}
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

static void			arg_prefixes(const char *s, const char c, t_index *params)
{
	special_handler(s, c, params);
	if (!(params->flags & 0x4) && (!(params->flags & 0x2) ||
			(c != 'f' && params->precision != -1)))
	{
		width(s, c, params, 1);
		prefix(params, s, c, 1);
	}
	else
	{
		prefix(params, s, c, 1);
		if (!(params->flags & 0x4))
			width(s, c, params, 1);
	}
}

void				printer_arg(const char *s, const char c, t_index *params)
{
	arg_prefixes(s, c, params);
	if (c != 's' && c != 'c' && c != 'f')
		int_precision(params);
	write_buff(s, params->size, params);
	if (c == 'f')
		float_precision(s, params);
	if (params->flags & 0x4)
		width(s, c, params, 1);
}

