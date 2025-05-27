/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:15:56 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/14 12:12:45 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*ft_utoa_base(uintptr_t n, const char *base)
{
	char		*str;
	size_t		base_len;
	size_t		len;
	uintptr_t	tmp;

	base_len = 0;
	while (base[base_len])
		base_len++;
	len = 1;
	tmp = n;
	while (tmp >= base_len)
	{
		tmp /= base_len;
		len++;
	}
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = base[n % base_len];
		n /= base_len;
	}
	return (str);
}
