/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_prcn_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:08:25 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/18 12:36:59 by hisasano         ###   ########.fr       */
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
	if (frags->format == F_STR && frags->precision >= 0
		&& (size_t)frags->precision < frags->str_count)
	{
		frags->str[frags->precision] = '\0';
		frags->str_count = frags->precision;
		return (1);
	}
	return (0);
}

static void	apply_numeric_zero_pad(t_frags *frags)
{
	size_t	zero_len;
	char	*zeros;
	char	*joined;

	if (frags->precision <= 0 || (size_t)frags->precision <= frags->str_count)
		return ;
	zero_len = frags->precision - frags->str_count;
	zeros = malloc(zero_len + 1);
	if (!zeros)
		return ;
	ft_memset(zeros, '0', zero_len);
	zeros[zero_len] = '\0';
	joined = ft_strjoin(zeros, frags->str);
	free(zeros);
	if (!joined)
		return ;
	free(frags->str);
	frags->str = joined;
	frags->str_count = frags->precision;
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