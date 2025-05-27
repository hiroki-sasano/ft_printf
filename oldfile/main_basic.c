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

	ft_ret = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	std_ret =   printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf("Return: ft=%d, std=%d\n\n", ft_ret, std_ret);

	
}

// valgrind --leak-check=full --show-leak-kinds=all ./test_mandatory
