SRC_DIR	:= srcs/
OBJ_DIR	:= obj/
BIN_DIR	:= bin/
INC_DIR	:= minilibx/ inc/

NAME	:= $(BIN_DIR)minirt
SRC		:= $(wildcard $(SRC_DIR)*.c) $(wildcard $(SRC_DIR)*/*.c)
OBJ		:= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
INCLUDE	:= -Iminilibx -Iinc
LDFLAGS	:= -Lminilibx -lmlx 

.PHONY: all clean fclean re
.SILENT:

all: $(NAME)

$(NAME): $(OBJ) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ -o $@
	$(info $@ created)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_DIR)*.h | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	$(info $@ created)

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@
	$(info $(notdir $@) created)

clean:
	$(RM) -rf $(OBJ_DIR)
	$(info $(OBJ_DIR) deleted)

fclean: clean
	$(RM) -rf $(BIN_DIR)
	$(info $(BIN_DIR) deleted)

fclean_re:
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