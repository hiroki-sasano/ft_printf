/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_num_zeropad_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:49:00 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/27 19:53:57 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"
#include <stdlib.h>

static char	*make_zero_str(size_t len)
{
	char	*s;

	s = ft_calloc(len + 1, 1);
	if (!s)
		return (NULL);
	ft_memset(s, '0', len);
	return (s);
}

void	ft_app_num_zeropad(t_frags *f)
{
	size_t	zero_len;
	char	*zeros;
	char	*joined;

	if (f->format == F_STR || f->format == F_CHAR || f->precision <= 0
		|| (size_t)f->precision <= f->str_count)
		return ;
	zero_len = f->precision - f->str_count;
	zeros = make_zero_str(zero_len);
	if (!zeros)
		return ;
	joined = ft_my_strjoin(zeros, f->str);
	free(zeros);
	if (!joined)
		return ;
	free(f->str);
	f->str = joined;
	f->str_count = f->precision;
}
