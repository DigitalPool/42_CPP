CC = c++
NAME = harlFilter
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Harl.cpp

all:
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f *.o

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
