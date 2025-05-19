/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_pad_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:04:11 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/18 13:06:33 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"
#include <stdlib.h>

static size_t	get_prefix_len(t_frags *f)
{
	if (f->f_hash && (f->format == F_HEX_LOW || f->format == F_HEX_UP)
		&& !(f->str_count == 1 && f->str[0] == '0'))
		return (2);
	return (0);
}

static char	*make_zeros(size_t pad_len)
{
	char	*z;

	z = malloc(pad_len + 1);
	if (!z)
		return (NULL);
	ft_memset(z, '0', pad_len);
	z[pad_len] = '\0';
	return (z);
}

static char	*join_pad(const char *old, const char *zeros, t_frags *f,
		size_t prefix_len)
{
	char const	*px;
	char		*tmp;
	char		*res;

	if (prefix_len == 0)
		return (ft_strjoin(zeros, old));
	if (f->format == F_HEX_UP)
		px = "0X";
	else
		px = "0x";
	tmp = ft_strjoin(px, zeros);
	if (!tmp)
		return (NULL);
	res = ft_strjoin(tmp, old);
	free(tmp);
	return (res);
}

void	ft_zero_pad(t_frags *frags)
{
	size_t	prefix;
	size_t	pad_len;
	char	*zeros;
	char	*newstr;

	prefix = get_prefix_len(frags);
	if (prefix == 2 && frags->str_count >= 2)
		frags->str_count -= 2;
	if (frags->width > frags->str_count + prefix)
		pad_len = frags->width - (frags->str_count + prefix);
	else
		pad_len = 0;
	if (pad_len == 0)
		return ;
	zeros = make_zeros(pad_len);
	if (!zeros)
		return ;
	newstr = join_pad(frags->str + prefix, zeros, frags, prefix);
	free(zeros);
	if (!newstr)
		return ;
	free(frags->str);
	frags->str = newstr;
	frags->str_count = ft_my_strlen(newstr);
}
