# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/09 17:34:47 by hisasano          #+#    #+#              #
#    Updated: 2025/05/19 19:56:22 by hisasano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

SRCFILES := \
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

BONUS_SRCFILES := \
ft_printf_bonus.c \
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
ft_handle_format_bonus.c 

SRCDIR        := src
BONUS_SRCDIR  := bonus_src
OBJDIR        := obj
INCDIR        := include
LIBFTDIR      := libft
AR_TMP        := ar_tmp

CC      := cc
CFLAGS  = -Wall -Wextra -Werror $(addprefix -I, $(INCLUDES))
AR      := ar
ARFLAGS := rcs
RM      := rm -f
RMDIR   := rm -rf

INCLUDES := $(INCDIR) $(LIBFTDIR)/include $(LIBFTDIR)
LIBFT    := $(LIBFTDIR)/libft.a
LIBFT_A  := $(LIBFT)

VALGRIND       = valgrind
VALGRIND_FLAGS = --leak-check=full

ifeq ($(MAKECMDGOALS), bonus)
 SRCS := $(addprefix $(BONUS_SRCDIR)/, $(BONUS_SRCFILES))
 CFLAGS += -DBONUS_MODE
else
 SRCS := $(addprefix $(SRCDIR)/, $(SRCFILES))
endif

OBJS := $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(NAME): $(LIBFT) $(OBJS)
	@mkdir -p $(AR_TMP)
	@cp $(LIBFT) $(AR_TMP)/
	@cd $(AR_TMP) && $(AR) x libft.a
	@$(AR) $(ARFLAGS) $@ $(OBJS) $(AR_TMP)/*.o
	@$(RMDIR) $(AR_TMP)
	@echo "Archive created: $(NAME)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(BONUS_SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

test:
	$(MAKE) re
	$(CC) \
		-I$(INCDIR) -I$(LIBFTDIR)/include -I$(LIBFTDIR) \
		main_basic.c \
		$(NAME) \
		$(LIBFT_A) \
		-o test_mandatory

testrun: test
	# $(VALGRIND) $(VALGRIND_FLAGS) ./test_mandatory
	./test_mandatory

testbonus:
	$(MAKE) fclean
	$(MAKE) bonus
	$(CC) \
		-I$(INCDIR) -I$(LIBFTDIR)/include -I$(LIBFTDIR) \
		-DBONUS_MODE \
		main_bonus.c \
		$(NAME) \
		$(LIBFT_A) \
		-o test_bonus

testbonusrun: testbonus
	# $(VALGRIND) $(VALGRIND_FLAGS) ./test_bonus
	./test_bonus

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	@$(RMDIR) $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	@$(RM) $(NAME) test_mandatory test_bonus

re: fclean all

bonus: $(NAME)

.PHONY: all clean fclean re bonus test testrun testbonus testbonusrun
