/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:34:20 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/14 23:08:53 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_conv(t_frags *frags, va_list *arg)
{
	char	*str;

	str = NULL;
	if (frags->format == F_CHAR)
		str = ft_conv_char((char)va_arg(*arg, int));
	else if (frags->format == F_STR)
		str = ft_conv_str(va_arg(*arg, char *));
	else if (frags->format == F_DEC || frags->format == F_INT)
		str = ft_conv_decimal(va_arg(*arg, int));
	else if (frags->format == F_UINT)
		str = ft_conv_unsigned(va_arg(*arg, unsigned int));
	else if (frags->format == F_PTR)
		str = ft_conv_pointer(va_arg(*arg, void *));
	else if (frags->format == F_HEX_LOW || frags->format == F_HEX_UP)
		str = ft_conv_hex(va_arg(*arg, unsigned int), frags->format);
	else if (frags->format == F_PCT)
		str = ft_my_strdup("%");
	else if (frags->format == F_INVALID)
		str = NULL;
	frags->str = str;
	if (str)
		frags->str_count = ft_my_strlen(str);
	else
		frags->str_count = 0;
}


// #include "ft_printf.h"
// #include <stdio.h>  // sprintf
// #include <string.h> // strlen
// #include <unistd.h> // write

// void	ft_conv(t_frags *frags, va_list *arg)
// {
// 	char	*str = NULL;
// 	char	log[100];

// 	sprintf(log, "DEBUG: ft_conv format = %d\n", frags->format);
// 	write(2, log, strlen(log));

// 	if (frags->format == F_CHAR)
// 	{
// 		int c = va_arg(*arg, int);
// 		sprintf(log, "DEBUG: CHAR = %c (%d)\n", c, c);
// 		write(2, log, strlen(log));
// 		str = ft_conv_char((char)c);
// 	}
// 	else if (frags->format == F_STR)
// 	{
// 		char *s = va_arg(*arg, char *);
// 		sprintf(log, "DEBUG: STR PTR = %p\n", (void *)s);
// 		write(2, log, strlen(log));
// 		str = ft_conv_str(s);
// 	}
// 	else if (frags->format == F_PTR)
// 	{
// 		void *p = va_arg(*arg, void *);
// 		sprintf(log, "DEBUG: PTR = %p\n", p);
// 		write(2, log, strlen(log));
// 		str = ft_conv_pointer(p);
// 	}
// 	else if (frags->format == F_DEC)
// 	{
// 		int n = va_arg(*arg, int);
// 		sprintf(log, "DEBUG: DEC = %d\n", n);
// 		write(2, log, strlen(log));
// 		str = ft_conv_decimal(n);
// 	}
// 	else if (frags->format == F_INT)
// 	{
// 		int i = va_arg(*arg, int);
// 		sprintf(log, "DEBUG: INT = %d\n", i);
// 		write(2, log, strlen(log));
// 		str = ft_conv_decimal(i);
// 	}
// 	else if (frags->format == F_UINT)
// 	{
// 		unsigned int u = va_arg(*arg, unsigned int);
// 		sprintf(log, "DEBUG: UINT = %u\n", u);
// 		write(2, log, strlen(log));
// 		str = ft_conv_unsigned(u);
// 	}
// 	else if (frags->format == F_HEX_LOW || frags->format == F_HEX_UP)
// 	{
// 		unsigned int x = va_arg(*arg, unsigned int);
// 		sprintf(log, "DEBUG: HEX = %u\n", x);
// 		write(2, log, strlen(log));
// 		str = ft_conv_hex(x, frags->format);
// 	}
// 	else if (frags->format == F_PCT)
// 	{
// 		write(2, "DEBUG: PERCENT %% detected\n", 27);
// 		str = ft_my_strdup("%");
// 	}

// 	frags->str = str;
// 	if (str)
// 		frags->str_count = ft_my_strlen(str);
// 	else
// 	{
// 		frags->str_count = 0;
// 		write(2, "DEBUG: ft_conv got NULL result\n", 31);
// 	}
// }
