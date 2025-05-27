/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_width_lr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:18:05 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/27 19:23:19 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"
#include <stdlib.h>

static void	apply_width_left(t_frags *f, char *pad)
{
	char	*joined;

	joined = ft_my_strjoin(f->str, pad);
	if (!joined)
		return ;
	free(f->str);
	f->str = joined;
	f->str_count += ft_my_strlen(pad);
}

static void	apply_width_right(t_frags *f, char *pad)
{
	char	*joined;

	joined = ft_my_strjoin(pad, f->str);
	if (!joined)
		return ;
	free(f->str);
	f->str = joined;
	f->str_count += ft_my_strlen(pad);
}

void	ft_app_width_lr(t_frags *f, char *pad)
{
	if (f->f_minus)
		apply_width_left(f, pad);
	else
		apply_width_right(f, pad);
	return ;
}
