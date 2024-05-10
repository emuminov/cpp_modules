CXX=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98 -g

NAME=phonebook
SRCS=PhoneBook.cpp Contact.cpp main.cpp add.cpp search.cpp common.cpp
HEADERS=app.hpp Contact.hpp PhoneBook.hpp
OBJS=$(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CXX) $(CFLAGS) $(OBJS) -o $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CFLAGS) -c $< -o $@

re: fclean
	@$(MAKE) --no-print-directory

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean re
