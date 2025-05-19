/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:58:23 by hisasano          #+#    #+#             */
/*   Updated: 2025/05/16 20:08:40 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "ft_printf.h"

void	ft_add_sign_or_space(t_frags *frags);
size_t	ft_parse_width(t_frags *frags, const char *format, size_t start);
void	ft_apply_prcn(t_frags *frags);
void	ft_left_align(t_frags *frags);
void	ft_zero_pad(t_frags *frags);
void	ft_hash_join(t_frags *frags);
void	ft_apply_width(t_frags *frags);
void	ft_apply(t_frags *frags);
size_t	ft_parse_prec(t_frags *frags, const char *format, size_t start);
void	ft_set_str(t_frags *frags, const char *format, size_t start);
void	ft_parse_format(t_frags *frags, const char *format, size_t start);
void	ft_set_flag(t_frags *frags, char c);
void	ft_conv_bonus(t_frags *frags, va_list *arg);
ssize_t	ft_handle_format(const char *format, size_t i, va_list *arg,
			t_frags *frags);
int		ft_printf_bonus(va_list *arg, const char *format, t_frags *frags);

#endif