/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:50:21 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/25 07:56:16 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

// void	ft_apply(t_frags *frags)
// {
// 	if (frags->format == F_INVALID)
// 		return ;
// 	if (frags->prec_on)
// 		ft_apply_prcn(frags);
// 	if (frags->f_plus && (frags->format == F_DEC || frags->format == F_INT))
// 		ft_add_sign_or_space(frags);
// 	else if (frags->f_space && (frags->format == F_DEC
// 			|| frags->format == F_INT))
// 		ft_add_sign_or_space(frags);
// 	if (frags->f_hash && (frags->format == F_HEX_LOW
// 			|| frags->format == F_HEX_UP))
// 		ft_hash_join(frags);
// 	if (frags->f_zero && !frags->f_minus && !frags->prec_on)
// 		ft_zero_pad(frags);
// 	if (frags->width && !frags->f_minus && !frags->f_zero)
// 		ft_apply_width(frags);
// 	if (frags->f_minus)
// 		ft_left_align(frags);
// 	if (frags->str)
// 	{
// 		if (frags->format == F_CHAR && frags->str[0] == '\0')
// 			frags->str_count = 1;
// 		else
// 			frags->str_count = ft_my_strlen(frags->str);
// 	}
// }

void	ft_apply(t_frags *f)
{
	if (f->format == F_INVALID || f->str == NULL)
		return ;
	/* 1. + / space   （prefix がまだ無ければ付ける）*/
	if ((f->f_plus || f->f_space) && (f->format == F_DEC || f->format == F_INT))
		ft_add_sign_or_space(f);
	/* 2. # hash (0x / 0X)  - 16進のみ  */
	if (f->f_hash && (f->format == F_HEX_LOW || f->format == F_HEX_UP))
		ft_hash_join(f); /* prefix が無ければ付加 */
	/* 3. precision   */
	if (f->prec_on)
		ft_apply_prcn(f); /* digits のみを 0 埋め／切り詰め */
	/* 4. 0-flag width（precision が無いときだけ） */
	if (f->f_zero && !f->f_minus && !f->prec_on && f->width)
	{
		ft_zero_pad(f); /* 0 で幅を満たす */
		return ;         /* 幅を満たしたので空白パディングはスキップ */
	}
	/* 5. 通常の幅（空白パディング）*/
	if (f->width && !f->f_minus)
		ft_apply_width(f); /* 右寄せ ※ 空白は prefix より前 */
	/* 6. - flag 左寄せ（幅があれば今度は後ろに空白） */
	if (f->f_minus)
		ft_left_align(f);
}
