/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:56:07 by hbally            #+#    #+#             */
/*   Updated: 2019/01/14 13:49:27 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"
#include "libft.h"

#include <stdio.h> //

int				ft_printf(const char *format, ...)
{
	va_list		args;
	t_index		params;

	ft_bzero(&params, sizeof(t_index));
	if (format && *format)
	{
		va_start(args, format);
		while (format[params.fmt_head])
		{
			printf("In ft_printf : fmt_head is %zu\n", params.fmt_head);//
			if (format[params.fmt_head] == '%')
			{
				printf("In ft_printf : Entering printer_fmt\n");//
				printer_fmt(format, &params, &args);
			}
			printf("In ft_printf : Exited printer_fmt\n");//
			printf("In ft_printf : fmt_head is %zu\n. Adding 1..", params.fmt_head);//
			params.fmt_head++;
			printf("In ft_printf : fmt_head is %zu\n", params.fmt_head);//
		}
		printf("In ft_printf : Last pass, fmt_head is %zu\n, format len is %zu", params.fmt_head, ft_strlen(format));//
		printer_fmt(format, &params, &args);
		va_end(args);
	}
	return (params.head);
}
