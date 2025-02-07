CC = c++
NAME = zombie
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Zombie.cpp main.cpp newZombie.cpp randomChump.cpp

all :
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f *.o

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
