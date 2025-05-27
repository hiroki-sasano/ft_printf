/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_format_spec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:56:03 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/27 18:30:01 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	ft_reset_format_spec(t_frags *frags)
{
	if (frags->prefix)
		free(frags->prefix);
	frags->prefix = NULL;
	frags->f_minus = 0;
	frags->f_zero = 0;
	frags->f_plus = 0;
	frags->f_space = 0;
	frags->f_hash = 0;
	frags->width = 0;
	frags->prec_on = 0;
	frags->precision = -1;
	frags->format = F_NONE;
	frags->f_add0 = 0;
	if (frags->str)
		free(frags->str);
	frags->str = NULL;
	frags->str_count = 0;
	frags->format_len = 0;
}
