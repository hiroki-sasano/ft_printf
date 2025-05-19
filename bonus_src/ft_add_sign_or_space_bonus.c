/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_sign_or_space_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:10:03 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/18 02:02:50 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"
#include <stdlib.h>

void	ft_add_sign_or_space(t_frags *frags)
{
	char	*temp;
	char	*c;

	if (frags->f_plus)
		c = "+";
	else if (frags->f_space)
		c = " ";
	else
		return ;
	temp = ft_strjoin(c, frags->str);
	if (!temp)
		return (free(frags->str));
	free(frags->str);
	frags->str = temp;
	frags->str_count++;
}
