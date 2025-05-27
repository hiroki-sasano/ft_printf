/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:58:27 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/27 17:01:11 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"
#include <unistd.h>

int	ft_printf_bonus(va_list *arg, const char *format, t_frags *frags)
{
	size_t	i;
	ssize_t	ret_size;
	ssize_t	total_size;

	i = 0;
	total_size = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			ret_size = ft_handle_format(frags, format, i, arg);
			if (ret_size == -1)
				return (-1);
			total_size += ret_size;
			i += frags->format_len;
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
