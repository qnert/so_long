CC = cc
CFLAGS = -Wall -Wextra -Werror
USER = $(shell whoami)
MLXFLAGS = -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
NAME = so_long

SRCS = so_long.c ./utils/map_check.c ./utils/components_check.c ./utils/game_funcs.c ./utils/game_hooks.c \
		./utils/fill_components.c

OBJS = $(SRCS:.c=.o)

all: MLX42 $(NAME)

$(NAME): $(OBJS)
	@cd libs && make
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./libs/libs.a ./MLX42/build/libmlx42.a $(MLXFLAGS)

MLX42:
	@if [ ! -d "MLX42" ]; then git clone https://github.com/codam-coding-college/MLX42.git; fi
	@cd MLX42 && cmake -B build && cmake --build build -j4

clean:
	@rm -rf MLX42
	@cd libs && make fclean
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all