/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flagc_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:46:54 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/16 17:39:58 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

void	ft_set_flag(t_frags *frags, char c)
{
	if (c == '-')
		frags->f_minus = 1;
	else if (c == '0')
		frags->f_zero = 1;
	else if (c == '+')
		frags->f_plus = 1;
	else if (c == ' ')
		frags->f_space = 1;
	else if (c == '#')
		frags->f_hash = 1;
}
