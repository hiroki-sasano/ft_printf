/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:43:13 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/27 16:07:17 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#ifdef BONUS_MODE
# include "ft_printf_bonus.h"
#endif

#ifdef BONUS_MODE

int	ft_printf_dispatch(va_list *arg, const char *format, t_frags *frags)
{
	return (ft_printf_bonus(arg, format, frags));
}

#else

int	ft_printf_dispatch(va_list *arg, const char *format, t_frags *frags)
{
	return (ft_printf_basic(arg, format, frags));
}
#endif

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		result;
	t_frags	frags;

	ft_memset(&frags, 0, sizeof(frags));
	ft_reset_format_spec(&frags);
	if (!format)
		return (0);
	va_start(arg, format);
	result = ft_printf_dispatch(&arg, format, &frags);
	va_end(arg);
	return (result);
}
