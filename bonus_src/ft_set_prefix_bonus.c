/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_prefix_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 06:19:26 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/25 07:14:45 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

void	ft_set_prefix(t_frags *f)
{
	f->prefix = NULL;

	if (f->format == F_DEC || f->format == F_INT)
	{
		if (f->str[0] == '-' || f->str[0] == '+')
		{
			f->prefix = ft_substr(f->str, 0, 1);
			if (f->prefix == NULL)
				return ;
			ft_memmove(f->str, f->str + 1, ft_my_strlen(f->str) + 1);
			f->str_count = ft_my_strlen(f->str);
		}
	}
	else if ((f->format == F_HEX_LOW || f->format == F_HEX_UP) && f->f_hash
		&& !(f->str_count == 1 && f->str[0] == '0'))
	{
		if (f->format == F_HEX_LOW)
			f->prefix = ft_my_strdup("0x");
		else
			f->prefix = ft_my_strdup("0X");
	}
}
