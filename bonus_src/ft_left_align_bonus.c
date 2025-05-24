/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left_align_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:04:44 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/25 07:42:35 by hisasano         ###   ########.fr       */
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

static char	*create_spaces(size_t len)
{
	char	*s;

	s = malloc(len + 1);
	if (s == NULL)
		return (NULL);
	ft_memset(s, ' ', len);
	s[len] = '\0';
	return (s);
}

static int	append_pad(t_frags *f, char *pad)
{
	char	*joined;

	joined = ft_my_strjoin(f->str, pad);
	free(pad);
	if (joined == NULL)
		return (0);
	free(f->str);
	f->str = joined;
	return (1);
}

/* ========================  public interface  ============================= */

void	ft_left_align(t_frags *f)
{
	size_t	prefix_len;
	size_t	pad_len;
	char	*pad;

	if (f->str == NULL)
		return ;
	prefix_len = (f->prefix != NULL) ? ft_my_strlen(f->prefix) : 0;
	pad_len = get_pad_len(f, prefix_len);
	if (pad_len == 0)
		return ;
	pad = create_spaces(pad_len);
	if (pad == NULL)
		return ;
	if (!append_pad(f, pad))
		return ;
	f->str_count += pad_len;
}