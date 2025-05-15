/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:00:50 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/14 22:37:13 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*ft_conv_str(char *str)
{
	if (str == NULL)
		str = "(null)";
	return (ft_my_strdup(str));
}





