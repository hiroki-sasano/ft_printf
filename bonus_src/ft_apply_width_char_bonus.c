/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_width_char_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:07:44 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/27 18:35:58 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"
#include <stdlib.h>

static void	write_char_left(char *buf, char c, int pad)
{
	int	i;

	i = 0;
	buf[0] = c;
	while (i < pad)
	{
		buf[1 + i] = ' ';
		i++;
	}
}

static void	write_char_right(char *buf, char c, int pad)
{
	int	i;

	i = 0;
	while (i < pad)
	{
		buf[i] = ' ';
		i++;
	}
	buf[pad] = c;
}

void	ft_apply_width_char(t_frags *f)
{
	int		total;
	int		pad;
	char	*buf;

	if (f->width > 1)
		total = f->width;
	else
		total = 1;
	pad = total - 1;
	buf = malloc(total + 1);
	if (!buf)
		return ;
	if (f->f_minus)
		write_char_left(buf, f->str[0], pad);
	else
		write_char_right(buf, f->str[0], pad);
	buf[total] = '\0';
	free(f->str);
	f->str = buf;
	f->str_count = total;
}
