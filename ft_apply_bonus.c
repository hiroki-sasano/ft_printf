/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:50:21 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/17 23:09:29 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

void	ft_apply(t_frags *frags)
{
	if (frags->format == F_INVALID)
		return ;
	if (frags->prec_on)
		ft_apply_prcn(frags);
	if (frags->f_plus && (frags->format == F_DEC || frags->format == F_INT))
		ft_add_sign_or_space(frags);
	else if (frags->f_space && (frags->format == F_DEC
			|| frags->format == F_INT))
		ft_add_sign_or_space(frags);
	if (frags->f_hash && (frags->format == F_HEX_LOW
			|| frags->format == F_HEX_UP))
		ft_hash_join(frags);
	if (frags->f_zero && !frags->f_minus && !frags->prec_on)
		ft_zero_pad(frags);
	if (frags->width && !frags->f_minus && !frags->f_zero)
		ft_apply_width(frags);
	if (frags->f_minus)
		ft_left_align(frags);
	if (frags->str)
		frags->str_count = ft_my_strlen(frags->str);
}
