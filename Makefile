NAME = so_long
CC = CC
CFLAGS = -Wall -Wextra#TODO add flags
MLX = -lmlx -L /usr/local/include -framework AppKit -framework OpenGL
LIBFT = -lft -L libft
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

%.c:
	$(CC) -c $(CFLAGS) $(SRCS)

all: lib $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLX) $(LIBFT) -o $(NAME)

lib:
	cd libft && make 

clean:
	rm -f $(OBJS) libft/*.o

fclean: clean
	rm -f $(NAME) libft/libft.a

re: fclean all

.PHONY: all clean fclean re lib