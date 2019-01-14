#include <stdarg.h>
#include "libftprintf.h"
#include "libft.h"

int				ft_asprintf(char **ret, const char *format, ...)
{
	va_list		args;
	size_t		head;
	t_index		params;

	ft_bzero(&params, sizeof(t_index));
	if (ret)
	{
		*ret = NULL;
		if (format && *format)
		{
			va_start(args, format);
			params->buf = ft_strnew(0);
			if (!params->buf)
				return (NULL);
			while (format[params.fmt_head])
			{
				if (format[params.fmt_head] == '%')
					printer_fmt(format, &params, &args);
				params.fmt_head++;
			}
			printer_fmt(format, &params, &args);
			va_end(args);
			*ret = params->buf;
		}
	}
	return (params->head);
}
