/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_join_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:53:22 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/25 07:51:40 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

void	ft_hash_join(t_frags *f)
{
	if (!f->f_hash || f->prefix != NULL)
		return ;
	if ((f->str_count == 1 && f->str[0] == '0') || f->str_count == 0)
		return ;
	if (f->format == F_HEX_LOW)
		f->prefix = ft_my_strdup("0x");
	else if (f->format == F_HEX_UP)
		f->prefix = ft_my_strdup("0X");
}
