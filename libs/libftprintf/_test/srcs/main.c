#include "ft_printf_test.h"

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_printf("%d4", 123);
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
		char *s1;
		char *s2;
		int ret1;
		int ret2;
		
		ret1 = asprintf(&s1, "%s   %50d %+.40d %.5f test %c %lld %#o\n", "alk;dfj;lakfdj", 4392, 43240, 432.549f, '2', 904399940394ll, 909);
		ret2 = ft_asprintf(&s2, "%s   %50d %+.40d %.5f test %c %lld %#o\n", "alk;dfj;lakfdj", 4392, 43240, 432.549f, '2', 904399940394ll, 909);
		printf("ret_real : %d\nret_mine : %d\n",
				ret1, ret2);

		if (!ft_strcmp(s1, s2))
			printf("DIFF OK\n");
		else
			printf("DIFF NOT OK\n");
		ft_asprintf(NULL, "");
		printf("%s", s1);
		return (0);
	}
}
