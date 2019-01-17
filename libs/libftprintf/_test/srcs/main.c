#include "ft_printf_test.h"

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
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

		printf("%s   %50d %+.40d %.5f test %c %p %lld %#o\n", "alk;dfj;lakfdj", 4392, 43240, 432.549f, '2', &s1, 904399940394ll, 909);
		ft_printf("%s   %50d %+.40d %.5f test %c %p %lld %#o\n", "alk;dfj;lakfdj", 4392, 43240, 432.549f, '2', &s1, 904399940394ll, 909);

		printf("%050d\n%0100d\n%0150d", 123, 123, 123);
		ft_printf("%050d\n%0100d\n%0150d", 123, 123, 123);
		
		return (0);
	}
}
