/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:34:20 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/16 14:19:26 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_conv(t_frags *frags, va_list *arg)
{
	char	*str;

	str = NULL;
	if (frags->format == F_INVALID)
		return ;
	if (frags->format == F_CHAR)
		str = ft_conv_char((char)va_arg(*arg, int));
	else if (frags->format == F_STR)
		str = ft_conv_str(va_arg(*arg, char *));
	else if (frags->format == F_DEC || frags->format == F_INT)
		str = ft_conv_decimal(va_arg(*arg, int));
	else if (frags->format == F_UINT)
		str = ft_conv_unsigned(va_arg(*arg, unsigned int));
	else if (frags->format == F_PTR)
		str = ft_conv_pointer(va_arg(*arg, void *));
	else if (frags->format == F_HEX_LOW || frags->format == F_HEX_UP)
		str = ft_conv_hex(va_arg(*arg, unsigned int), frags->format);
	else if (frags->format == F_PCT)
		str = ft_my_strdup("%");

	frags->str = str;
	if (str)
		frags->str_count = ft_my_strlen(str);
	else
		frags->str_count = 0;
}
