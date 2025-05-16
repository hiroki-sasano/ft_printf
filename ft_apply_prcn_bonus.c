/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_prcn_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:08:25 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/16 18:13:14 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"
#include <stdlib.h>

void	ft_apply_prcn(t_frags *frags)
{
	char	*zero;
	char	*result;
	size_t	zero_count;

	if (!frags->str || frags->precision <= 0)
		return ;
	zero_count = frags->precision - ft_my_strlen(frags->str);
	if ((int)zero_count <= 0)
		return ;
	zero = (char *)malloc(sizeof(char) * (zero_count + 1));
	if (!zero)
		return ;
	ft_memset(zero, '0', zero_count);
	zero[frags->precision] = '\0';
	result = ft_strjoin(zero, frags->str);
	free(zero);
	if (!result)
		return ;
	free(frags->str);
	frags->str = ft_my_strdup(result);
	free(result);
	frags->str_count = ft_my_strlen(frags->str);
}
