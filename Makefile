NAME = cub3D

RESET = "\033[0m"
GREEN = \033[38:5:120m
BLUE = \033[38:5:117m
ORANGE = \033[38:5:222m
PINK = \033[38:5:218m

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

MLX_PATH = ./minilibx
MLX_FLAGS = -L/usr/lib -L$(LIBFT_PATH) -L$(MLX_PATH) -lmlx -lX11 -lXext -lm -lz
MLX = $(MLX_PATH)/libmlx.a

OBJ_DIR = objs
SRC_FILES = \
			main \
			controls/keypress controls/keyrelease controls/event_exec \
			init/init init/init2 \
			parsing/cub_parse parsing/cub_parse2 parsing/scene_parse \
			parsing/map_parse parsing/map_parse2 \
			player/player player/move player/turn\
			utils/free utils/get_next_line utils/quit_exit \
			render/dda render/raycasting render/render \
			render/draw render/draw2
SRC = $(addprefix srcs/, $(addsuffix .c, $(SRC_FILES)))

OBJS := $(SRC:srcs/%.c=$(OBJ_DIR)/%.o)
$(OBJ_DIR)/%.o: srcs/%.c | $(OBJ_DIR)
	@cc $(CFLAGS) -c $< -o $@

AR = ar rcs
RM = rm -rf
INCLUDES = -I/usr/include -I$(MLX_PATH) -I./includes/
CFLAGS = -Wall -Wextra -Werror $(INCLUDES) -fsanitize=address -g3

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@chmod 777 $(MLX_PATH)/configure
	@make -C $(MLX_PATH) > /dev/null 2>&1
	@cc $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)$(NAME)$(BLUE) is ready"$(RESET)

valgrind: CFLAGS := -Wall -Wextra -Werror $(INCLUDES)
valgrind: fclean $(OBJS) $(LIBFT)
	@chmod 777 $(MLX_PATH)/configure
	@make -C $(MLX_PATH) > /dev/null 2>&1
	@cc $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)$(NAME)$(BLUE) is ready to use with Valgrind"$(RESET)

$(LIBFT):
	@echo "$(BLUE)Compiling libft..." $(RESET)
	@make -C $(LIBFT_PATH) --no-print-directory

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/controls
	@mkdir -p $(OBJ_DIR)/init
	@mkdir -p $(OBJ_DIR)/parsing
	@mkdir -p $(OBJ_DIR)/player
	@mkdir -p $(OBJ_DIR)/utils
	@mkdir -p $(OBJ_DIR)/render

clean:
	@make clean -C $(LIBFT_PATH) --no-print-directory
	@echo "$(ORANGE)Remove Libft object files"$(RESET)
	@make clean -C $(MLX_PATH) --no-print-directory
	@$(RM) $(OBJS) $(OBJ_DIR)
	@echo "$(ORANGE)Remove object files"$(RESET)

fclean: clean
	@make fclean -C $(LIBFT_PATH) --no-print-directory
	@$(RM) $(NAME)
	@echo "$(ORANGE)Remove $(NAME)"$(RESET)
	@echo "$(PINK)EVERYTING CLEAR!! :P"$(RESET)

re: fclean all

.PHONY = all clean fclean re valgrind
