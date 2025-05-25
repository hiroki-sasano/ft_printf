/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_str_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 23:35:07 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/25 10:57:23 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"
#include <stdlib.h>

void	ft_set_str(t_frags *f, const char *fmt, size_t start)
{
	size_t	i;
	size_t	j;
	size_t	alloc;
	char	*dst;

	alloc = f->format_len + 1;
	if (f->f_add0)
		alloc += 1;
	dst = malloc(alloc);
	if (dst == NULL)
		return ;
	i = 0;
	j = 0;
	while (i < f->format_len && fmt[start + i])
	{
		dst[j++] = fmt[start + i];
		if (f->f_add0 && fmt[start + i] == '.')
			dst[j++] = '0';
		i++;
	}
	dst[j] = '\0';
	free(f->str);
	f->str = dst;
	f->str_count = j;
	f->f_add0 = 0;
}
