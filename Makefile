NAME := libftprintf.a

SRC := ft_printf.c
OBJ := $(SRC:.c=.o)

BONUSSRC := _bonus.c
BONUSOBJ := $(BONUSSRC:.c=.o)

CC := cc
CFLAGS := -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

LIBFT_DIR := libft
LIBFT_A	  := $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR) all      # -Cはディレクトリ移動してからmakeを実行
	cp $(LIBFT_A) $(NAME)         # 出来たlibft.aをlibftprintf.aにコピー
	ar rcs $(NAME) $(OBJ)         # libftprintf.aにさらに.oファイルを追加

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJ) $(BONUSOBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

#bonus: re $(BONUSOBJ)
#	ar rcs $(NAME) $(BONUSOBJ)
# ↑ is ”re", "bonusobj" and "ar" are in no particulur order

bonus: BONUS_BUILD

BONUS_BUILD: re $(BONUSOBJ)
	ar rcs $(NAME) $(BONUSOBJ)


.PHONY: all clean fclean re bonus
