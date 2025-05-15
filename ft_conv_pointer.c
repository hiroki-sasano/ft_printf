/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:19:44 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/14 15:39:10 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>
#include <stdlib.h>

char	*ft_conv_pointer(void *ptr)
{
	uintptr_t	addr;
	char		*hex;
	char		*result;

	if (!ptr)
		return (ft_my_strdup("0x0"));
	addr = (uintptr_t)ptr;
	hex = ft_utoa_base(addr, "0123456789abcdef");
	if (!hex)
		return (NULL);
	result = ft_strjoin("0x", hex);
	free(hex);
	return (result);
}
