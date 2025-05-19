# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/09 17:34:47 by hisasano          #+#    #+#              #
#    Updated: 2025/05/19 20:54:37 by hisasano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := libftprintf.a

SRC_M  = ft_printf.c \
          ft_conv_char.c ft_conv_str.c ft_conv_decimal.c \
          ft_conv_unsigned.c ft_conv_pointer.c ft_conv_hex.c \
          ft_my_atoi.c ft_reset_format_spec.c \
          ft_utoa.c ft_utoa_base.c ft_do_write.c \
          ft_is_spec.c ft_spec_type.c ft_conv.c ft_printf_basic.c \
          ft_my_strdup.c ft_my_strlen.c

SRC_B  = ft_printf_bonus.c \
          ft_add_sign_or_space_bonus.c ft_apply_bonus.c \
          ft_apply_prcn_bonus.c ft_apply_width_bonus.c \
          ft_hash_join_bonus.c ft_left_align_bonus.c ft_zero_pad_bonus.c \
          ft_parse_width_bonus.c ft_parse_prec_bonus.c ft_parse_format_bonus.c \
          ft_set_flagc_bonus.c ft_set_str_bonus.c ft_conv_bonus.c \
          ft_handle_format_bonus.c

SRCDIR       := src
BONUSDIR     := bonus_src
OBJDIR       := obj
INCDIR       := include
LIBFTDIR     := libft

CC      := cc
CFLAGS  := -Wall -Wextra -Werror
AR      := ar
ARFLAGS := rcs
RM      := rm -f
RMDIR   := rm -rf

MANDATORY_SRCS := $(addprefix $(SRCDIR)/,$(SRC_M))
BONUS_SRCS     := $(addprefix $(BONUSDIR)/,$(SRC_B))

ifeq ($(filter bonus testbonus testbonusrun bonus_lib,$(MAKECMDGOALS)),)
	SRCS   := $(MANDATORY_SRCS)
else
	SRCS   := $(sort $(MANDATORY_SRCS) $(BONUS_SRCS))
	CFLAGS += -DBONUS_MODE
endif

OBJS := $(addprefix $(OBJDIR)/,$(notdir $(SRCS:.c=.o)))

vpath %.c $(SRCDIR) $(BONUSDIR)

all: $(NAME)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(addprefix -I, $(INCDIR) $(LIBFTDIR)/include $(LIBFTDIR)) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

LIBFT := $(LIBFTDIR)/libft.a
$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(NAME): $(LIBFT) $(OBJS)
	@mkdir -p ar_tmp
	@cp $(LIBFT) ar_tmp/
	@cd ar_tmp && $(AR) x libft.a
	@$(AR) $(ARFLAGS) $@ $(OBJS) ar_tmp/*.o
	@$(RMDIR) ar_tmp
	@echo "Archive created: $(NAME)"

test: re
	$(CC) -I$(INCDIR) -I$(LIBFTDIR)/include -I$(LIBFTDIR) \
	     main_basic.c $(NAME) $(LIBFT) -o test_mandatory

testrun: test
	./test_mandatory

testbonus: fclean bonus
	$(CC) -I$(INCDIR) -I$(LIBFTDIR)/include -I$(LIBFTDIR) \
	     -DBONUS_MODE main_bonus.c $(NAME) $(LIBFT) -o test_bonus

testbonusrun: testbonus
	./test_bonus

bonus_lib: CFLAGS += -DBONUS_MODE
bonus_lib: fclean bonus

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	@$(RMDIR) $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	$(RM) $(NAME) test_mandatory test_bonus

re: fclean all

bonus: $(NAME)

.PHONY: all clean fclean re bonus test testrun testbonus testbonusrun bonus_lib
