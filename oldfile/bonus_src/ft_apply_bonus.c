/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:50:21 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/25 11:16:01 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

void	ft_apply(t_frags *f)
{
	if (f->format == F_INVALID || f->str == NULL)
		return ;
	if ((f->f_plus || f->f_space) && (f->format == F_DEC || f->format == F_INT))
		ft_add_sign_or_space(f);
	if (f->f_hash && (f->format == F_HEX_LOW || f->format == F_HEX_UP))
		ft_hash_join(f); 
	if (f->prec_on)
		ft_apply_prcn(f); 

	if (f->f_zero && !f->f_minus && !f->prec_on && f->width)
	{
		ft_zero_pad(f); 
		return ; 
	}

	if (f->width && !f->f_minus)
		ft_apply_width(f);

	if (f->f_minus)
		ft_left_align(f);
}
