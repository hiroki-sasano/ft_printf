/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_str_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 23:35:07 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/16 01:07:15 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "ft_printf.h"
#include <stdlib.h>

void	ft_set_str_bonus(t_frags *frags, const char *format, size_t start)
{
	size_t	i;
	char	*temp;

	temp = (char *)malloc(sizeof(char) * (frags->format_len + 1));
	if (!temp)
		return ;
	i = 0;
	while (i < frags->format_len)
	{
		temp[i] = format[start + i];
		i++;
	}
	temp[i] = '\0';
	if (frags->str)
		free(frags->str);
	frags->str = temp;
	frags->str_count = ft_my_strlen(frags->str);
}