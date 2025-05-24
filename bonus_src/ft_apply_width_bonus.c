/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_width_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:52:10 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/25 06:40:08 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"
#include <stdlib.h>

void	ft_apply_width(t_frags *frags)
{
	size_t	pad;
	char	*pad_str;
	char	*tmp;

	if (!frags->str)
		return ;
	if (frags->width > frags->str_count)
		pad = frags->width - frags->str_count;
	else
		pad = 0;
	if (pad == 0)
		return ;
	pad_str = malloc(pad + 1);
	if (!pad_str)
		return ;
	ft_memset(pad_str, ' ', pad);
	pad_str[pad] = '\0';
	if (frags->f_minus)
		tmp = ft_my_strjoin(frags->str, pad_str);
	else
		tmp = ft_my_strjoin(pad_str, frags->str);
	free(pad_str);
	if (!tmp)
		return;
	free(frags->str);
	frags->str = tmp;
	frags->str_count = ft_my_strlen(tmp);
}
