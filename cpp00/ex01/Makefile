CXX=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98

NAME=phonebook
SRCS=PhoneBook.cpp Contact.cpp main.cpp add.cpp search.cpp common.cpp
HEADERS=app.hpp Contact.hpp PhoneBook.hpp
OBJS=$(SRCS:%.cpp=objs/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CXX) $(CFLAGS) $(OBJS) -o $@

objs/%.o: %.cpp $(HEADERS)
	@mkdir -p objs
	$(CXX) $(CFLAGS) -c $< -o $@

re: fclean
	@$(MAKE) --no-print-directory

clean:
	rm -rf objs

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean re
