/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left_align_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:04:44 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/18 00:48:20 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"
#include <stdlib.h>

void	ft_left_align(t_frags *frags)
{
	size_t	s_size;
	char	*temp;
	char	*result;

	s_size = 0;
	if (frags->width > frags->str_count)
		s_size = frags->width - frags->str_count;
	temp = (char *)malloc(sizeof(char) * (s_size + 1));
	if (!temp)
		return ;
	ft_memset(temp, ' ', s_size);
	temp[s_size] = '\0';
	result = ft_strjoin(frags->str, temp);
	free(temp);
	if (!result)
		return ;
	free(frags->str);
	frags->str = result;
	frags->str_count = ft_my_strlen(frags->str);
}
