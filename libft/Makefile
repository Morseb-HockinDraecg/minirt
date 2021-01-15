PROJ_DIR := libft/
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

$(NAME): $(OBJ) | $(BIN_DIR)
	ar rcs $(NAME) $(OBJ)
	echo "$(PROJ_DIR)$@ \033[32mlib created\033[0m"
	echo "--------------------------------------------"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_DIR)*.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ -D BUFFER_SIZE=$(BS)
	echo "$(PROJ_DIR)$@ \033[32mcreated\033[0m"

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@
	echo "$(PROJ_DIR)$@ \033[32mdir created\033[0m"

clean:
	$(RM) -rf $(OBJ_DIR)
	echo "$(PROJ_DIR)$(OBJ_DIR) \033[31mdir deleted\033[0m"

fclean: clean
	$(RM) -rf $(BIN_DIR)
	echo "$(PROJ_DIR)$(BIN_DIR) \033[31mdir deleted\033[0m"

fclean_re:
	$(RM) -rf $(OBJ_DIR)/*
	echo "$(PROJ_DIR)$(OBJ_DIR)*.o \033[31mdeleted\033[0m"
	$(RM) -rf $(BIN_DIR)
	echo "$(PROJ_DIR)$(BIN_DIR) \033[31mdir deleted\033[0m"

re: fclean_re all
