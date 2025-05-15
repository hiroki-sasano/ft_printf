#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


static int	ft_myintlen(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		sign;
	int		len;
	char	*result;

	nb = n;
	sign = (n < 0);
	if (sign)
		nb = -nb;
	len = ft_myintlen(nb) + sign;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (len-- > sign)
	{
		result[len] = nb % 10 + '0';
		nb /= 10;
	}
	if (sign)
		result[0] = '-';
	return (result);
}


size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

#include <stdint.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (ft_strlen(s1) > SIZE_MAX - ft_strlen(s2) - 1)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

#include "ft_printf.h"

size_t	ft_my_strlen(const char *s)
{
	size_t	len;

	if (!s)
	{
		write(2, "ERROR: NULL passed to ft_my_strlen\n", 35);
		return (0);
	}
	write(2, "DEBUG: ft_my_strlen START\n", 27);

	len = 0;
	while (s[len])
	{
		if (len > 1000)
		{
			write(2, "ERROR: ft_my_strlen runaway\n", 29);
			break;
		}
		len++;
	}
	write(2, "DEBUG: ft_my_strlen END\n", 25);
	return (len);
}


#include "ft_printf.h"
#include <limits.h>

static int	ft_parse_digits(const char *str, int *i, int sign, int *overflow)
{
	int	result;

	result = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		if (result > INT_MAX / 10 || (result == INT_MAX / 10 && ((!sign
						&& (str[*i] - '0') > 7) || (sign && (str[*i]
							- '0') > 8))))
		{
			*overflow = 1;
			if (sign)
				return (INT_MIN);
			return (INT_MAX);
		}
		result = result * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (result);
}

int	ft_my_atoi(const char *str)
{
	int		i;
	int		result;
	int		sign;
	int		overflow;

	i = 0;
	result = 0;
	sign = 0;
	overflow = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = 1;
		i++;
	}
	result = ft_parse_digits(str, &i, sign, &overflow);
	if (overflow)
		return (result);
	if (sign)
		return (-result);
	return (result);
}


#include "ft_printf.h"
#include <stdlib.h>

char	*ft_utoa_base(uintptr_t n, const char *base)
{
	char		*str;
	size_t		base_len;
	size_t		len;
	uintptr_t	tmp;

	base_len = 0;
	while (base[base_len])
		base_len++;
	len = 1;
	tmp = n;
	while (tmp >= base_len)
	{
		tmp /= base_len;
		len++;
	}
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = base[n % base_len];
		n /= base_len;
	}
	return (str);
}


#include "ft_printf.h"
#include <stdlib.h>

static size_t	ft_uint_len(unsigned int n)
{
	size_t	len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	size_t	len;
	char	*str;

	len = ft_uint_len(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}


#include "ft_printf.h"
#include <stdlib.h>

#include <unistd.h> 

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*ft_my_strdup(const char *s1)
{
	char	debug_buf[100];  // アドレス表示用
	char	num_buf[20];     // 数値表示用
	size_t	len;
	size_t	i;
	char	*dup;

	if (!s1)
	{
		write(2, "ERROR: NULL in ft_my_strdup\n", 29);
		return (NULL);
	}

	// ポインタアドレス表示
	sprintf(debug_buf, "ft_my_strdup received pointer: %p\n", (void *)s1);
	write(2, debug_buf, strlen(debug_buf));

	len = ft_my_strlen(s1);

	// 文字列長ログ
	write(2, "STR LEN: ", 9);
	sprintf(num_buf, "%zu\n", len);
	write(2, num_buf, strlen(num_buf));

	// 安全な長さで中身出力
	write(2, "STR SAFE DUMP: ", 15);
	write(2, s1, len);
	write(2, "\n", 1);

	// 複製処理
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}


#include "ft_printf.h"

char	*ft_conv_unsigned(unsigned int i)
{
	return (ft_utoa(i));
}

#include "ft_printf.h"

#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*ft_conv_str(char *str)
{
	char	buf[100];

	if (str == NULL)
	{
		write(2, "DEBUG: NULL string received\n", 29);
		str = "(null)";
	}
	else
	{
		write(2, "DEBUG: Non-NULL string received\n", 33);
		sprintf(buf, "POINTER: %p\n", (void *)str);
		write(2, buf, strlen(buf));  // アドレスを確認
	}
	return (ft_my_strdup(str));
}




#include "ft_printf.h"
#include <stdint.h>
#include <stdlib.h>

char	*ft_conv_pointer(void *ptr)
{
	uintptr_t	addr;
	char		*hex;
	char		*result;

	if (!ptr)
		return (ft_my_strdup("0x0"));
	addr = (uintptr_t)ptr;
	hex = ft_utoa_base(addr, "0123456789abcdef");
	if (!hex)
		return (NULL);
	result = ft_strjoin("0x", hex);
	free(hex);
	return (result);
}

#include "ft_printf.h"

char	*ft_conv_hex(unsigned int value, t_argtype type)
{
	char	*hex;

	if (type == F_HEX_LOW)
		hex = ft_utoa_base(value, "0123456789abcdef");
	else
		hex = ft_utoa_base(value, "0123456789ABCDEF");
	if (!hex)
		return (NULL);
	return (hex);
}

#include "ft_printf.h"

char	*ft_conv_decimal(int n)
{
	return (ft_itoa(n));
}

#include "ft_printf.h"
#include <stdlib.h>

char	*ft_conv_char(char c)
{
	char	*str;

	str = malloc(2);
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}


#include <errno.h>
#include <unistd.h>

ssize_t	ft_do_write(int fd, const void *buf, size_t len)
{
	size_t	written;
	ssize_t	ret;

	written = 0;
	while (written < len)
	{
		ret = write(fd, (const char *)buf + written, len - written);
		if (ret == -1)
		{
			if (errno == EINTR)
				continue ;
			return (-1);
		}
		written += ret;
	}
	return ((ssize_t)written);
}

#include "ft_printf.h"

void	ft_spec_type(t_frags *frags, char type)
{
	if (type == 'c')
		frags->format = F_CHAR;
	else if (type == 's')
		frags->format = F_STR;
	else if (type == 'p')
		frags->format = F_PTR;
	else if (type == 'd')
		frags->format = F_DEC;
	else if (type == 'i')
		frags->format = F_INT;
	else if (type == 'u')
		frags->format = F_UINT;
	else if (type == 'x')
		frags->format = F_HEX_LOW;
	else if (type == 'X')
		frags->format = F_HEX_UP;
	else if (type == '%')
		frags->format = F_PCT;
	else
		frags->format = F_INVALID;
}

#include "ft_printf.h"
#include <stdlib.h>

void	ft_reset_format_spec(t_frags *frags)
{
	frags->f_minus = 0;
	frags->f_zero = 0;
	frags->f_plus = 0;
	frags->f_spase = 0;
	frags->f_hash = 0;
	frags->width = 0;
	frags->precision = 0;
	if (frags->str != NULL)
		free(frags->str);
	frags->str = NULL;
	frags->str_count = 0;
	return ;
}

#include "ft_printf.h"
#include <unistd.h>

#include <stdio.h> // sprintf 用
#include <string.h>
void	ft_conv(t_frags *frags, va_list *arg)
{
	char	*str;
	char	log[100];

	str = NULL;

	sprintf(log, "DEBUG: ft_conv format = %d\n", frags->format);
	write(2, log, strlen(log));

	if (frags->format == F_CHAR)
	{
		int c = va_arg(*arg, int);
		sprintf(log, "DEBUG: CHAR = %c (%d)\n", c, c);
		write(2, log, strlen(log));
		str = ft_conv_char((char)c);
	}
	else if (frags->format == F_STR)
	{
		char *s = va_arg(*arg, char *);
		sprintf(log, "DEBUG: STR PTR = %p\n", (void *)s);
		write(2, log, strlen(log));
		str = ft_conv_str(s);
	}
	else if (frags->format == F_PTR)
		str = ft_conv_pointer(va_arg(*arg, void *));
	else if (frags->format == F_DEC || frags->format == F_INT)
		str = ft_conv_decimal(va_arg(*arg, int));
	else if (frags->format == F_UINT)
		str = ft_conv_unsigned(va_arg(*arg, unsigned int));
	else if (frags->format == F_HEX_LOW || frags->format == F_HEX_UP)
		str = ft_conv_hex(va_arg(*arg, unsigned int), frags->format);
	else if (frags->format == F_PCT)
		str = ft_my_strdup("%");

	frags->str = str;
	if (str)
		frags->str_count = ft_my_strlen(str);
	else
	{
		frags->str_count = 0;
		write(2, "DEBUG: ft_conv got NULL result\n", 31);
	}
}



#include "ft_printf.h"
#include <unistd.h>

static int	ft_handle_percent(t_frags *frags, va_list *arg, const char *format,
    size_t *i)
{
ssize_t	ret_size;

(*i)++;
if (format[*i] == '\0')
    return (-1);
write(2, "ft_handle_percent: type = ", 27);
write(2, &format[*i], 1);
write(2, "\n", 1);
ft_spec_type(frags, format[*i]);
ft_conv(frags, arg);
ret_size = ft_do_write(1, frags->str, frags->str_count);
if (ret_size == -1)
    return (-1);
(*i)++;
return (ret_size);
}

int	ft_printf_basic(va_list *arg, const char *format, t_frags *frags)
{
	size_t	i;
	ssize_t	ret_size;
	ssize_t	total_size;

	write(2, "FULL FORMAT STRING:\n", 21);
	write(2, format, ft_strlen(format));
	write(2, "\n", 1);

	i = 0;
	total_size = 0;
	while (format[i])
	{
		ft_reset_format_spec(frags);
		// %% の場合（リテラルの %）
		if (format[i] == '%' && format[i + 1] == '%')
		{
			if (write(1, "%", 1) == -1)
				return (-1);
			i += 2;
			total_size++;
			continue ;
		}
		// 通常の変換指定子
		if (format[i] == '%')
		{
			ret_size = ft_handle_percent(frags, arg, format, &i);
			if (ret_size == -1)
				return (-1);
			total_size += ret_size;
			continue ;
		}
		// 通常文字
		if (write(1, &format[i++], 1) == -1)
			return (-1);
		total_size++;
	}
	return (total_size);
}


#include "ft_printf.h"
#ifdef BONUS_MODE
# include "ft_printf_bonus.h"
#endif

#ifdef BONUS_MODE

int	ft_printf_dispatch(va_list *arg, const char *format, t_frags *frags)
{
	return (ft_printf_bonus(arg, format, frags));
}

#else

int	ft_printf_dispatch(va_list *arg, const char *format, t_frags *frags)
{
	return (ft_printf_basic(arg, format, frags));
}
#endif

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		result;
	t_frags	frags;

	frags.str = NULL;
	if (!format)
		return (0);
	va_start(arg, format);
	result = ft_printf_dispatch(&arg, format, &frags);
	va_end(arg);
	return (result);
}

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	char c = 'A';
	char *str = "Hello, printf!";
	void *ptr = str;
	int num = -42;
	unsigned int u = 3000000000U;
	int hex = 255;

	write(2, "MAIN STR: ", 10);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);

	ft_printf(
		"Char: %c\nString: %s\nPointer: %p\nDecimal: %d\nInteger: %i\nUnsigned: %u\nHex(lower): %x\nHex(upper): %X\nPercent: %%\n",
		c, str, ptr, num, num, u, hex, hex
	);

	return 0;
}
