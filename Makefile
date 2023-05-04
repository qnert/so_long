CC = cc
CFLAGS =
USER = $(shell whoami)
MLXFLAGS = -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
NAME = so_long

SRCS = so_long.c

all: $(MLX) $(NAME)

$(NAME): $(OBJS)
	@cd ./MLX42 && cmake -B build && cmake --build build -j4
	@cd libs && make
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS) ./libs/libs.a ./MLX42/build/libmlx42.a $(MLXFLAGS)

clean:
	@cd ./MLX42 && rm -rf build
	@cd libs && make fclean
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all