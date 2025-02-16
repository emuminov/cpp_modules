CXX=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98 -I includes

NAME=phonebook
FILES=PhoneBook.cpp Contact.cpp main.cpp add.cpp search.cpp common.cpp
SRCS=$(FILES:%=srcs/%)
OBJS=$(FILES:%.cpp=objs/%.o)
HEADER_FILES=app.hpp Contact.hpp PhoneBook.hpp
HEADERS=$(HEADER_FILES:%=includes/%);

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CXX) $(CFLAGS) $(OBJS) -o $@

objs/%.o: srcs/%.cpp $(HEADERS)
	@mkdir -p objs
	$(CXX) $(CFLAGS) -c $< -o $@

re: fclean
	@$(MAKE) --no-print-directory

clean:
	rm -rf objs

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean re
