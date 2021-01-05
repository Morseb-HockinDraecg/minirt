SRC_DIR	:= srcs/
OBJ_DIR	:= obj/
BIN_DIR	:= bin/
#INC_DIR	:= inc/
INC_DIR	:= minilibx/

NAME	:= (BIN_DIR)minirt
SRC		:= $(wildcard $(SRC_DIR)*.c)
OBJ		:= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
INCLUDE	:= -Iminilibx
LDFLAGS	:= -L. -lmlx

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $(OBJ_DIR)$^ -o $@
 	$(info $@ created)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_DIR)*.h | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	$(info $@ created)

$(BIN_DIR) $(OBJ_DIR):
	@mkdir -p $@
	$(info $@ created)

clean:
	@$(RM) -rf $(OBJ_DIR)
	$(info $(OBJ_DIR) deleted)

fclean: clean
	@$(RM) -rf $(BIN_DIR)
	$(info $(BIN_DIR) deleted)

re: fclean all

# -include $(OBJ:.o=.d)
