/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_sign_or_space_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:10:03 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/27 19:52:09 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

void	ft_add_sign_or_space(t_frags *f)
{
	if (!(f->format == F_DEC || f->format == F_INT))
		return ;
	if (f->str[0] == '-')
		return ;
	if (f->prefix != NULL)
		return ;
	if (f->f_plus)
		f->prefix = ft_my_strdup("+");
	else if (f->f_space)
		f->prefix = ft_my_strdup(" ");
}
