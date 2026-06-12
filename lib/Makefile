NAME        = so_long

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I. -Ilib/libft -Ilib/libftprintf

RM          = rm -rf


SRCS        = src/main.c \
              src/map_checker.c \
              lib/ft_count_lines.c \
              lib/ft_count_c.c \
              lib/ft_line_length.c \
              lib/get_next_line.c \
              lib/get_next_line_utils.c


OBJS        = $(SRCS:.c=.o)


LIBFT_DIR   = lib/libft
LIBFT       = $(LIBFT_DIR)/libft.a

PRINTF_DIR  = lib/libftprintf
PRINTF      = $(PRINTF_DIR)/libftprintf.a



all: $(LIBFT) $(PRINTF) $(NAME)


$(LIBFT):
	@make -C $(LIBFT_DIR)


$(PRINTF):
	@make -C $(PRINTF_DIR)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)


%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)
	$(RM) $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
