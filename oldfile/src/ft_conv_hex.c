/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:21:18 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/14 14:22:31 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_hex(unsigned int value, t_argtype type)
{
	char	*hex;

	if (type == F_HEX_LOW)
		hex = ft_utoa_base(value, "0123456789abcdef");
	else
		hex = ft_utoa_base(value, "0123456789ABCDEF");
	if (!hex)
		return (NULL);
	return (hex);
}
