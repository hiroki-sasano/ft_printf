/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:58:27 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/15 20:38:52 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"
#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>

size_t	ft_parse_width(t_frags *frags, const char *format, size_t start)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	while (ft_isdigit(format[start + i]))
		i++;
	if (i == 0)
		return (0);
	temp = (char *)malloc(sizeof(char) * (i + 1));
	if (!temp)
		return (0);
	j = 0;
	while (j < i)
	{
		temp[j] = format[start + j];
		j++;
	}
	temp[j] = '\0';
	frags->width = ft_my_atoi(temp);
	free(temp);
	return (i);
}

void	ft_apply_prcn(t_frags *frags)
{
	char	*zero;
	char	*result;
	size_t	zero_count;

	if (!frags->str || frags->precision <= 0)
		return ;
	zero_count = frags->precision - ft_my_strlen(frags->str);
	if ((int)zero_count <= 0)
		return ;
	zero = (char *)malloc(sizeof(char) * (zero_count + 1));
	if (!zero)
		return ;
	ft_memset(zero, '0', zero_count);
	zero[frags->precision] = '\0';
	result = ft_strjoin(zero, frags->str);
	free(zero);
	if (!result)
		return ;
	free(frags->str);
	frags->str = ft_my_strdup(result);
	free(result);
	frags->str_count = ft_my_strlen(frags->str);
}

void	ft_left_align(t_frags *frags)
{
	size_t	s_size;
	char	*temp;
	char	*result;

	s_size = 0;
	if (frags->precision)
		ft_apply_prcn(frags);
	if (frags->f_plus || frags->f_space)
		ft_add_sign_or_space(frags);
	if (frags->width > ft_my_strlen(frags->str))
		s_size = frags->width - ft_my_strlen(frags->str);
	temp = (char *)malloc(sizeof(char) * (s_size + 1));
	if (!temp)
		return ;
	ft_memset(temp, ' ', s_size);
	temp[s_size] = '\0';
	;
	result = ft_strjoin(frags->str, temp);
	free(temp);
	if (!result)
		return ;
	free(frags->str);
	frags->str = result;
	frags->str_count = ft_my_strlen(frags->str);
}

void	ft_zero_pad(t_frags *frags)
{
	size_t	s_size;
	char	*temp;
	char	*result;

	if (frags->width > ft_my_strlen(frags->str))
		s_size = frags->width - ft_my_strlen(frags->str);
	else
		return ;
	temp = (char *)malloc(sizeof(char) * (s_size + 1));
	if (!temp)
		return ;
	ft_memset(temp, '0', s_size);
	temp[s_size] = '\0';
	;
	result = ft_strjoin(temp, frags->str);
	free(temp);
	if (!result)
		return ;
	free(frags->str);
	frags->str = result;
	frags->str_count = ft_my_strlen(frags->str);
}

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
	frags->str = ft_my_strdup(temp);
	free(temp);
}

void	ft_hash_join(t_frags *frags)
{
	char	*temp;

	if (frags->format == F_HEX_LOW)
		temp = ft_strjoin("0x", frags->str);
	else if (frags->format == F_HEX_UP)
		temp = ft_strjoin("0X", frags->str);
	else
		return ;
	if (!temp)
		return ;
	free(frags->str);
	frags->str = temp;
	frags->str_count = ft_strlen(frags->str);
}

void	ft_apply_width(t_frags *frags)
{
	size_t	len;
	size_t	padding_len;
	char	*padding;
	char	*temp;

	len = frags->str_count;
	if (frags->width <= len)
		return ;
	padding_len = frags->width - len;
	padding = (char *)malloc(padding_len + 1);
	if (!padding)
		return ;
	ft_memset(padding, ' ', padding_len);
	padding[padding_len] = '\0';
	temp = ft_strjoin(padding, frags->str);
	free(padding);
	free(frags->str);
	frags->str = temp;
	frags->str_count = frags->width;
}

void	ft_apply(t_frags *frags)
{
	if (frags->format == F_INVALID)
		return;
	if (frags->precision && (frags->format == F_DEC || frags->format == F_INT
			|| frags->format == F_UINT || frags->format == F_HEX_LOW
			|| frags->format == F_HEX_UP))
		ft_apply_prcn(frags);
	if (frags->f_plus && (frags->format == F_DEC || frags->format == F_INT))
		ft_add_sign_or_space(frags);
	else if (frags->f_space && (frags->format == F_DEC
			|| frags->format == F_INT))
		ft_add_sign_or_space(frags);
	if (frags->f_hash && (frags->format == F_HEX_LOW
			|| frags->format == F_HEX_UP))
		ft_hash_join(frags);
	if (frags->f_zero && !frags->f_minus && !frags->precision)
		ft_zero_pad(frags);
	if (frags->width && !frags->f_minus && !frags->f_zero)
		ft_apply_width(frags);
	if (frags->f_minus)
		ft_left_align(frags);
}

size_t	ft_parse_prec(t_frags *frags, const char *format, size_t start)
{
	size_t	i;

	if (!ft_isdigit(format[start + 1]))
	{
		frags->precision = 0;
		return (1); 
	}

	frags->precision = ft_my_atoi(&format[start + 1]);

	i = 1;
	while (ft_isdigit(format[start + i]))
		i++;

	return (i);
}


// size_t	ft_parse_prec(t_frags *frags, const char *format, size_t start)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*temp;

// 	i = 1;
// 	j = 0;
// 	if (!ft_isdigit(format[start + 1]))
// 	{
// 		frags->precision = 0;
// 		return (1); 
// 	}
// 	while (ft_isdigit(format[start + i]))
// 		i++;
// 	temp = malloc(sizeof(char) * (i + 1));
// 	if (!temp)
// 		return (0);
// 	while (j < i - 1)
// 	{
// 		temp[j] = format[start + j + 1];
// 		j++;
// 	}
// 	temp[j] = '\0';
// 	frags->precision = ft_my_atoi(temp);
// 	free(temp);
// 	return (i);
// }

void	ft_set_str(t_frags *frags, const char *format, size_t start)
{
	size_t	i;
	char	*temp;

	temp = (char *)malloc(sizeof(char) * (frags->format_len + 1));
	if (!temp)
		return ;
	i = 0;
	while (i < frags->format_len && format[start + i])
	{
		temp[i] = format[start + i];
		i++;
	}
	temp[i] = '\0';
	if (frags->str)
		free(frags->str);
	frags->str = temp;
	frags->str_count = i;
}

// start == %
void	ft_parse_format(t_frags *frags, const char *format, size_t start)
{
	size_t	i;
	char	c;

	i = 1;
	while (format[start + i] && !ft_is_spec(format[start + i]))
	{
		c = format[start + i];
		ft_set_flag(frags, c);
		if (frags->precision == 0 && ft_isdigit(c))
			i += ft_parse_width(frags, format, start + i) - 1;
		else if (c == '.')
			i += ft_parse_prec(frags, format, start + i) - 1;
		else if (ft_is_spec(c))
		{
			ft_spec_type(frags, c);
			i++;
			break ;
		}
		i++;
	}
	if (frags->format == F_NONE)
		frags->format = F_INVALID;
	frags->format_len = i + 1; 
	if (frags->format == F_INVALID)
		ft_set_str(frags, format, start);
}

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

void	ft_conv_bonus(t_frags *frags, va_list *arg)
{
	char	*str;

	str = NULL;
	if (frags->format == F_INVALID)
		return; 
	if (frags->format == F_CHAR)
		str = ft_conv_char((char)va_arg(*arg, int));
	else if (frags->format == F_STR)
		str = ft_conv_str(va_arg(*arg, char *));
	else if (frags->format == F_DEC)
		str = ft_conv_decimal(va_arg(*arg, int));
	else if (frags->format == F_UINT)
		str = ft_conv_unsigned(va_arg(*arg, unsigned int));
	else if (frags->format == F_PTR)
		str = ft_conv_pointer(va_arg(*arg, void *));
	else if (frags->format == F_HEX_LOW || frags->format == F_HEX_UP)
		str = ft_conv_hex(va_arg(*arg, unsigned int), frags->format);
	else if (frags->format == F_PCT)
		str = ft_my_strdup("%");
	if (str)
		frags->str = str;
	ft_apply(frags);
}

ssize_t	ft_handle_format_bonus(const char *format, size_t i, va_list *arg,
		t_frags *frags)
{
	ssize_t	ret;

	ft_reset_format_spec(frags);
	ft_parse_format(frags, format, i);
	ft_conv_bonus(frags, arg);

	if (!frags->str)
	return (0);

	ret = ft_do_write(1, frags->str, frags->str_count);
	free(frags->str);
	frags->str = NULL;
	if (ret == -1)
		return (-1);
	return (ret);
}

#include <stdarg.h>
#include <unistd.h>

int	ft_printf_bonus(va_list *arg, const char *format, t_frags *frags)
{
	size_t	i;
	ssize_t	ret_size;
	ssize_t	total_size;

	i = 0;
	total_size = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			ret_size = ft_handle_format_bonus(format, i, arg, frags);
			if (ret_size == -1)
				return (-1);
			total_size += ret_size;
			i += frags->format_len;
		}
		else
		{
			if (write(1, &format[i++], 1) == -1)
				return (-1);
			total_size++;
		}
	}
	return (total_size);
}
