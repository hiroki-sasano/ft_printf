#include "ft_printf.h"
#ifdef BONUS_MODE
# include "ft_bonus.h"
#endif

#include <stdarg.h>

typedef enum
{
	F_CHAR,      // %c: 文字
	F_STR,    // %s: 文字列
	F_PTR,   // %p: ポインタ（16進数）
	F_DEC,   // %d: 10進数（符号付き）
	F_INT,   // %i: 整数（符号付き）
	F_UINT,  // %u: 10進数（符号なし）
	F_HEX_LOW, // %x: 16進数（小文字）
	F_HEX_UP, // %X: 16進数（大文字）
	F_PCT,   // %%: パーセント記号
	F_INVALID
}						ArgType;

typedef struct
{
	unsigned int	f_minus;
	unsigned int	f_zero;
	unsigned int	f_plus;
	unsigned int	f_spase;
	unsigned int	f_hash;
	int				width;
	int				precision;
	ArgType			format;
	char			*str;
	size_t			str_count;
}					FormatFrags;

void	ft_spec_type(FormatFrags *frags, char *type)
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
	frags->format = F_INVALID;
	return ;
}

#include <limits.h>
#include <stdlib.h>

size_t	ft_parse_width(FormatFrags *frags, const char *format, size_t start)
{
	size_t	i;
	char	*temp;

	i = 0;
	while (format[start + i] >= 0 && format[start + i])
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (format[start + i] >= 0 && format[start + i])
		temp[i++] = format[start + i];
	temp[i] = '\0';
	if (ft_atoi(temp) > INT_MAX)
		frags->width = 0;
	frags->width = ft_atoi(temp);
	free(temp);
	return (i);
}

static int	ft_parse_digits(const char *str, int *i, int sign, int *overflow)
{
	int	result;

	result = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		if (result > INT_MAX / 10 || (result == INT_MAX / 10 && ((!sign
						&& (str[*i] - '0') > 7)
					|| (sign && (str[*i] - '0') > 8))))
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
	int	i;
	int	result;
	int	sign;
	int	overflow;

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

#include <limits.h>
#include <stdlib.h>

size_t	ft_parse_prec(FormatFrags *frags, const char *format, size_t start)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 1;
	while (format[start + i] >= 0 && format[start + i])
		i++;
	temp = (char *)malloc(sizeof(char) * i);
	if (!temp)
		return (NULL);
	i = 1;
	j = 0;
	while (format[start + i] >= 0 && format[start + i])
		temp[j++] = format[start + i];
	temp[i] = '\0';
	if (ft_my_atoi(temp) > INT_MAX)
		frags->width = 0;
	frags->width = ft_my_atoi(temp);
	free(temp);
	return (i);
}

void	ft_parse_format(FormatFrags *frags, const char *format, size_t start,
		size_t f_size)
{
	size_t	i;
	char	c;

	i = 0;
	while (format[start + i++] != '%' && (start + i) <= f_size)
	{
		c = format[start + i];
		if (c == '-')
			frags->f_minus = 1;
		else if (c == '0')
			frags->f_zero = 1;
		else if (c == '+')
			frags->f_plus = 1;
		else if (c == ' ')
			frags->f_spase = 1;
		else if (c == '#')
			frags->f_hash = 1;
		else if (frags->precision == 0 && (c >= 0 && c <= 9))
			i += ft_parse_width(frags, format, start + i);
		else if (c == '.')
			i += ft_parse_prec(frags, format, start + i);
		else
			ft_spec_type(frags, format);
		i++;
	}
}

void	ft_reset_format_spec(FormatFrags *frags)
{
	frags->f_minus = 0;
	frags->f_zero = 0;
	frags->f_plus = 0;
	frags->f_spase = 0;
	frags->f_hash = 0;
	frags->width = 0;
	frags->precision = 0;
	free(frags->str);
	frags->str_count = 0;
	return ;
}
char	*ft_conv_char(char c)
{
	char	*str;

	str = ft_calloc(2, sizeof(char));
	if (str)
		str[0] = c;
	return (str);
}

char	*ft_convert_str(char *str)
{
	if (str)
		return (str);
	return (NULL);
}

char	*ft_convert_decimal(char *str)
{
	return (ft_my_atoi(str));
}

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
	str = (char *)malloc(len + 1); // +1 for '\0'
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

static char	*ft_convert_unsigned(unsigned int i)
{
	return (ft_utoa(i));
}

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

#include <stdint.h>
static char	*ft_convert_pointer(void *ptr)
{
	uintptr_t	addr;
	char		*hex;
	char		*result;

	addr = (uintptr_t)ptr;
	hex = ft_utoa_base(addr, "0123456789abcdef");
	result = ft_strjoin("0x", hex);
	free(hex);
	return (result);
}

#include <stdlib.h>
#include <ctype.h>

static char	*str_to_upper(const char *s)
{
	int		i = 0;
	char	*res = malloc(ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = ft_toupper((unsigned char)s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

static char	*ft_convert_hex(unsigned int value, ArgType type)
{
	char	*hex;
	char	*result;

	if (type == F_HEX_LOW)
		hex = ft_utoa_base(value, "0123456789abcdef");
	else
		hex = ft_utoa_base(value, "0123456789ABCDEF");
	if (!hex)
		return (NULL);
	return (hex);
}

void	ft_apply_prcn(FormatFrags *frags)
{
	char	*zero;
	char	*result;

	if (frags->precision <= 0)
		return ;
	zero = (char *)malloc(sizeof(char) * (frags->precision + 1));
	if (!zero)
		return ;
	ft_memset(zero, '0', frags->precision);
	zero[frags->precision] = '\0';
	result = ft_strjoin(zero, frags->str);
	free(zero);
	if (!result)
		return ;
	free(frags->str);
	frags->str = ft_strdup(result);
	free(result);
	frags->str_count = ft_strlen(frags->str);
}

void ft_left_align(FormatFrags *frags)
{
	size_t s_size;
	char *temp;
	char *result;
	
	s_size = 0;
	if (frags->precision)
		ft_apply_prcn(frags);
	if (frags->width > ft_strlen(frags->str))
		s_size = frags->width - ft_strlen(frags->str);
	temp = (char *)malloc(sizeof(char) * (s_size + 1));
	if (!temp)
		return ;
	ft_memset(temp, ' ', s_size);
	temp[s_size] = '\0';;
	result = ft_strjoin(frags->str, temp);
	free(temp);
	if (!result)
		return;
	free(frags->str);
	frags->str = result;
	frags->str_count = ft_strlen(frags->str);
}

static void	ft_apply(FormatFrags *frags)
{
	if (frags->f_minus)
		ft_left_align(frags);
	if (frags->f_zero && (!frags->f_minus))
		ft_zero_pad(frags);
	if (frags->f_plus && (frags->format == F_DEC || frags->format == F_INT))
		ft_plus_join(frags);
	if (frags->f_spase)
		ft_spase_join(frags);
	if (frags->f_hash)
		ft_hash_join(frags);
	if (frags->width && (!frags->f_minus || !frags->f_zero))
		ft_apply_width(frags);
	if (frags->precision && (!frags->f_minus || !frags->width))
		ft_apply_prcn(frags);
	
	return ;
}

void	ft_conv(FormatFrags *frags, va_list(arg))
{
	char	*str;

	str = NULL;
	if (frags->format == F_CHAR)
		str = ft_convert_char((char)va_arg(arg, int));
	else if (frags->format == F_STR)
		str = ft_convert_str(va_arg(arg, char *));
	else if (frags->format == F_DEC)
		str = ft_convert_decimal(va_arg(arg, int));
	else if (frags->format == F_UINT)
		str = ft_convert_unsigned(va_arg(arg, unsigned int));
	else if (frags->format == F_PTR)
		str = ft_convert_pointer(va_arg(arg, void *));
	else if (frags->format == F_HEX_LOW
		|| frags->format == F_HEX_UP)
		str = ft_convert_hex(va_arg(arg, unsigned int), frags->format);
	else if (frags->format == F_PCT)
		str = ft_strdup("%");
	if (str)
		frags->str = str;
	str = ft_strdup("");
	ft_apply(frags);

	return ;
}

void				ft_putarg(FormatFrags frags);

/* . - > 0 */
/* (. > 0) 	"width & . = (%8.5d " 00042")" (%-8.5d "00042 ")
  %3.5d → "00042"
(+ > ' ') (0 < .) (- > 0) (# %x %o 0x, 0X, 0 が先頭に付加)
 (' ' % d " 42")  (%+d %+i "+42" ) */
/*
• Manage any combination of the following flags: ’-0.’ and the field minimum width
under all conversions.
• Manage all the following flags: ’# +’ (Yes, one of them is a space)
*/

/*  % [flags] [width] [.precision] [specifier]  */
/*    -0#" "+  INT_MAX　.INT_MAX                */

int	ft_printf_bonus(va_list arg, const char *format)
{
	FormatFrags	frags;
	size_t		f_size;
	size_t		i;
	char		*s;
	va_list		arg;

	i = 0;
	f_size = ft_strlen(format);
	while (i <= f_size)
	{
		if (format[i] == '%')
		{
			ft_reset_format_spec(&frags);
			ft_parse_format(&frags, format, i, f_size);
			ft_conv(&frags, arg);
			ft_putstr(frags.str);
			i += frags.str_count;
		}
		if (format[i] != '%')
			if (!write(1, format[i], 1))
				return -1;
			else 
				size_t result += write(); 
		// write戻り値確認
		i++;
	}
	return (result);
}

/********** 引数が　０の場合　要検討 */
int	ft_printf(const char *format, ...)
{
	va_list	arg;

	if (!format)
		return (0);
#ifdef BONUS_MODE
	return (ft_printf_bonus(arg, *format));
#else
	return (ft_print_basic(arg, *format));
#endif
}

/* . - > 0 */
/* (. > 0) 	"width & . = (%8.5d " 00042")" (%-8.5d "00042 ")
(+ > ' ') (0 < .) (- > 0) (# %x %o 0x, 0X, 0 が先頭に付加)
 (' ' % d " 42")  (%+d %+i "+42" ) */
/*
• Manage any combination of the following flags: ’-0.’ and the field minimum width
under all conversions.
• Manage all the following flags: ’# +’ (Yes, one of them is a space)
*/

/*  % [flags] [width] [.precision] [specifier]  */
/*    -0#" "+  INT_MAX　.INT_MAX                */

/*
| 指定       | 結果例 (`n = 42`)              |
| -------- | --------------------------- |
| `%5d`    | `"   42"` （幅5、右寄せ）          |
| `%05d`   | `"00042"` （幅5、0埋め）          |
| `%.5d`   | `"00042"` （精度5桁）            |
| `%8.5d`  | `"   00042"`（精度で0埋め → 幅で空白） |
| `%-8.5d` | `"00042   "`（左寄せ）           |
| `%08.5d` | `"   00042"`（※`0`は無視）       |
*/
/*
| 指定        | 結果例（文字列 "Hello, world"） |
| --------- | ----------------------- |
| `%10s`    | `"Hello, world"`（幅無効）   |
| `%.5s`    | `"Hello"`               |
| `%10.5s`  | `"     Hello"`          |
| `%-10.5s` | `"Hello     "`          |
*/

/*
• Manage any combination of the following flags: ’-0.’ and the field minimum width
under all conversions.
• Manage all the following flags: ’# +’ (Yes, one of them is a space)
*/

/*
| 指定       | 結果例 (`n = 42`)              |
| -------- | --------------------------- |
| `%5d`    | `"   42"` （幅5、右寄せ）          |
| `%05d`   | `"00042"` （幅5、0埋め）          |
| `%.5d`   | `"00042"` （精度5桁）            |
| `%8.5d`  | `"   00042"`（精度で0埋め → 幅で空白） |
| `%-8.5d` | `"00042   "`（左寄せ）           |
| `%08.5d` | `"   00042"`（※`0`は無視）       |
*/
/*
| 指定        | 結果例（文字列 "Hello, world"） |
| --------- | ----------------------- |
| `%10s`    | `"Hello, world"`（幅無効）   |
| `%.5s`    | `"Hello"`               |
| `%10.5s`  | `"     Hello"`          |
| `%-10.5s` | `"Hello     "`          |
*/

/*
RETURN VALUES
		These functions return the number of characters printed (not including the trailing ‘\0’ used to end output
		to strings), except for snprintf() and vsnprintf(),
			which return the number of characters that would have
		been printed if the size were unlimited (again,
			not including the final ‘\0’).  These functions return a
		negative value if an error occurs.*/
/*
char        • %c Prints a single character.
char *      • %s Prints a string (as defined by the common C convention).
void *      • %p The void
	* pointer argument has to be printed in hexadecimal format.
int         • %d Prints a decimal (base 10) number.
int         • %i Prints an integer in base 10.
unsigned int• %u Prints an unsigned decimal (base 10) number.
255 → ff    • %x Prints a number in hexadecimal (base 16) lowercase format.
255 → FF    • %X Prints a number in hexadecimal (base 16) uppercase format.
％  • %% Prints a percent sign.
*/

// /********************
// %[flags][width][.precision][length]specifier
//   *flags : - or 0
//   *width : 0 ~ 9　INT_MAXまで
//   *.precision : 0 ~ 9　INT_MAXまで
//   *length : %ld == long : %hhu == unsigned char : %lf == long double 等　課題範囲外
// */

// #include "ft_printf.h"
// #include <stdio.h>
// #include <limits.h>

// int main() {

//     // テストケース1: 単一の文字
//     ft_printf("c:::単一の文字::::::::::::::::::%c,%c\n", 'A', 'B');
//     printf("c:::単一の文字::::::::::::::::::%c,%c\n\n", 'A', 'B');

//     // 拡張: 特殊文字
//     ft_printf("c:::単一の文字(スペース):::::::::%c\n", ' ');
//     printf("c:::単一の文字(スペース):::::::::%c\n\n", ' ');

//     ft_printf("c:::単一の文字(改行):::::::::::%c\n", '\n');
//     printf("c:::単一の文字(改行):::::::::::%c\n\n", '\n');

//     // テストケース2: 文字列
//     ft_printf("s:::文字列:::::::::::::::::::::%s\n", "world");
//     printf("s:::文字列:::::::::::::::::::::%s\n\n", "world");

//     // テストケース2.2: 空文字列
//     ft_printf("空文字列::::::%s\n", "");
//     printf("空文字列::::::%s\n\n", "");

//     // テストケース2.3: NULLポインタ
//     ft_printf("NULLポインタ:::::: %s\n", NULL);
//     printf("NULLポインタ:::::: %s\n\n", "(null)");//未定義動作

//     // テストケース2.4: 長い文字列
//     ft_printf("長い文字列:::::::::::%s\n",
//	"This is a very long string to test the ft_printf function.");
//     printf("長い文字列:::::::::::%s\n\n",
//	"This is a very long string to test the ft_printf function.");

//     // 拡張: 特殊文字を含む文字列
//     ft_printf("s:::特殊文字の文字列:::::::::::%s\n", "Hello, \tWorld! \nNewline");
//     printf("s:::特殊文字の文字列:::::::::::%s\n\n", "Hello, \tWorld! \nNewline");

//     // テストケース3: ポインタ
//     ft_printf("p:::ポインタ引数を16進数形式::::::%p\n", &main);
//     printf("p:::ポインタ引数を16進数形式::::::%p\n\n", &main);

//     // テストケース3.1: NULLポインタのポインタ表示
//     ft_printf("NULLポインタのポインタ::::::%p\n", NULL);
//     printf("NULLポインタのポインタ::::::%p\n\n", NULL);

//     // テストケース4: 10進数
//     ft_printf("d:::10進数:::::::::::::::::::::%d\n", 0);
//     printf("d:::10進数:::::::::::::::::::::%d\n\n", 0);

//     // テストケース4.1: 大きな整数
//     ft_printf("大きな整数:::::::::::::::::%d\n", INT_MAX);
//     printf("大きな整数:::::::::::::::::%d\n\n", INT_MAX);

//     // テストケース4.2: 小さな整数
//     ft_printf("小さな整数:::::::::::::::::%d\n", INT_MIN);
//     printf("小さな整数:::::::::::::::::%d\n\n", INT_MIN);

//     // テストケース5: 10進数の整数
//     ft_printf("i:::10進数:::::::::::::::::::::%i\n", 0);
//     printf("i:::10進数:::::::::::::::::::::%i\n\n", 0);

//     // テストケース5.1: 大きな整数
//     ft_printf("大きな整数:::::::::::::::::%i\n", INT_MAX);
//     printf("大きな整数:::::::::::::::::%i\n\n", INT_MAX);

//     // テストケース5.2: 小さな整数
//     ft_printf("小さな整数:::::::::::::::::%i\n", INT_MIN);
//     printf("小さな整数:::::::::::::::::%i\n\n", INT_MIN);

//     // テストケース6: 符号なし10進数
//     ft_printf("u:::符号なし10進数::::::::::::::%u\n", 0);
//     printf("u:::符号なし10進数::::::::::::::%u\n\n", 0);

//     // テストケース6.1: 負の符号なし整数
//     ft_printf("負の符号なし整数:::::::::::::::%u\n", -1);
//     printf("負の符号なし整数:::::::::::::::%u\n\n", -1);

//     // テストケース6.2: 大きな符号なし整数
//     ft_printf("大きな符号なし整数:::::::::::::::%u\n", UINT_MAX);
//     printf("大きな符号なし整数:::::::::::::::%u\n\n", UINT_MAX);

//     // テストケース7: 16進数の小文字形式
//     ft_printf("x:::16進数の小文字形式:::::::::::%x\n", 255);
//     printf("x:::16進数の小文字形式:::::::::::%x\n\n", 255);

//     // 拡張: 境界値の16進数
//     ft_printf("x:::境界値 (UINT_MAX):::::::::::%x\n", UINT_MAX);
//     printf("x:::境界値 (UINT_MAX):::::::::::%x\n\n", UINT_MAX);

//     // テストケース8: 16進数の大文字形式
//     ft_printf("X:::16進数の大文字形式:::::::::::%X\n", 255);
//     printf("X:::16進数の大文字形式:::::::::::%X\n\n", 255);

//     // 拡張: 負数の16進数
//     ft_printf("x:::負数 (負の16進数):::::::::::%x\n", -1);
//     printf("x:::負数 (負の16進数):::::::::::%x\n\n", -1);

//     // テストケース9: パーセント記号
//     ft_printf("パーセント記号:%%\n");
//     printf("パーセント記号:%%\n\n");

//     // テストケース9.1: パーセント記号を2つ連続
//     ft_printf("パーセント記号2つ連続:%%%%\n");
//     printf("パーセント記号2つ連続:%%%%\n\n");

//     // テストケース10: 複数のフォーマット指定子
//     ft_printf("複数のフォーマット指定子::::::%d, %s, %c, %x, %p, %%\n", 42, "answer",
//	'A', 255, &main);
//     printf("複数のフォーマット指定子::::::%d, %s, %c, %x, %p, %%\n\n", 42, "answer", 'A',
//	255, &main);

//     // 拡張: 負数を含む複合フォーマット
//     ft_printf("複数のフォーマット(負数): %d, %s, %c, %x, %p, %%\n", -42,
//		"negative",	'Z', -255, &main);
//     printf("複数のフォーマット(負数): %d, %s, %c, %x, %p, %%\n\n", -42, "negative", 'Z',
//	-255, &main);

//     return (0);
// }