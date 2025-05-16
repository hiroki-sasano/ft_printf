/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 23:39:07 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/16 20:50:10 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "ft_printf.h"

static size_t	format_loop(t_frags *frags, const char *format, size_t start)
{
	size_t	i;
	char	c;

	i = 1;
	while (format[start + i])
	{
		c = format[start + i];
		ft_set_flag(frags, c);
		if (frags->precision == 0 && ft_isdigit(c))
			i += ft_parse_width(frags, format, start + i) - 1;
		else if (c == '.')
			i += ft_parse_prec(frags, format, start + i) - 1;
		else if (ft_is_spec(c))
		{
			ft_spec_type(frags, c);
			if (frags->format == F_PCT)
				ft_set_str(frags, format, start);
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
