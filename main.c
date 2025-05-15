
// #include "ft_printf.h"
// #include <stdio.h>

// int main(void)
// {
// 	int		count;
// 	char	c = 'A';
// 	char	*str = "Hello, printf!";
// 	void	*ptr = str;
// 	int		num = -42;
// 	unsigned int u = 3000000000U;
// 	int		hex = 255;

// 	count = ft_printf(
// 		"Char: %c\nString: %s\nPointer: %p\nDecimal: %d\nInteger: %i\nUnsigned: %u\nHex(lower): %x\nHex(upper): %X\nPercent: %%\n",
// 		c, str, ptr, num, num, u, hex, hex
// 	);
// 	ft_printf("Total printed characters: %d\n", count);

// 	// 比較用
// 	printf(
// 		"[printf]\nChar: %c\nString: %s\nPointer: %p\nDecimal: %d\nInteger: %i\nUnsigned: %u\nHex(lower): %x\nHex(upper): %X\nPercent: %%\n",
// 		c, str, ptr, num, num, u, hex, hex
// 	);
// 	return (0);
// }

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int ret_std;
	int ret_ft;

	// 1. '%' だけ
	printf("\n[STD]   Case 1: \"%%\"\n");
	ret_std = printf("->[%]");
	printf("\nReturn: %d\n", ret_std);

	printf("\n[FT ]   Case 1: \"%%\"\n");
	ret_ft = ft_printf("->[%]");
	printf("\nReturn: %d\n", ret_ft);

	// 2. '%' のあと終端文字
	printf("\n[STD]   Case 2: \"%%\\0\"\n");
	ret_std = printf("->[%%\0]\n");  // 実際にはこれ途中で出力終わる
	printf("\nReturn: %d\n", ret_std);

	printf("\n[FT ]   Case 2: \"%%\\0\"\n");
	ret_ft = ft_printf("->[%%\0]\n");
	printf("\nReturn: %d\n", ret_ft);

	// 3. '%' のあと無効な文字
	printf("\n[STD]   Case 3: \"%%Q\"\n");
	ret_std = printf("->[%Q]");
	printf("\nReturn: %d\n", ret_std);

	printf("\n[FT ]   Case 3: \"%%Q\"\n");
	ret_ft = ft_printf("->[%Q]");
	printf("\nReturn: %d\n", ret_ft);

	// 4. '%' のあと数字とピリオドで終わり
	printf("\n[STD]   Case 4: \"%%5.\"\n");
	ret_std = printf("->[%5.]");
	printf("\nReturn: %d\n", ret_std);

	printf("\n[FT ]   Case 4: \"%%5.\"\n");
	ret_ft = ft_printf("->[%5.]");
	printf("\nReturn: %d\n", ret_ft);

	return (0);
}


// int main(void)
// {
// 	ft_printf("A double percent: %%\n");
// 	return 0;
// }

// #include "ft_printf.h"

// int main(void)
// {
// 	char *str = "hello";
// 	ft_printf("String: %s\n", str);
// 	return 0;
// }


/********** 引数が　０の場合　要検討 */
/*
%.Nd → 最小桁数が N になるように ゼロ埋め

精度指定があると、0 フラグは無視される

0 のみを出力する場合、%.0d は空文字になる（特別ルール）
*/

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

//     // ��ストケース3.1: NULLポインタのポインタ表示
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