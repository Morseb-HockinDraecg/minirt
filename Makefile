PROJ_DIR := minirt/
SRC_DIR	:= $(PROJ_DIR)srcs/
OBJ_DIR	:= $(PROJ_DIR)obj/
BIN_DIR	:= $(PROJ_DIR)bin/
INC_DIR	:= minilibx/ $(PROJ_DIR)inc/

NAME	:= $(BIN_DIR)minirt
#NORME : pas de wildcard !!
SRC		:= $(wildcard $(SRC_DIR)*.c) $(wildcard $(SRC_DIR)*/*.c)
OBJ		:= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
INCLUDE	:= -Iminilibx -I$(PROJ_DIR)inc -Ilibft
LDFLAGS	:= -Lminilibx -lmlx -Llibft -lft

.PHONY: all clean fclean re
.SILENT:

all: libft minilib $(NAME)

$(NAME):  $(OBJ) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ -o $@
	$(info $@ created)

libft:
	make -C libft
	$(info $@ created)

minilib:
	make -C minilibx
	$(info $@ created)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_DIR)mini_rt.h | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	$(info $@ created)

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $(PROJ_DIR)$@
	$(info $(notdir $@) created)

clean:
	$(RM) -rf $(OBJ_DIR)
	$(info $(OBJ_DIR) deleted)
	make -C libft clean
	make -C minilibx clean

fclean: clean
	$(RM) -rf $(BIN_DIR)
	$(info $(BIN_DIR) deleted)
	make -C libft fclean
	make -C minilibx fclean

fclean_re:
	make -C libft re
	make -C minilibx re
	$(RM) -rf $(OBJ_DIR)/*
	$(info $(OBJ_DIR) deleted)
	$(RM) -rf $(BIN_DIR)
	$(info $(BIN_DIR) deleted)

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