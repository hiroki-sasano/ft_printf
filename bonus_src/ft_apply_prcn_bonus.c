/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_prcn_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:08:25 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/25 06:58:36 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"
#include <stdlib.h>

static int	handle_zero_prec_zero_val(t_frags *frags)
{
	if ((frags->format == F_DEC || frags->format == F_INT
			|| frags->format == F_UINT || frags->format == F_HEX_LOW
			|| frags->format == F_HEX_UP) && frags->precision == 0 && frags->str
		&& frags->str[0] == '0' && frags->str[1] == '\0')
	{
		free(frags->str);
		frags->str = ft_my_strdup("");
		frags->str_count = 0;
		frags->f_hash = 0;
		return (1);
	}
	return (0);
}

static int	handle_string_precision(t_frags *frags)
{
	char	*tmp;

	if (frags->format == F_STR && frags->precision >= 0
		&& (size_t)frags->precision < frags->str_count)
	{
		tmp = ft_substr(frags->str, 0, frags->precision);
		if (!tmp)
			return (1);
		free(frags->str);
		frags->str = tmp;
		frags->str_count = frags->precision;
		return (1);
	}
	return (0);
}

/*
 * precision が「**数字部分**を何桁にするか」を示す点に合わせて，
 * ① 先頭の符号／0x を **prefix** として切り分ける
 * ② digits_len = そのほかの数字だけの長さ
 * ③ zero_len  = precision - digits_len で決定
 * ④ prefix → 0パディング → 数字 という順で連結
 * 最後に frags->str_count を更新します。
 */
static void	apply_numeric_zero_pad(t_frags *f)
{
	size_t	zero_len;
	char	*zeros;
	char	*tmp;
	char	*joined;

	if (f->format == F_STR || f->format == F_CHAR || f->precision <= 0
		|| (size_t)f->precision <= f->str_count)
		return ;
	zero_len = f->precision - f->str_count;
	zeros = ft_calloc(zero_len + 1, 1);
	if (zeros == NULL)
		return ;
	ft_memset(zeros, '0', zero_len);
	if (f->prefix != NULL)
		tmp = ft_my_strjoin(f->prefix, zeros);
	else
		tmp = ft_my_strdup(zeros);
	if (tmp == NULL)
	{
		free(zeros);
		return ;
	}
	joined = ft_my_strjoin(tmp, f->str);
	free(zeros);
	free(tmp);
	free(f->str);
	if (joined == NULL)
		return ;
	f->str = joined;
	f->str_count = f->precision;
}

void	ft_apply_prcn(t_frags *frags)
{
	if (!frags->str)
		return ;
	if (handle_zero_prec_zero_val(frags))
		return ;
	if (handle_string_precision(frags))
		return ;
	apply_numeric_zero_pad(frags);
}

// if (frags->precision <= 0 || (size_t)frags->precision <= frags->str_count)
// zero_pat on off
//"(size_t)frags->precision <= frags->str_count" is alredy　full str