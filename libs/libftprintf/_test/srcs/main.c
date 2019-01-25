#include "ft_printf_test.h"

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		int ret;
		ret = ft_dprintf(4390, "TEST %s\n", "HELLO");
		printf("%d\n", ret);
		perror(NULL);
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
