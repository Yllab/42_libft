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
//		test_double(&printf);
//		test_string(&printf);
	}
	if (!strcmp(argv[1], "ft_printf"))
	{
		test_int(&ft_printf);
//		test_double(&ft_printf);
//		test_string(&ft_printf);
	}
	if (!strcmp(argv[1], "asprintf"))
	{
		char *s1;
		char *s2;
		int ret1;
		int ret2;
		
		return (0);
	}
}
