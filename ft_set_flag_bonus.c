/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flag_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 23:34:52 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/15 23:34:59 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "ft_printf.h"

void	ft_set_flag_bonus(t_frags *frags, char c)
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