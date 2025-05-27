/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_basic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:40:46 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/27 15:59:52 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

static int	ft_handle_percent(t_frags *frags, va_list *arg, const char *format,
	size_t *i)
{
ssize_t	ret_size;

(*i)++;
if (format[*i] == '\0')
	return (-1);
ft_spec_type(frags, format[*i]);
ft_conv(frags, arg);
ret_size = ft_do_write(1, frags->str, frags->str_count);
if (ret_size == -1)
{
	free(frags->str);
	frags->str = NULL;
	return (-1);
}
free(frags->str);
frags->str = NULL;
(*i)++;
return (ret_size);
}

int	ft_printf_basic(va_list *arg, const char *format, t_frags *frags)
{
	size_t	i;
	ssize_t	ret_size;
	ssize_t	total_size;

	i = 0;
	total_size = 0;
	while (format[i])
	{
		ft_reset_format_spec(frags);
		if (format[i] == '%')
		{
			ret_size = ft_handle_percent(frags, arg, format, &i);
			if (ret_size == -1)
				return (-1);
			total_size += ret_size;
		}
		else
		{
			if (write(1, &format[i++], 1) == -1)
				return (-1);
			total_size++;
		}
	}
	return (total_size);
}
