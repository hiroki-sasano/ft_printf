# ifndef FT_PRINTF_H
# define FT_PRINTF_H

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
	size_t			inc_count;
}					FormatFrags;


#endif