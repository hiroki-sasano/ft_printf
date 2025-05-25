/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_width_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:52:10 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/25 11:09:03 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"
#include <stdlib.h>

static char	*make_pad(size_t len)
{
	char	*pad;

	pad = malloc(len + 1);
	if (pad == NULL)
		return (NULL);
	ft_memset(pad, ' ', len);
	pad[len] = '\0';
	return (pad);
}

void	ft_apply_width(t_frags *f)
{
	size_t	prefix_len, pad_len;
	char	*pad, *joined;

	if (!f->str || (f->format == F_CHAR && f->str[0] == '\0'))
		return ;
	prefix_len = 0;
	if (f->prefix)
		prefix_len = ft_my_strlen(f->prefix);
	if (f->width <= f->str_count + prefix_len)
		return ;
	pad_len = f->width - (f->str_count + prefix_len);
	if (!(pad = make_pad(pad_len)))
		return ;
	if (f->f_minus)
		joined = ft_my_strjoin(f->str, pad);
	else
		joined = ft_my_strjoin(pad, f->str);
	free(pad);
	if (!joined)
		return ;
	free(f->str);
	f->str = joined;
	f->str_count += pad_len;
}
