SRC_DIR	:= src/
OBJ_DIR	:= obj/
BIN_DIR	:= bin/
INC_DIR	:= inc/

NAME	:= $(BIN_DIR)libft.a
SRC		:= $(wildcard $(SRC_DIR)*.c)
OBJ		:= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
INCLUDE	:= -Iinc
LDFLAGS	:= -Llib

BS = 32

.PHONY: all clean fclean re
.SILENT:

all: $(NAME)
	$(info libft done : BUFFER_SIZE = $(BS))

$(NAME): $(OBJ) | $(BIN_DIR)
	ar rcs $(NAME) $(OBJ)
	$(info $@ created)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_DIR)*.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ -D BUFFER_SIZE=$(BS)
	$(info $@ created)

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@
	$(info $@ created)

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
