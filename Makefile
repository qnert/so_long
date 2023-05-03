CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = so_long

SRCS = so_long.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@cd includes && make
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./MLX42/build/libmlx42.a -framework Cocoa -framework OpenGL -framework IOKit-Iinclude -lglfw -L"/Users/skunert/.brew/opt/glfw/lib/"

clean:
	@cd includes && make fclean
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all