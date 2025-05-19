#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
	int ft_ret, std_ret;
	
	// --- %c ---
	char	null_char = '\0';
	ft_ret = ft_printf("ft : [%%c] -> [%c]\n", 'A');
	std_ret =    printf("std: [%%c] -> [%c]\n", 'A');
	printf("Return: ft=%d, std=%d\n\n", ft_ret, std_ret);

	ft_ret = ft_printf("ft : [%%c] -> [%c]\n", '\n');
	std_ret =    printf("std: [%%c] -> [%c]\n", '\n');
	printf("Return: ft=%d, std=%d\n\n", ft_ret, std_ret);

	ft_ret =  ft_printf("ft : [%%c] -> [NULL %c]\n", null_char);
	std_ret =    printf("std: [%%c] -> [NULL %c]\n", null_char);
	printf("Return: ft=%d, std=%d\n\n", ft_ret, std_ret);

	ft_ret = ft_printf("ft : [%%c] -> [%c]\n", 31);
	std_ret =    printf("std: [%%c] -> [%c]\n", 31);
	printf("Return: ft=%d, std=%d\n\n", ft_ret, std_ret);

	ft_ret = ft_printf("ft : [%%c] -> [%c]\n", 32);
	std_ret =    printf("std: [%%c] -> [%c]\n", 32);
	printf("Return: ft=%d, std=%d\n\n", ft_ret, std_ret);

	ft_ret = ft_printf("ft : [%%c] -> [%c]\n", 126);
	std_ret =    printf("std: [%%c] -> [%c]\n", 126);
	printf("Return: ft=%d, std=%d\n\n", ft_ret, std_ret);

	ft_ret = ft_printf("ft : [%%c] -> [%c]\n", 127);
	std_ret =    printf("std: [%%c] -> [%c]\n", 127);
	printf("Return: ft=%d, std=%d\n\n", ft_ret, std_ret);

	// --- %s ---
	char *null_str = NULL;
	ft_ret = ft_printf("ft : [%%s] -> [%s]\n", "Hello");
	std_ret =    printf("std: [%%s] -> [%s]\n", "Hello");
	printf("Return: ft=%d, std=%d\n\n", ft_ret, std_ret);

	ft_ret = ft_printf("ft : [%%s] -> [%s]\n", "");
	std_ret =    printf("std: [%%s] -> [%s]\n", "");
	printf("Return: ft=%d, std=%d\n\n", ft_ret, std_ret);

	ft_ret = ft_printf("ft : [NULL %%s] -> [%s]\n", null_str);
	std_ret =    printf("std: [NULL %%s] -> [%s]\n", null_str);
	printf("Return: ft=%d, std=%d\n\n", ft_ret, std_ret);

	// --- %p ---
	int x = 42;
	void *p = &x;
	ft_ret = ft_printf("ft : [%%p] -> [%p]\n", p);
	std_ret =    printf("std: [%%p] -> [%p]\n", p);
	printf("Return: ft=%d, std=%d\n\n", ft_ret, std_ret);

	ft_ret = ft_printf("ft : [NULL %%p] -> [%p]\n", NULL);
	std_ret =    printf("std: [NULL %%p] -> [%p]\n", NULL);
	printf("Return: ft=%d, std=%d\n\n", ft_ret, std_ret);

	// --- %d / %i ---
	ft_ret = ft_printf("ft : [%%d %%i] -> [%d][%i]\n", 123, -456);
	std_ret =    printf("std: [%%d %%i] -> [%d][%i]\n", 123, -456);
	printf("Return: ft=%d, std=%d\n\n", ft_ret, std_ret);

	ft_ret = ft_printf("ft : [INT_MIN] -> [%d]\n", INT_MAX);
	std_ret =    printf("std: [INT_MIN] -> [%d]\n", INT_MAX);
	printf("Return: ft=%d, std=%d\n\n", ft_ret, std_ret);

	ft_ret = ft_printf("ft : [INT_MIN] -> [%d]\n", INT_MIN);
	std_ret =    printf("std: [INT_MIN] -> [%d]\n", INT_MIN);
	printf("Return: ft=%d, std=%d\n\n", ft_ret, std_ret);

	// --- %u ---
	ft_ret = ft_printf("ft : [%%u] -> [%u]\n", 0);
	std_ret =    printf("std: [%%u] -> [%u]\n", 0);
	printf("Return: ft=%d, std=%d\n\n", ft_ret, std_ret);
	
	ft_ret = ft_printf("ft : [%%u] -> [%u]\n", -1);
	std_ret =    printf("std: [%%u] -> [%u]\n", -1);
	printf("Return: ft=%d, std=%d\n\n", ft_ret, std_ret);

	ft_ret = ft_printf("ft : [%%u] -> [%u]\n", 3000000000U);
	std_ret =    printf("std: [%%u] -> [%u]\n", 3000000000U);
	printf("Return: ft=%d, std=%d\n\n", ft_ret, std_ret);

	ft_ret = ft_printf("ft : [%%u] -> [%u]\n", UINT_MAX);
	std_ret =    printf("std: [%%u] -> [%u]\n", UINT_MAX);
	printf("Return: ft=%d, std=%d\n\n", ft_ret, std_ret);

	// --- %x / %X ---
	ft_ret = ft_printf("ft : [%%x %%X] -> [%x][%X]\n", 255, 255);
	std_ret =    printf("std: [%%x %%X] -> [%x][%X]\n", 255, 255);
	printf("Return: ft=%d, std=%d\n\n", ft_ret, std_ret);

	ft_ret = ft_printf("ft : [0 %%x] -> [%x]\n", 0);
	std_ret =    printf("std: [0 %%x] -> [%x]\n", 0);
	printf("Return: ft=%d, std=%d\n\n", ft_ret, std_ret);

	ft_ret = ft_printf("ft : [%%x] -> [%x]\n", UINT_MAX);
	std_ret =    printf("std: [%%x] -> [%x]\n", UINT_MAX);
	printf("Return: ft=%d, std=%d\n\n", ft_ret, std_ret);

	// --- %% ---
	ft_ret = ft_printf("ft : [%%%%] -> [%%]\n");
	std_ret =    printf("std: [%%%%] -> [%%]\n");
	printf("Return: ft=%d, std=%d\n\n", ft_ret, std_ret);

	ft_ret = ft_printf("ft : [%%d, %%s, %%c, %%x, %%p,%%%%]%d, %s, %c, %x, %p, %%\n", -42, "negative",	'Z', -255, &main);
	std_ret =   printf("std: [%%d, %%s, %%c, %%x, %%p,%%%%]%d, %s, %c, %x, %p, %%\n", -42, "negative",	'Z', -255, &main);
	printf("Return: ft=%d, std=%d\n\n", ft_ret, std_ret);
	return (0);
}


// int main(void)
// {
// 	int ret_std, ret_ft;

// 	// Char
// 	ret_std = printf("STD: char = [%c]\n", 'A');
// 	ret_ft = ft_printf("FT : char = [%c]\n", 'A');
// 	printf("Return: STD = %d, FT = %d\n\n", ret_std, ret_ft);

// 	ret_std = printf("STD: char = [%c]\n", 31);
// 	ret_ft = ft_printf("FT : char = [%c]\n", 31);
// 	printf("Return: STD = %d, FT = %d\n\n", ret_std, ret_ft);

// 	ret_std = printf("STD: char = [%c]\n", 32);
// 	ret_ft = ft_printf("FT : char = [%c]\n", 32);
// 	printf("Return: STD = %d, FT = %d\n\n", ret_std, ret_ft);

// 	ret_std = printf("STD: char = [%c]\n", 126);
// 	ret_ft = ft_printf("FT : char = [%c]\n", 126);
// 	printf("Return: STD = %d, FT = %d\n\n", ret_std, ret_ft);

// 	ret_std = printf("STD: char = [%c]\n", 127);
// 	ret_ft = ft_printf("FT : char = [%c]\n", 127);
// 	printf("Return: STD = %d, FT = %d\n\n", ret_std, ret_ft);

// 	// String
// 	ret_std = printf("STD: string = [%s]\n", "Hello");
// 	ret_ft = ft_printf("FT : string = [%s]\n", "Hello");
// 	printf("Return: STD = %d, FT = %d\n\n", ret_std, ret_ft);

// 	// NULL string
// 	ret_std = printf("STD: null string = [%s]\n", (char *)NULL);
// 	ret_ft = ft_printf("FT : null string = [%s]\n", (char *)NULL);
// 	printf("Return: STD = %d, FT = %d\n\n", ret_std, ret_ft);

// 	// Pointer
// 	void *p = &ret_std;
// 	ret_std = printf("STD: pointer = [%p]\n", p);
// 	ret_ft = ft_printf("FT : pointer = [%p]\n", p);
// 	printf("Return: STD = %d, FT = %d\n\n", ret_std, ret_ft);

// 	// Decimal
// 	ret_std = printf("STD: int = [%d]\n", -12345);
// 	ret_ft = ft_printf("FT : int = [%d]\n", -12345);
// 	printf("Return: STD = %d, FT = %d\n\n", ret_std, ret_ft);

// 	// Unsigned
// 	ret_std = printf("STD: uint = [%u]\n", 3000000000U);
// 	ret_ft = ft_printf("FT : uint = [%u]\n", 3000000000U);
// 	printf("Return: STD = %d, FT = %d\n\n", ret_std, ret_ft);

// 	// Hex lower
// 	ret_std = printf("STD: hex (x) = [%x]\n", 255);
// 	ret_ft = ft_printf("FT : hex (x) = [%x]\n", 255);
// 	printf("Return: STD = %d, FT = %d\n\n", ret_std, ret_ft);

// 	// Hex upper
// 	ret_std = printf("STD: hex (X) = [%X]\n", 255);
// 	ret_ft = ft_printf("FT : hex (X) = [%X]\n", 255);
// 	printf("Return: STD = %d, FT = %d\n\n", ret_std, ret_ft);

// 	// Percent
// 	ret_std = printf("STD: percent = [%%]\n");
// 	ret_ft = ft_printf("FT : percent = [%%]\n");
// 	printf("Return: STD = %d, FT = %d\n\n", ret_std, ret_ft);

// 	return 0;
// }
