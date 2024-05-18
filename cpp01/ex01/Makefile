CXX=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98 -fsanitize=address

NAME=main
SRCS=main.cpp zombieHorde.cpp Zombie.cpp
OBJS=$(SRCS:%.cpp=objs/%.o)
HEADERS=Zombie.hpp

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
