/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:20:10 by hbally            #+#    #+#             */
/*   Updated: 2019/01/14 13:14:59 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_test.h"

int		main(int argc, char **argv)
{
	/*
	if (argc == 1 || !strcmp(argv[1], "printf"))
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
	*/
	ft_printf("%s test\n", "test");
//	char *s;
//	ft_asprintf(&s, "%s test\n", "test");
	return (0);
}
