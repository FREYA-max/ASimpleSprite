CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long

OBJDIR = obj
MLX_DIR_LINUX = lib/mlx-linux
MLX_DIR_MACOS = lib/mlx-macos
LIBFT_DIR = lib/libft
FTPRINTF_DIR = lib/libftprintf

SRC_CORE = src/main.c src/map_checker.c
SRC_UTIL = lib/ft_count_lines.c lib/ft_count_c.c lib/ft_line_length.c \
           lib/get_next_line.c lib/get_next_line_utils.c

SRC = $(SRC_CORE) $(SRC_UTIL)
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

.SILENT:

all: linux

linux: CFLAGS += -DLINUX
linux: MLX_DIR=$(MLX_DIR_LINUX)
linux: MLX_LIB=-lmlx_Linux -lm -lX11 -lXext
linux: $(LIBFT_DIR)/libft.a $(FTPRINTF_DIR)/libftprintf.a $(NAME)
	@echo "Linux build complete."

macos: CFLAGS += -DMACOS
macos: MLX_DIR=$(MLX_DIR_MACOS)
macos: MLX_LIB=-lmlx -framework OpenGL -framework AppKit
macos: $(LIBFT_DIR)/libft.a $(FTPRINTF_DIR)/libftprintf.a $(NAME)
	@echo "macOS build complete."

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -L$(FTPRINTF_DIR) -lftprintf -lft $(MLX_LIB) -o $(NAME)
	@echo "$(NAME) has been successfully built."

$(OBJDIR)/%.o: %.c
	@echo "Compiling $<"
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -I$(FTPRINTF_DIR) -c $< -o $@

$(LIBFT_DIR)/libft.a:
	@echo "Building libft..."
	$(MAKE) -C $(LIBFT_DIR)

$(FTPRINTF_DIR)/libftprintf.a:
	@echo "Building libftprintf..."
	$(MAKE) -C $(FTPRINTF_DIR)

clean:
	@echo "Cleaning up..."
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFT_DIR) clean >/dev/null 2>&1 || true
	$(MAKE) -C $(FTPRINTF_DIR) clean >/dev/null 2>&1 || true
	@echo "Clean complete."

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean >/dev/null 2>&1 || true
	$(MAKE) -C $(FTPRINTF_DIR) fclean >/dev/null 2>&1 || true
	@echo "Full clean complete."

re: fclean all

.PHONY: all linux macos clean fclean re
