NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -c #TODO add flags
#MLX = -lmlx -L /usr/local/include -framework AppKit -framework OpenGL
LIBFT = -lft -L libft
FT_PRINTF = -lftprintf -L ft_printf
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

%.c:
	$(CC) $(CFLAGS) $(SRCS)

all: lib ftprintf $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)

ftprintf:
	cd ft_printf && make

lib:
	cd libft && make 

clean:
	rm -f ./*.o libft/*.o ft_printf/*.o

fclean: clean
	rm -f $(NAME) libft/libft.a ft_printf/libftprintf.a

re: fclean all

.PHONY: all clean fclean re lib ftprintf

# WINDOWS
#NAME = so_long
#CC = gcc
#CFLAGS = -Wall -Wextra -c #TODO add flags
#LIBFT = -lft -L libft
#FT_PRINTF = -lftprintf -L ft_printf
#SRCS = $(wildcard *.c)
#OBJS = $(SRCS:.c=.o)
#
#%.c:
#	$(CC) $(CFLAGS) $(SRCS)
#
#all: lib ftprintf $(NAME)
#
#$(NAME): $(OBJS)
#	$(CC) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)
#
#ftprintf:
#	cd ft_printf && make
#
#lib:
#	cd libft && make 
#
#clean:
#	del .\*.o libft\*.o ft_printf\*.o
#
#fclean: clean
#	del $(NAME) libft\libft.a ft_printf\libftprintf.a
#
#re: fclean all
#
#.PHONY: all clean fclean re lib ftprintf
