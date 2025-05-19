/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:42:23 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/19 19:03:01 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <sys/types.h>

typedef enum e_argtype
{
	F_NONE = -1,
	F_CHAR,
	F_STR,
	F_PTR,
	F_DEC,
	F_INT,
	F_UINT,
	F_HEX_LOW,
	F_HEX_UP,
	F_PCT,
	F_INVALID
}					t_argtype;

typedef struct s_frags
{
	unsigned int	f_minus;
	unsigned int	f_zero;
	unsigned int	f_plus;
	unsigned int	f_space;
	unsigned int	f_hash;
	size_t			width;
	unsigned int	prec_on;
	int				precision;
	t_argtype		format;
	char			*str;
	size_t			str_count;
	size_t			format_len;
}					t_frags;

char				*ft_conv_char(char c);
char				*ft_conv_str(char *str);
char				*ft_conv_decimal(int n);
char				*ft_conv_unsigned(unsigned int i);
char				*ft_conv_pointer(void *ptr);
char				*ft_conv_hex(unsigned int value, t_argtype type);

int					ft_my_atoi(const char *str);
void				ft_reset_format_spec(t_frags *frags);
char				*ft_utoa(unsigned int n);
char				*ft_utoa_base(uintptr_t n, const char *base);
ssize_t				ft_do_write(int fd, const void *buf, size_t len);
int					ft_is_spec(char c);
void				ft_spec_type(t_frags *frags, char type);
void				ft_conv(t_frags *frags, va_list *arg);
int					ft_printf_basic(va_list *arg, const char *format,
						t_frags *frags);
int					ft_printf(const char *format, ...);
char				*ft_my_strdup(const char *s1);
size_t				ft_my_strlen(const char *s);

#endif