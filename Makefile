NAME        = so_long
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
LIBFT_DIR   = libft
FT_PRINTF_DIR = ft_printf
FT_PRINTF  = $(FT_PRINTF_DIR)/libftprintf.a
LIBFT_LIB   = $(LIBFT_DIR)/libft.a
INCLUDES    = -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)
MLX_FLAGS   = -Lminilibx-linux -lmlx_Linux -lX11 -lXext
SRC         = so_long.c gnl/get_next_line_bonus.c gnl/get_next_line_utils_bonus.c \
			utils.c map_parsing.c mx_init.c player.c fill.c game.c valid_map.c\
			
OBJS        = $(SRC:.c=.o)

all: $(LIBFT_LIB) $(FT_PRINTF) $(NAME)

$(NAME): $(LIBFT_LIB) $(FT_PRINTF) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT_LIB) $(FT_PRINTF) -o $(NAME)


$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	@rm -f $(OBJS)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(FT_PRINTF_DIR)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) fclean -C $(FT_PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re