#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int ret_std, ret_ft;

	// Width + Precision
	ret_std = printf("STD: [%8.5d]\n", 42);
	ret_ft = ft_printf("FT : [%8.5d]\n", 42);
	printf("Return: STD = %d, FT = %d\n\n", ret_std, ret_ft);

	// Zero-padding
	ret_std = printf("STD: [%08d]\n", 42);
	ret_ft = ft_printf("FT : [%08d]\n", 42);
	printf("Return: STD = %d, FT = %d\n\n", ret_std, ret_ft);

	// Left-align
	ret_std = printf("STD: [%-8d]\n", 42);
	ret_ft = ft_printf("FT : [%-8d]\n", 42);
	printf("Return: STD = %d, FT = %d\n\n", ret_std, ret_ft);

	// Plus flag
	ret_std = printf("STD: [%+d]\n", 42);
	ret_ft = ft_printf("FT : [%+d]\n", 42);
	printf("Return: STD = %d, FT = %d\n\n", ret_std, ret_ft);

	// Space flag
	ret_std = printf("STD: [% d]\n", 42);
	ret_ft = ft_printf("FT : [% d]\n", 42);
	printf("Return: STD = %d, FT = %d\n\n", ret_std, ret_ft);

	// Hash with x/X
	ret_std = printf("STD: [%#x]\n", 42);
	ret_ft = ft_printf("FT : [%#x]\n", 42);
	printf("Return: STD = %d, FT = %d\n\n", ret_std, ret_ft);

	ret_std = printf("STD: [%#X]\n", 42);
	ret_ft = ft_printf("FT : [%#X]\n", 42);
	printf("Return: STD = %d, FT = %d\n\n", ret_std, ret_ft);

	// Hash with 0 value
	ret_std = printf("STD: [%#x]\n", 0);
	ret_ft = ft_printf("FT : [%#x]\n", 0);
	printf("Return: STD = %d, FT = %d\n\n", ret_std, ret_ft);

	return 0;
}
