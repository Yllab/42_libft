/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:20:10 by hbally            #+#    #+#             */
/*   Updated: 2019/01/16 11:43:14 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_test.h"

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_printf("%*d", 50, 50);
		return (0);
	}
	if (!strcmp(argv[1], "printf"))
	{
		test_int(&printf);
		test_double(&printf);
		test_string(&printf);
	}
	if (!strcmp(argv[1], "ft_printf"))
	{
		test_int(&ft_printf);
		test_double(&ft_printf);
		test_string(&ft_printf);
	}
	if (!strcmp(argv[1], "asprintf"))
	{
		return (0);
	}
}
