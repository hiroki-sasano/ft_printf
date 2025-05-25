/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 23:39:07 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/25 10:04:13 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"
#include <stdlib.h>

size_t	handle_dot(t_frags *f, const char *fmt, size_t pos)
{
	f->prec_on = 1;
	if (ft_isdigit((unsigned char)fmt[pos + 1]))
		return (ft_parse_prec(f, fmt, pos) - 1);
	f->precision = 0;
	f->f_add0 = 1; 
	return (0);
}
void	handle_specifier(t_frags *f, char spec)
{
	ft_spec_type(f, spec);
	if (f->format == F_PCT)
	{
		if (f->str)
			free(f->str);
		f->str = ft_my_strdup("%");
		if (f->str == NULL)
			return ;
		f->str_count = 1;
		f->width = 0;
		f->f_minus = 0;
		f->f_zero = 0;
		f->f_plus = 0;
		f->f_space = 0;
		f->f_hash = 0;
		f->prec_on = 0;
	}
}

static size_t	format_loop(t_frags *f, const char *fmt, size_t start)
{
	size_t	i;
	char	c;

	i = 1;
	while (fmt[start + i])
	{
		c = fmt[start + i];
		ft_set_flag(f, c);
		if (!f->prec_on && ft_isdigit(c))
			i += ft_parse_width(f, fmt, start + i) - 1;
		else if (c == '.')
			i += handle_dot(f, fmt, start + i);
		else if (ft_is_spec(c))
		{
			handle_specifier(f, c);
			if (c == '%' && fmt[start + i + 1] == '%')
				i++;
			i++;
			break ;
		}
		i++;
	}
	return (i);
}

void	ft_parse_format(t_frags *frags, const char *format, size_t start)
{
	size_t	len;

	len = format_loop(frags, format, start);
	if (frags->format == F_NONE)
	{
		frags->format = F_INVALID;
		frags->format_len = len;
		ft_set_str(frags, format, start);
		return ;
	}
	frags->format_len = len;
}
