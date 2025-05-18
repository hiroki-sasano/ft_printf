/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 23:39:07 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/18 02:08:02 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"
#include <stdlib.h>

static size_t	handle_dot(t_frags *frags, const char *fmt, size_t pos)
{
	frags->prec_on = 1;
	return (ft_parse_prec(frags, fmt, pos) - 1);
}

static void	handle_specifier(t_frags *frags, char spec)
{
	ft_spec_type(frags, spec);
	if (frags->format == F_PCT)
	{
		if (frags->str)
			free(frags->str);
		frags->str = ft_my_strdup("%");
		frags->str_count = 1;
	}
}

static size_t	format_loop(t_frags *frags, const char *fmt, size_t start)
{
	size_t	i;
	char	c;

	i = 1;
	while (fmt[start + i])
	{
		c = fmt[start + i];
		ft_set_flag(frags, c);
		if (!frags->prec_on && ft_isdigit(c))
			i += ft_parse_width(frags, fmt, start + i) - 1;
		else if (c == '.')
			i += handle_dot(frags, fmt, start + i);
		else if (ft_is_spec(c))
		{
			handle_specifier(frags, c);
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
