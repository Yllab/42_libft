/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:15:51 by hbally            #+#    #+#             */
/*   Updated: 2018/12/22 17:05:44 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"
#include "libft.h"

size_t				parser(const char *format,
							t_index *params;
							va_list *args,
							char **s)
{
	params->head++;
	params.precision = -1;
	while (format[params->head])
	{
		if (!check_flag(format[params->head], &params))
			if (!check_width(format, &(params->head), &params))
				if (!check_precision(format, &(params->head), &params))
					if (!check_length(format, &(params->head), &params))
						if (dispatcher(format[params->head], args, &params, s))
							return (1);
		params->head++;
	}
	params->head--;
	return (0);
}
