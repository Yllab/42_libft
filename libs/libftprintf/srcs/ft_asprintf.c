#include <stdarg.h>
#include "libftprintf.h"
#include "libft.h"

int				ft_asprintf(char **ret, const char *format, ...)
{
	va_list		args;
	size_t		head;
	t_index		params;

	if (ret && format && *format)
	{
		ret = ft_strnew(0);
		if (!ret)
			return (NULL);
		va_start(args, format);
		ft_bzero(&params, sizeof(t_index));
		while (format[params.head])
		{
			if (format[params.head] == '%')
				printer_fmt(format, &params, &args, ret);
			params.head++;
		}
		printer_fmt(format, &params, &args, ret);
		va_end(args);
	}
	return (params->head);
}
