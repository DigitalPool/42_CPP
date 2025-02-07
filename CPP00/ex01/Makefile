CC = c++
NAME = phonebook
FLAGS = -Wall -Wextra -Werror
SRC = Phonebook.cpp Contact.cpp

all :
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f *.o

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
