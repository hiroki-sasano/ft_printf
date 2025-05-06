# include "ft_printf.h"

typedef struct s_format
{
    char flag;         // 例: '-', '0'
    int  width;        // 最小フィールド幅
    int  precision;    // 精度（なければ -1）
    char specifier;    // 変換指定子（例: 'd', 's', etc.）
} t_format;


int ft_count_conversiions(const char *format)
{
    int count;
    int i;

    count = 0;
    i = 0;
    int len = strlen(format);
    while(format != '\0')
    {
        if (format == '%')
    }
    return count;
}

char *ft_extract_conversions(const char *format)
{
    char **convertions;
    int     conv_count;
    int i;
    int j;
    int k;

    conv_count = 0;
    i = 0;
    j = 0;
    k = 0;
    while(format[i] != '\0')
    {
        if (format[i] == '%')
            conv_count++;
        else if (conv_count == 0)
            ft_putchar(format[i]);
        else if (conv_count == 1)
        {
            i = ft_judge_conv(&format[i], );
        }

    }
}

int     ft_parse_conv(const char *format, va_list ap)
{
    int i;

    i = 0;
    if (*format == '-' || *format == '0')
    ft_parse_flag();
    ft_parse_length();
    ft_parse_specifier();
}
/******************** 
%[flags][width][.precision][length]specifier
  *flags : - or 0
  *width : 0 ~ 9　INT_MAXまで
  *.precision : 0 ~ 9　INT_MAXまで
  *length : %ld == long : %hhu == unsigned char : %lf == long double 等　課題範囲外 
*/
int ft_printf(const char *format, ...)
{

    va_list ap;
    int     conv_count;
    int i;

    conv_count = 0;
    i = 0;
    while(format[i] != '\0')
    {
        if (format[i] == '%')
            conv_count++;
        else if (conv_count == 0)
            ft_putchar(format[i]);
        else if (conv_count >= 1)
        {
            i += ft_judge_conv(&format[i], ap);
        }
        i++;
    }
    return i;
}
#include <stdio.h>

int main ()
{
    const char msg[] = "%c, %c, %c, %c";

    int i = 0;
    char a = 'A';
    char b = "AA";
    char c = '1';
    char d;
    while(i <= 127)
    {
        d = i;
        ft_printf(msg, a, b, c, d);
        printf(msg, a, b, c, d);
        i++;
    }

}


/*malloc, free, write, va_start, va_arg, va_copy,va_end*/
/*
%c	1文字を出力	'A' → A
%s	文字列（char *）を出力	"Hello"
%p	ポインタのアドレスを表示（0x付き16進）	0x7ffeefbff4c8
%d / %i	符号付き10進整数（int）	-42, 123
%u	符号なし10進整数（unsigned int）	4294967295
%x	小文字の16進数（unsigned int）	ff
%X	大文字の16進数（unsigned int）	FF
%%	% そのものを出力	%
*/

/****************************** 
サポートするフラグ：-0.* と 最小フィールド幅
-	左寄せ	最優先
0	ゼロ埋め	- があると無効
*	幅（または精度）を引数で渡す	va_arg() で取得 ワイルドカード
数字（例: 8）	最小幅を指定	パースして整数にする
*****************************/

/*
hirokisasano@hirokinoMacBook-Air ft_printf % cc testprintf.c 
testprintf.c:7:33: warning: data argument not used by format string [-Wformat-extra-args]
    7 |     printf("%d %d %d", 1, 1, 1, 1);
      |            ~~~~~~~~~~           ^
1 warning generated.
hirokisasano@hirokinoMacBook-Air ft_printf % ./a.out 
1 1 1%      
*/              