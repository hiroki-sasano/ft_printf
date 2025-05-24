/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flagc_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:46:54 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/25 08:02:44 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

void	ft_set_flag(t_frags *f, char c)
{
	if (c == '-')
		f->f_minus = 1;
	else if (c == '0' && !f->width && !f->prec_on && !f->f_minus)
		f->f_zero = 1;
	else if (c == '+')
		f->f_plus = 1;
	else if (c == ' ')
		f->f_space = 1;
	else if (c == '#')
		f->f_hash = 1;
}
