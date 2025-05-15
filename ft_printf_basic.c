/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_basic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:40:46 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/14 22:44:20 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

// static int	ft_handle_percent(t_frags *frags, va_list arg,
		// const char *format, size_t *i)
// {
// 	ssize_t	ret_size;

// 	if (format[*i + 1] == '%')  // ← 連続 %% を検出
// 	{
// 		frags->format = F_PCT;
// 		ft_conv(frags, arg);
// 		ret_size = ft_do_write(1, frags->str, frags->str_count);
// 		if (ret_size == -1)
// 			return (-1);
// 		(*i) += 2;  // ← 2文字消費（%%）
// 		return (ret_size);
// 	}
// 	// 通常の %x %s %d など
// 	(*i)++;
// 	if (format[*i] == '\0')
// 		return (-1);
// 	ft_spec_type(frags, format[*i]);
// 	ft_conv(frags, arg);
// 	ret_size = ft_do_write(1, frags->str, frags->str_count);
// 	if (ret_size == -1)
// 		return (-1);
// 	(*i)++;
// 	return (ret_size);
// }

static int	ft_handle_percent(t_frags *frags, va_list *arg, const char *format,
		size_t *i)
{
	ssize_t	ret_size;

	(*i)++;
	if (format[*i] == '\0')
		return (-1);
	write(2, "ft_handle_percent: type = ", 27);
	write(2, &format[*i], 1);
	write(2, "\n", 1);
	ft_spec_type(frags, format[*i]);
	ft_conv(frags, arg);
	ret_size = ft_do_write(1, frags->str, frags->str_count);
	if (ret_size == -1)
		return (-1);
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

// int	ft_printf_basic(va_list arg, const char *format, t_frags *frags)
// {
// 	size_t	i;
// 	ssize_t	ret_size;
// 	ssize_t	total_size;

// 	write(2, "FULL FORMAT STRING:\n", 21);
// 	write(2, format, ft_strlen(format));
// 	write(2, "\n", 1);

// 	i = 0;
// 	total_size = 0;
// 	while (format[i])
// 	{
// 		ft_reset_format_spec(frags);
// 		// %% の場合（リテラルの %）
// 		if (format[i] == '%' && format[i + 1] == '%')
// 		{
// 			if (write(1, "%", 1) == -1)
// 				return (-1);
// 			i += 2;
// 			total_size++;
// 			continue ;
// 		}
// 		// 通常の変換指定子
// 		if (format[i] == '%')
// 		{
// 			ret_size = ft_handle_percent(frags, arg, format, &i);
// 			if (ret_size == -1)
// 				return (-1);
// 			total_size += ret_size;
// 			continue ;
// 		}
// 		// 通常文字
// 		if (write(1, &format[i++], 1) == -1)
// 			return (-1);
// 		total_size++;
// 	}
// 	return (total_size);
// }
