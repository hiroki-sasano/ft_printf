/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_prefix_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 06:19:26 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/27 15:52:52 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"
#include <stdlib.h>

void ft_set_prefix(t_frags *frags)
{
    if (!frags->prefix)
        return;
    char *old = frags->str;
    size_t old_len = ft_my_strlen(old);
    size_t pre_len = ft_my_strlen(frags->prefix);
    // +1 バイト分の '\0' を含めて確保
    char *new = malloc(pre_len + old_len + 1);
    if (!new)
        return;
    // 先頭に prefix をコピー
    ft_memcpy(new, frags->prefix, pre_len);
    // 続けて元の文字列＋終端 '\0' をコピー
    ft_memcpy(new + pre_len, old, old_len + 1);
    free(old);
    frags->str = new;
}

// void	ft_set_prefix(t_frags *f)
// {
// 	f->prefix = NULL;

// 	if (f->format == F_DEC || f->format == F_INT)
// 	{
// 		if (f->str[0] == '-' || f->str[0] == '+')
// 		{
// 			f->prefix = ft_substr(f->str, 0, 1);
// 			if (f->prefix == NULL)
// 				return ;
// 			ft_memmove(f->str, f->str + 1, ft_my_strlen(f->str) + 1);
// 			f->str_count = ft_my_strlen(f->str);
// 		}
// 	}
// 	else if ((f->format == F_HEX_LOW || f->format == F_HEX_UP) && f->f_hash
// 		&& !(f->str_count == 1 && f->str[0] == '0'))
// 	{
// 		if (f->format == F_HEX_LOW)
// 			f->prefix = ft_my_strdup("0x");
// 		else
// 			f->prefix = ft_my_strdup("0X");
// 	}
// }
