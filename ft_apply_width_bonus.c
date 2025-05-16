/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_width_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:52:10 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/16 18:13:46 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"
#include <stdlib.h>

void	ft_apply_width(t_frags *frags)
{
	size_t	len;
	size_t	padding_len;
	char	*padding;
	char	*temp;

	len = frags->str_count;
	if (frags->width <= len)
		return ;
	padding_len = frags->width - len;
	padding = (char *)malloc(padding_len + 1);
	if (!padding)
		return ;
	ft_memset(padding, ' ', padding_len);
	padding[padding_len] = '\0';
	temp = ft_strjoin(padding, frags->str);
	free(padding);
	free(frags->str);
	frags->str = temp;
	frags->str_count = ft_my_strlen(frags->str);
}
