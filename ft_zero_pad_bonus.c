/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_pad_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:04:11 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/16 20:47:09 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"
#include <stdlib.h>

void	ft_zero_pad(t_frags *frags)
{
	size_t	s_size;
	char	*temp;
	char	*result;

	if (frags->width > ft_my_strlen(frags->str))
		s_size = frags->width - ft_my_strlen(frags->str);
	else
		return ;
	temp = (char *)malloc(sizeof(char) * (s_size + 1));
	if (!temp)
		return ;
	ft_memset(temp, '0', s_size);
	temp[s_size] = '\0';
	result = ft_strjoin(temp, frags->str);
	free(temp);
	if (!result)
		return ;
	free(frags->str);
	frags->str = result;
	frags->str_count = ft_my_strlen(frags->str);
}
