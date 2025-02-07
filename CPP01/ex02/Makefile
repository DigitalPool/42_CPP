CC = c++
NAME = stringrefs
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp

all:
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f *.o

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
