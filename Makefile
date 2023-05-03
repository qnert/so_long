CC = cc
CFLAGS =
MLXFLAGS = -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/skunert/.brew/opt/glfw/lib/"
NAME = so_long

SRCS = so_long.c

all: $(MLX) $(NAME)

$(NAME): $(OBJS)
	@git clone https://github.com/codam-coding-college/MLX42.git
	@cd MLX42 && cmake -B build && cmake --build build -j4
	@cd libs && make
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS) .//libs/libs.a ./MLX42/build/libmlx42.a $(MLXFLAGS)

clean:
	@rm -rf MLX42
	@cd libs && make fclean
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all