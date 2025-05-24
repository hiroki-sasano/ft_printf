/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:40:07 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/25 07:27:18 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"
#include <stdlib.h>

ssize_t	ft_handle_format(const char *fmt, size_t i, va_list *ap, t_frags *f)
{
	ssize_t	written;
	ssize_t	ret;

	ft_reset_format_spec(f);
	ft_parse_format(f, fmt, i);
	ft_conv_bonus(f, ap);
	if (f->str == NULL)
		return (0);
	written = 0;
	if (f->prefix)
	{
		ret = ft_do_write(1, f->prefix, ft_my_strlen(f->prefix));
		if (ret == -1)
			return (-1);
		written += ret;
	}
	ret = ft_do_write(1, f->str, f->str_count);
	if (ret == -1)
		return (-1);
	written += ret;
	free(f->str);
	f->str = NULL;
	if (f->prefix)
	{
		free(f->prefix);
		f->prefix = NULL;
	}
	return (written);
}
