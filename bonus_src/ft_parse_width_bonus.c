/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:09:23 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/16 18:12:59 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"
#include <stdlib.h>

size_t	ft_parse_width(t_frags *frags, const char *format, size_t start)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	while (ft_isdigit(format[start + i]))
		i++;
	if (i == 0)
		return (0);
	temp = (char *)malloc(sizeof(char) * (i + 1));
	if (!temp)
		return (0);
	j = 0;
	while (j < i)
	{
		temp[j] = format[start + j];
		j++;
	}
	temp[j] = '\0';
	frags->width = ft_my_atoi(temp);
	free(temp);
	return (i);
}
