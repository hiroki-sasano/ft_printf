/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_width_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:52:10 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/27 20:22:15 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"
#include <stdlib.h>

static char	*make_space_pad(int pad_len)
{
	int		i;
	char	*pad;

	i = 0;
	pad = malloc(pad_len + 1);
	if (!pad)
		return (NULL);
	while (i < pad_len)
	{
		pad[i] = ' ';
		i++;
	}
	pad[pad_len] = '\0';
	return (pad);
}

static size_t	get_prefix_len(t_frags *f)
{
	if (f->prefix)
		return (ft_my_strlen(f->prefix));
	return (0);
}

void	ft_apply_width(t_frags *f)
{
	size_t	prefix_len;
	int		pad_len;
	char	*pad;

	if (f->format == F_PCT)
		return ;
	if (f->format == F_CHAR)
	{
		ft_apply_width_char(f);
		return ;
	}
	if (f->f_zero && !f->f_minus && !f->prec_on)
	{
		ft_zero_pad(f);
		return ;
	}
	prefix_len = get_prefix_len(f);
	pad_len = (int)f->width - ((int)f->str_count + (int)prefix_len);
	if (pad_len <= 0)
		return ;
	pad = make_space_pad(pad_len);
	if (!pad)
		return ;
	ft_app_width_lr(f, pad);
	free(pad);
}
