/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_prec_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:48:38 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/16 17:48:58 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

size_t	ft_parse_prec(t_frags *frags, const char *format, size_t start)
{
	size_t	i;

	if (!ft_isdigit(format[start + 1]))
	{
		frags->precision = 0;
		return (1);
	}
	frags->precision = ft_my_atoi(&format[start + 1]);
	i = 1;
	while (ft_isdigit(format[start + i]))
		i++;
	return (i);
}
