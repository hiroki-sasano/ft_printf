# ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_format
{
    char flag;         // 例: '-', '0'
    int  width;        // 最小フィールド幅
    int  precision;    // 精度（なければ -1）
    char specifier;    // 変換指定子（例: 'd', 's', etc.）
} t_format;


#endif