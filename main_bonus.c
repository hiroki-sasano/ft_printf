#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
    int s_ret, f_ret;
    setvbuf(stdout, NULL, _IONBF, 0);

    /* 1. Signed decimal tests */
    printf("=== SIGNED DECIMAL %%d / %%i ===\n");
    /* basic + */
    printf("STD basic +         |"); s_ret = printf("[%+d]\n", 42);
    printf("FT  basic +         |"); f_ret = ft_printf("[%+d]\n", 42);
    printf("R: %d %d\n\n", s_ret, f_ret);
    
    /* space flag */
    printf("STD space flag      |"); s_ret = printf("[% d]\n", 42);
    printf("FT  space flag      |"); f_ret = ft_printf("[% d]\n", 42);
    printf("R: %d %d\n\n", s_ret, f_ret);

    /* plus over space (space ignored) */
    printf("STD plus over space |"); s_ret = printf("[%+d]\n", 42);
    printf("FT  plus over space |"); f_ret = ft_printf("[%+d]\n", 42);
    printf("R: %d %d\n\n", s_ret, f_ret);

    /* left align */
    printf("STD left align      |"); s_ret = printf("[%-8d]\n", 42);
    printf("FT  left align      |"); f_ret = ft_printf("[%-8d]\n", 42);
    printf("R: %d %d\n\n", s_ret, f_ret);

    /* zero pad */
    printf("STD zero pad        |"); s_ret = printf("[%08d]\n", 42);
    printf("FT  zero pad        |"); f_ret = ft_printf("[%08d]\n", 42);
    printf("R: %d %d\n\n", s_ret, f_ret);

    /* zero & minus (0 ignored) */
    printf("STD zero & minus    |"); s_ret = printf("[%-08d]\n", 42);
    printf("FT  zero & minus    |"); f_ret = ft_printf("[%-08d]\n", 42);
    printf("R: %d %d\n\n", s_ret, f_ret);

    /* width.prec */
    printf("STD width.prec      |"); s_ret = printf("[%8.5d]\n", 42);
    printf("FT  width.prec      |"); f_ret = ft_printf("[%8.5d]\n", 42);
    printf("R: %d %d\n\n", s_ret, f_ret);

    /* prec.zero on zero */
    printf("STD prec.zero on 0   |"); s_ret = printf("[%.0d]\n", 0);
    printf("FT  prec.zero on 0   |"); f_ret = ft_printf("[%.0d]\n", 0);
    printf("R: %d %d\n\n", s_ret, f_ret);

    /* INT_MIN */
    printf("STD INT_MIN         |"); s_ret = printf("[%d]\n", INT_MIN);
    printf("FT  INT_MIN         |"); f_ret = ft_printf("[%d]\n", INT_MIN);
    printf("R: %d %d\n\n", s_ret, f_ret);

    /* 2. Unsigned and hex tests */
    printf("=== UNSIGNED / HEX ===\n");
    /* u max */
    printf("STD u max           |"); s_ret = printf("[%u]\n", UINT_MAX);
    printf("FT  u max           |"); f_ret = ft_printf("[%u]\n", UINT_MAX);
    printf("R: %d %d\n\n", s_ret, f_ret);

    /* x hash */
    printf("STD x hash          |"); s_ret = printf("[%#x]\n", 0x2a);
    printf("FT  x hash          |"); f_ret = ft_printf("[%#x]\n", 0x2a);
    printf("R: %d %d\n\n", s_ret, f_ret);

    /* X hash */
    printf("STD X hash          |"); s_ret = printf("[%#X]\n", 0x2a);
    printf("FT  X hash          |"); f_ret = ft_printf("[%#X]\n", 0x2a);
    printf("R: %d %d\n\n", s_ret, f_ret);

    /* x hash zero */
    printf("STD x hash zero     |"); s_ret = printf("[%#x]\n", 0);
    printf("FT  x hash zero     |"); f_ret = ft_printf("[%#x]\n", 0);
    printf("R: %d %d\n\n", s_ret, f_ret);

    /* prec vs hash */
    printf("STD prec vs hash    |"); s_ret = printf("[%#.0x]\n", 0);
    printf("FT  prec vs hash    |"); f_ret = ft_printf("[%#.0x]\n", 0);
    printf("R: %d %d\n\n", s_ret, f_ret);

    /* width+hash+0 */
    printf("STD width+hash+0    |"); s_ret = printf("[%#08x]\n", 0x2a);
    printf("FT  width+hash+0    |"); f_ret = ft_printf("[%#08x]\n", 0x2a);
    printf("R: %d %d\n\n", s_ret, f_ret);

    /* 3. Pointer tests */
    printf("=== POINTER %%p ===\n");
    int x = 42;
    /* normal */
    printf("STD pointer normal  |"); s_ret = printf("[%20p]\n", &x);
    printf("FT  pointer normal  |"); f_ret = ft_printf("[%20p]\n", &x);
    printf("R: %d %d\n\n", s_ret, f_ret);

    /* null */
    printf("STD pointer NULL    |"); s_ret = printf("[%p]\n", NULL);
    printf("FT  pointer NULL    |"); f_ret = ft_printf("[%p]\n", NULL);
    printf("R: %d %d\n\n", s_ret, f_ret);

    /* left align pointer */
    printf("STD ptr left align  |"); s_ret = printf("[%-20p]\n", &x);
    printf("FT  ptr left align  |"); f_ret = ft_printf("[%-20p]\n", &x);
    printf("R: %d %d\n\n", s_ret, f_ret);

    /* 4. Percent symbol tests */
   /* 4. Percent symbol tests */
printf("=== PERCENT EDGE CASES ===\n");
/* lone %% */
printf("STD lone %%         |");      s_ret = printf("[%%]\n");
printf("FT  lone %%         |");      f_ret = ft_printf("[%%]\n");
printf("R: %d %d\n\n", s_ret, f_ret);

/* invalid %%Q (std undefined → literal出力で模倣) */
printf("STD invalid %%Q     |");      s_ret = printf("[%%Q]\n");
printf("FT  invalid %%Q     |");      f_ret = ft_printf("[%%Q]\n");
printf("R: %d %d\n\n", s_ret, f_ret);

/* width only %% */
printf("STD width only %%   |");      s_ret = printf("[%5%%]\n");
printf("FT  width only %%   |");      f_ret = ft_printf("[%5%%]\n");
printf("R: %d %d\n\n", s_ret, f_ret);

/* width.prec trailing . */
printf("STD width.prec .    |");      s_ret = printf("[%5.]\n");
printf("FT  width.prec .    |");      f_ret = ft_printf("[%5.]\n");
printf("R: %d %d\n\n", s_ret, f_ret);

/* 5. String and char */
printf("=== STRING / CHAR ===\n");
/* null string */
printf("STD null str       |");      s_ret = printf("[%s]\n", (char*)NULL);
printf("FT  null str       |");      f_ret = ft_printf("[%s]\n", (char*)NULL);
printf("R: %d %d\n\n", s_ret, f_ret);

/* precision str */
printf("STD precision str    |");     s_ret = printf("[%.3s]\n", "abcdef");
printf("FT  precision str    |");     f_ret = ft_printf("[%.3s]\n", "abcdef");
printf("R: %d %d\n\n", s_ret, f_ret);

/* null char */
printf("STD nul char END  |");        s_ret = printf("[%cEND]\n", '\0');
printf("FT  nul char END  |");        f_ret = ft_printf("[%cEND]\n", '\0');
printf("R: %d %d\n\n", s_ret, f_ret);

/* 6. Combination torture */
printf("=== COMBINATION TORTURE ===\n");
printf("STD mix flags      |");       s_ret = printf("[%-#08x]\n", 0x2a);
printf("FT  mix flags      |");       f_ret = ft_printf("[%-#08x]\n", 0x2a);
printf("R: %d %d\n\n", s_ret, f_ret);

printf("STD combo full     |");       s_ret = printf("[% -+#20.10d]\n", 12345);
printf("FT  combo full     |");       f_ret = ft_printf("[% -+#20.10d]\n", 12345);
printf("R: %d %d\n", s_ret, f_ret);


    return 0;
}