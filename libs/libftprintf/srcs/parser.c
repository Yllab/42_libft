/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:09:48 by hbally            #+#    #+#             */
/*   Updated: 2019/01/17 14:18:07 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

int					parser(const char *format, t_index *params, va_list *args)
{
	params->fmt_head++;
	params->precision = -1;
	while (format[params->fmt_head])
	{
		if (!check_flag(format[params->fmt_head], params))
			if (!check_width(format, &(params->fmt_head), params, args))
				if (!check_precision(format, &(params->fmt_head), params))
					if (!check_length(format, &(params->fmt_head), params))
						if (dispatcher(format[params->fmt_head], args, params))
							return (0);
		params->fmt_head++;
	}
	params->fmt_head--;
	return (1);
}
