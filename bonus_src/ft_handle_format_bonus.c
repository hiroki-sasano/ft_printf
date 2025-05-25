/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:40:07 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/25 10:20:45 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"
#include <stdlib.h>

static ssize_t	write_chunk(const char *s, size_t len)
{
	if (len == 0)
		return (0);
	return (ft_do_write(1, s, len));
}

static ssize_t	write_all(t_frags *f)
{
	size_t	lead;
	ssize_t	n;

	lead = 0;
	while (f->str[lead] == ' ')
		lead++;
	n = write_chunk(f->str, lead);
	if (n == -1)
		return (-1);
	if (f->prefix && write_chunk(f->prefix, ft_my_strlen(f->prefix)) == -1)
		return (-1);
	if (write_chunk(f->str + lead, f->str_count - lead) == -1)
		return (-1);
	return (n + (f->prefix ? ft_my_strlen(f->prefix) : 0)
		+ (f->str_count - lead));
}

static void	free_frags(t_frags *f)
{
	free(f->str);
	free(f->prefix);
	f->str = NULL;
	f->prefix = NULL;
}

ssize_t	ft_handle_format(const char *fmt, size_t i, va_list *ap, t_frags *f)
{
	ssize_t	total;

	(void)fmt;
	ft_reset_format_spec(f);
	ft_parse_format(f, fmt, i);
	ft_conv_bonus(f, ap);
	if (f->str == NULL)
		return (0);
	total = write_all(f);
	if (total == -1)
		return (free_frags(f), -1);
	free_frags(f);
	return (total);
}
