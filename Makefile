#\/\/\/Colours

NO_COLOR = \033[0m
WAIT_COLOR = \033[1;33m
OK_COLOR = \033[1;32m
CLEAN_COLOR = \033[1;36m

#\/\/\/Compiliation

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror

#\/\/\/Files

SRC = main.c \
ft_input_read.c \
ft_map.c \
ft_store.c \
ft_place.c \

OBJ = $(SRC:.c=.o)

INC = -I ./libft/ -L ./libft -lft

#\/\/\/Rules

.PHONY: all clean fclean re

all: $(NAME) 

$(NAME): $(OBJ)
	@make all -C libft
	$(CC) $(CFLAGS) $(OBJ) $(INC) -o $@ 
	@echo "$(OK_COLOR)	--- Fillit  created! ---	$(NO_COLOR)"

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)
	@echo "$(OK_COLOR)	--- Binary   created ---	$(NO_COLOR)"

norme:
	@norminette $(SRC) $(INC)
clean:
	rm -rf $(OBJ)
	@make clean -C libft
	@echo "$(CLEAN_COLOR)	--- Binary   deleted ---		$(NO_COLOR)"
	
fclean: clean
	@make fclean -C libft
	rm -rf $(NAME)
	@echo "$(CLEAN_COLOR)	--- Program  deleted ---		$(NO_COLOR)"

re: fclean all
