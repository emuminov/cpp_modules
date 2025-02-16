CXX=g++
CFLAGS=-Wall -Wextra -Werror -std=c++98 -g

NAME=phonebook
SRCS=PhoneBook.cpp Contact.cpp main.cpp add.cpp search.cpp common.cpp
OBJS=$(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $@

%.o: %.c
	$(CXX) -c $(SRCS) -o $@

re: fclean
	$(MAKE)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean re
