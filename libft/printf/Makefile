SRC_DIR	:= src/
OBJ_DIR	:= obj/
INC_DIR	:= inc/

NAME	:= libftprintf.a
SRC		:= $(wildcard $(SRC_DIR)*.c)
OBJ		:= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
LIB		:= libft/libft.a

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
INCLUDE	:= -Iinc/
LDFLAGS	:= -Llibft/
LDLIBS  := -lft 

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	$(info $@ created)


$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_DIR)*.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ 
	$(info $@ created)

$(OBJ_DIR):
	mkdir -p $@
	$(info $@ created)

$(LIB)/libft/libft.a:
	make -C $< all

clean:
	$(RM) -rf $(OBJ_DIR)
	$(info $(OBJ_DIR) deleted)

fclean: clean
	$(RM) -rf $(NAME)

cleano:
	$(RM) -rf $(OBJ_DIR)/*
re:  cleano all


.SILENT :

# -include $(OBJ:.o=.d)

