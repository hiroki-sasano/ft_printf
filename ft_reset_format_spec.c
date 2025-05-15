/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_format_spec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:56:03 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/14 14:31:46 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	ft_reset_format_spec(t_frags *frags)
{
	frags->f_minus = 0;
	frags->f_zero = 0;
	frags->f_plus = 0;
	frags->f_spase = 0;
	frags->f_hash = 0;
	frags->width = 0;
	frags->precision = 0;
	if (frags->str != NULL)
		free(frags->str);
	frags->str = NULL;
	frags->str_count = 0;
	return ;
}
