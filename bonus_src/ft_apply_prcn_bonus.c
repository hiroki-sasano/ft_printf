/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_prcn_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:08:25 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/27 19:56:07 by hisasano         ###   ########.fr       */
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

static int	handle_string_precision(t_frags *f)
{
	char	*tmp;

	if (f->format == F_STR && f->str_count == 6 && !ft_strncmp(f->str, "(null)",
			6))
	{
		if (f->precision == 0)
		{
			free(f->str);
			f->str = ft_my_strdup("");
			f->str_count = 0;
			return (1);
		}
	}
	if (f->format == F_STR && f->precision >= 0
		&& (size_t)f->precision < f->str_count)
	{
		tmp = ft_substr(f->str, 0, f->precision);
		if (!tmp)
			return (1);
		free(f->str);
		f->str = tmp;
		f->str_count = f->precision;
		return (1);
	}
	return (0);
}

static int	null_str_with_prec(t_frags *f)
{
	int	len;

	len = ft_my_strlen("(null)");
	if (f->format == F_STR && f->str && !ft_strncmp(f->str, "(null)", len)
		&& f->prec_on)
	{
		free(f->str);
		if (f->precision < 0 || f->precision >= len)
			f->str = ft_my_strdup("(null)");
		else
			f->str = ft_my_strdup("");
		if (f->str == NULL)
			return (1);
		f->str_count = ft_my_strlen(f->str);
		return (1);
	}
	return (0);
}

void	ft_apply_prcn(t_frags *frags)
{
	if (null_str_with_prec(frags))
		return ;
	if (!frags->str)
		return ;
	if (handle_zero_prec_zero_val(frags))
		return ;
	if (handle_string_precision(frags))
		return ;
	ft_app_num_zeropad(frags);
}

// if (frags->precision <= 0 || (size_t)frags->precision <= frags->str_count)
// zero_pat on off
//"(size_t)frags->precision <= frags->str_count" is alredy　full str