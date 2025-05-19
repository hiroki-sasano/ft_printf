/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:52:57 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/14 13:58:41 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static int	ft_parse_digits(const char *str, int *i, int sign, int *overflow)
{
	int	result;

	result = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		if (result > INT_MAX / 10 || (result == INT_MAX / 10 && ((!sign
						&& (str[*i] - '0') > 7) || (sign && (str[*i]
							- '0') > 8))))
		{
			*overflow = 1;
			if (sign)
				return (INT_MIN);
			return (INT_MAX);
		}
		result = result * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (result);
}

int	ft_my_atoi(const char *str)
{
	int		i;
	int		result;
	int		sign;
	int		overflow;

	i = 0;
	result = 0;
	sign = 0;
	overflow = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = 1;
		i++;
	}
	result = ft_parse_digits(str, &i, sign, &overflow);
	if (overflow)
		return (result);
	if (sign)
		return (-result);
	return (result);
}
