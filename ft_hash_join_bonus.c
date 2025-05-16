/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_join_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:53:22 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/16 18:24:58 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"
#include <stdlib.h>

void	ft_hash_join(t_frags *frags)
{
	char	*temp;

	if (frags->format == F_HEX_LOW)
		temp = ft_strjoin("0x", frags->str);
	else if (frags->format == F_HEX_UP)
		temp = ft_strjoin("0X", frags->str);
	else
		return ;
	if (!temp)
		return ;
	free(frags->str);
	frags->str = temp;
	frags->str_count = ft_my_strlen(frags->str);
}
