# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/09 17:34:47 by hisasano          #+#    #+#              #
#    Updated: 2025/05/15 20:45:59 by hisasano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = \
	ft_printf.c \
	ft_conv_char.c \
	ft_conv_str.c \
	ft_conv_decimal.c \
	ft_conv_unsigned.c \
	ft_conv_pointer.c \
	ft_conv_hex.c \
	ft_my_atoi.c \
	ft_reset_format_spec.c \
	ft_utoa.c \
	ft_utoa_base.c \
	ft_do_write.c \
	ft_is_spec.c \
	ft_spec_type.c \
	ft_conv.c \
	ft_printf_basic.c \
	ft_my_strdup.c \
	ft_my_strlen.c

BONUS_SRCS = ft_printf_bonus.c

HEADERS = ft_printf.h
CC := cc
CFLAGS := -Wall -Wextra -Werror

LIBFT_DIR := libft
LIBFT_A	  := $(LIBFT_DIR)/libft.a

ifeq ($(MAKECMDGOALS), bonus)
SRCS += $(BONUS_SRCS)
CFLAGS += -DBONUS_MODE
endif

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR) all    
	ar rcs $(NAME) $(OBJS)

bonus: $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
