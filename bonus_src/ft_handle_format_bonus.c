/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:40:07 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/27 18:42:18 by hisasano         ###   ########.fr       */
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
	if (f->prefix)
		return (n + ft_my_strlen(f->prefix) + (f->str_count - lead));
	else
		return (n + (f->str_count - lead));
}

static void	free_frags(t_frags *f)
{
	free(f->str);
	free(f->prefix);
	f->str = NULL;
	f->prefix = NULL;
}

static void	ft_set_prefix(t_frags *f)
{
	char	*tmp;

	if ((f->format == F_DEC || f->format == F_INT) && f->str
		&& (f->str[0] == '-' || f->str[0] == '+'))
	{
		if (f->str[0] == '-')
			f->prefix = ft_my_strdup("-");
		else
			f->prefix = ft_my_strdup("+");
		tmp = ft_my_strdup(f->str + 1);
		free(f->str);
		f->str = tmp;
		f->str_count = ft_my_strlen(f->str);
	}
}

ssize_t	ft_handle_format(t_frags *f, const char *fmt, size_t i, va_list *ap)
{
	ssize_t	total;

	(void)fmt;
	ft_reset_format_spec(f);
	ft_parse_format(f, fmt, i);
	ft_conv_bonus(f, ap);
	if (f->str == NULL)
		return (0);
	ft_set_prefix(f);
	ft_hash_join(f);
	ft_add_sign_or_space(f);
	if (f->format == F_CHAR)
		f->str_count = 1;
	ft_apply_prcn(f);
	ft_apply_width(f);
	total = write_all(f);
	if (total == -1)
		return (free_frags(f), -1);
	free_frags(f);
	return (total);
}
