NAME    = minirt
CC      = cc
MKDIR   = mkdir

SRC_DIR = src
OBJ_DIR = build/objs

SRC = \
    main.c \
    error/error.c \
    lighting/lighting_utils.c \
    lighting/lighting.c \
    lighting/shadow.c \
    paint_img/antialiasing.c \
    paint_img/paint_img.c \
    parser/ambient.c \
    parser/camera.c \
    parser/chunk_utils.c \
    parser/light.c \
    parser/object.c \
    parser/parser_utils.c \
    parser/parser.c \
    parser/vector_parser.c \
    ray/ray_utils.c \
    ray/ray.c \
    shapes/cyl_faces_utils.c \
    shapes/cyl_utils.c \
    shapes/ft_object_list_utils.c \
    shapes/ft_object_utils.c \
    shapes/plane_utils.c \
    shapes/sphere_utils.c \
    utils/color_utils.c \
    utils/elements_utils.c \
    utils/hit_record_utils.c \
    utils/hit_utils.c \
    utils/hittable_utils.c \
    utils/math_utils.c \
    utils/utils.c \
    utils/vec_utils.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

ifdef ANTIALIAS
    FLAGS = -Wall -Werror -Wextra -DANTI=1
else
    FLAGS = -Wall -Werror -Wextra -DANTI=5
endif

LIBFT = libft/libft.a
MLX42 = MLX42/libmlx42.a

HEADER = includes/minirt.h

INCLUDES = -Iincludes -Ilibft

GLFW_LIB = -L /opt/homebrew/Cellar/glfw/3.4/lib

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	$(MKDIR) -p $(dir $@)
	$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(MLX42)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(MLX42) $(GLFW_LIB) -lglfw -o $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(MLX42):
	$(MAKE) -C MLX42

$(OBJ_DIR):
	$(MKDIR) -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re: fclean all