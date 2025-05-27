/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_pad_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:04:11 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/25 08:50:56 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"
#include <stdlib.h>

static size_t	get_pad_len(t_frags *f, size_t px_len)
{
	if (f->width > f->str_count + px_len)
		return (f->width - (f->str_count + px_len));
	return (0);
}

static char	*create_zeros(size_t len)
{
	char	*z;

	z = malloc(len + 1);
	if (z == NULL)
		return (NULL);
	ft_memset(z, '0', len);
	z[len] = '\0';
	return (z);
}

static int	join_zeros(t_frags *f, char *zeros)
{
	char	*joined;

	joined = ft_my_strjoin(zeros, f->str);
	free(zeros);
	if (joined == NULL)
		return (0);
	free(f->str);
	f->str = joined;
	return (1);
}

void	ft_zero_pad(t_frags *f)
{
	size_t	prefix_len;
	size_t	pad_len;
	char	*zeros;

	if (!(f->format == F_DEC || f->format == F_INT
		|| f->format == F_UINT || f->format == F_HEX_LOW
		|| f->format == F_HEX_UP || f->format == F_PTR))
		 return ;
	if (f->str == NULL)
		return ;
	prefix_len = 0;
	if (f->prefix != NULL)
		prefix_len = ft_my_strlen(f->prefix);
	pad_len = get_pad_len(f, prefix_len);
	if (pad_len == 0)
		return ;
	zeros = create_zeros(pad_len);
	if (zeros == NULL)
		return ;
	if (!join_zeros(f, zeros))
		return ;
	f->str_count += pad_len;
}
