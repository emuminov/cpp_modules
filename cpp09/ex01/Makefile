CXX=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3 -O0

NAME=RNP
SRCS=main.cpp RNP.cpp
HEADER=RNP.hpp
OBJS=$(SRCS:%.cpp=objs/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CXX) $(CFLAGS) $(OBJS) -o $@

objs/%.o: %.cpp $(HEADER)
	@mkdir -p objs
	$(CXX) $(CFLAGS) -c $< -o $@

re: fclean
	@$(MAKE) --no-print-directory

clean:
	rm -rf objs

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean re
