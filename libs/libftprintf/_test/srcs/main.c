/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:20:10 by hbally            #+#    #+#             */
/*   Updated: 2019/01/14 15:01:51 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_test.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
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
		char *s1;
		char *s2;
		int ret1;
		int ret2;

//		printf("%s   %50d %+.40d %.5f test %c %p %lld %#o\n", "alk;dfj;lakfdj", 4392, 43240, 432.549f, '2', &s1, 904399940394ll, 909);
//		ft_printf("%s   %50d %+.40d %.5f test %c %p %lld %#o\n", "alk;dfj;lakfdj", 4392, 43240, 432.549f, '2', &s1, 904399940394ll, 909);
//		printf("\n\n\n");
//		asprintf(&s1, "%s   %50d %+.40d %.5f test %c %p %lld %#o\n", "alk;dfj;lakfdj", 4392, 43240, 432.549f, '2', &s1, 904399940394ll, 909);
//		ft_asprintf(&s2, "%s   %50d %+.40d %.5f test %c %p %lld %#o\n", "alk;dfj;lakfdj", 4392, 43240, 432.549f, '2', &s1, 904399940394ll, 909);

		printf("%050d\n%0100d\n%0150d", 123, 123, 123);
		ft_printf("%050d\n%0100d\n%0150d", 123, 123, 123);
		/*
		if (!ft_strcmp(s1, s2))
			ft_printf("Ok\n");
		else
		{
			ft_putendl(s1);
			ft_putendl(s2);
		}
		*/
		
	}
	return (0);
}
