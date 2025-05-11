# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/09 17:34:47 by hisasano          #+#    #+#              #
#    Updated: 2025/05/10 01:08:10 by hisasano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c
BONUS_SRCS = ft_bonus.c

OBJS := $(SRCS:.c=.o)
BONUS_OBJS := $(BONUS_SRCS:.c=.o)

HEADERS = ft_printf.h
CC := cc
CFLAGS := -Wall -Wextra -Werror

LIBFT_DIR := libft
LIBFT_A	  := $(LIBFT_DIR)/libft.a

ifeq ($(MAKECMDGOALS), bonus)
SRCS += $(BONUS_SRCS)
CFLAGS += -DBONUS_MODE
endif

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR) all    
	ar rcs $(NAME) $(OBJS) $(LIBFT_A)

bonus: $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
