# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/09 17:34:47 by hisasano          #+#    #+#              #
#    Updated: 2025/05/21 19:53:55 by hisasano         ###   ########.fr        #
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

BONUS_SRCS = ft_printf_bonus.c \
ft_add_sign_or_space_bonus.c \
ft_parse_width_bonus.c \
ft_apply_prcn_bonus.c \
ft_left_align_bonus.c \
ft_zero_pad_bonus.c \
ft_hash_join_bonus.c \
ft_apply_width_bonus.c \
ft_apply_bonus.c \
ft_parse_prec_bonus.c \
ft_set_str_bonus.c \
ft_parse_format_bonus.c \
ft_set_flagc_bonus.c \
ft_conv_bonus.c \
ft_handle_format_bonus.c \
ft_printf_bonus.c 

OBJS = $(SRCS:.c=.o)   #srcが確定しない状態で展開　ng
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

HEADERS = ft_printf.h
CC := cc
CFLAGS := -Wall -Wextra -Werror

LIBFT_DIR := libft
LIBFT_A	  := $(LIBFT_DIR)/libft.a

#SRCS := $(MANDATORY_SRCS) 

ifeq ($(MAKECMDGOALS), bonus)
	SRCS += $(BONUS_SRCS)
	CFLAGS += -DBONUS_MODE
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) all    
	ar rcs $(NAME) $(OBJS)

bonus: $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

test:
	$(MAKE) re
	$(CC)               \
		main_basic.c      \
		$(NAME)           \
		$(LIBFT_A)        \
		-o test_mandatory

testbonus:
	$(MAKE) fclean
	$(MAKE) bonus
	$(CC)               \
		-DBONUS_MODE      \
		main_bonus.c      \
		$(NAME)           \
		$(LIBFT_A)        \
		-o test_bonus

.PHONY: all clean fclean re bonus test test_bonus
