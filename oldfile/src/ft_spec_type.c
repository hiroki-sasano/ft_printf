/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:31:54 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/17 23:44:17 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_spec_type(t_frags *frags, char type)
{
	if (type == 'c')
		frags->format = F_CHAR;
	else if (type == 's')
		frags->format = F_STR;
	else if (type == 'p')
		frags->format = F_PTR;
	else if (type == 'd')
		frags->format = F_DEC;
	else if (type == 'i')
		frags->format = F_INT;
	else if (type == 'u')
		frags->format = F_UINT;
	else if (type == 'x')
		frags->format = F_HEX_LOW;
	else if (type == 'X')
		frags->format = F_HEX_UP;
	else if (type == '%')
	{
		frags->format = F_PCT;
		frags->format_len = 1;
	}
	else
		frags->format = F_INVALID;
}
