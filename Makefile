PROJ_DIR := minirt/
SRC_DIR	:= $(PROJ_DIR)srcs/
INC_DIR	:= $(PROJ_DIR)inc/
OBJ_DIR	:= $(PROJ_DIR)obj/
BIN_DIR	:= $(PROJ_DIR)bin/

NAME	:= $(BIN_DIR)minirt
SRC		:= $(SRC_DIR)color/color.c\
$(SRC_DIR)color/light.c\
$(SRC_DIR)display/img.c\
$(SRC_DIR)display/list_obj.c\
$(SRC_DIR)display/shape_intersection.c\
$(SRC_DIR)display/util.c\
$(SRC_DIR)display/utils_cylinders.c\
$(SRC_DIR)error/error_format.c\
$(SRC_DIR)error/error_minirt.c\
$(SRC_DIR)error/error_parsing.c\
$(SRC_DIR)init/init.c\
$(SRC_DIR)init/init_mlx.c\
$(SRC_DIR)parsing/check_values.c\
$(SRC_DIR)parsing/manag_lst.c\
$(SRC_DIR)parsing/parse_not_shape.c\
$(SRC_DIR)parsing/parse_shape.c\
$(SRC_DIR)parsing/parsing.c\
$(SRC_DIR)parsing/parsing_utils_cylindre.c\
$(SRC_DIR)parsing/trim.c\
$(SRC_DIR)vector/vector1.c\
$(SRC_DIR)vector/vector2.c\
$(SRC_DIR)hook.c\
$(SRC_DIR)main.c\
$(SRC_DIR)save.c\
$(SRC_DIR)utils_minirt.c

OBJ		:= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
INCLUDE	:= -Iminilibx -I$(PROJ_DIR)inc -Ilibft/inc/
LDFLAGS	:= -Lminilibx -lmlx -Llibft/bin -lft -lm

.PHONY: all clean fclean re
.SILENT:

all: $(NAME)
	$(info "./minirt/bin/minirt" + (rt file) to lauch app)
	$(info --------------------------------------------)

$(NAME):  $(OBJ) | $(BIN_DIR)
	make -C libft
	make -C minilibx
	cp minilibx/libmlx.dylib .
	$(CC) $(LDFLAGS) $^ -o $@
	echo "$@ (exec) \033[32mcreated\033[0m"
	echo "--------------------------------------------"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_DIR)mini_rt.h | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	echo "$@ \033[32mcreated\033[0m"

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@
	echo "$(OBJ_DIR) \033[32mdir created\033[0m"

clean:
	$(RM) -rf $(OBJ_DIR)
	echo "$(OBJ_DIR) \033[31mdir deleted\033[0m"
	$(RM) libmlx.dylib
	make -C libft clean
	make -C minilibx clean

fclean:
	$(RM) -rf $(OBJ_DIR)
	echo "$(OBJ_DIR) \033[31mdir deleted\033[0m"
	$(RM) libmlx.dylib
	$(RM) -rf $(BIN_DIR)
	echo "$(BIN_DIR) \033[31mdir deleted\033[0m"
	make -C libft fclean
	make -C minilibx fclean

fclean_re:
	make -C libft re
	make -C minilibx re
	$(RM) -rf $(OBJ_DIR)/*
	echo "$(OBJ_DIR)*.o \033[31mdeleted\033[0m"
	$(RM) -rf $(BIN_DIR)
	echo "$(BIN_DIR) \033[31mdir deleted\033[0m"
	echo "--------------------------------------------"

re: fclean_re all

# -include $(OBJ:.o=.d)

# LDFLAGS	:= -Lminilibx -Wl,-rpath=./minilibx/ -lmlx #-fPIC
## NAME
	# export LD_LIBRARY_PATH=../minilibx;\
	# echo $$LD_LIBRARY_PATH
	# $( info LD_LIBRARY_PATH : |$(LD_LIBRARY_PATH)|)
##clean
	# unset LD_LIBRARY_PATH
	# LD_LIBRARY_PATH unset 