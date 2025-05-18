/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:40:07 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/18 00:03:56 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"
#include <stdlib.h>

ssize_t	ft_handle_format(const char *format, size_t i, va_list *arg,
		t_frags *frags)
{
	ssize_t	ret;

	ft_reset_format_spec(frags);
	ft_parse_format(frags, format, i);
	ft_conv_bonus(frags, arg);
	if (!frags->str)
		return (0);
	ret = ft_do_write(1, frags->str, frags->str_count);
	free(frags->str);
	frags->str = NULL;
	if (ret == -1)
		return (-1);
	return (ret);
}
