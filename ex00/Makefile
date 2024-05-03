CXX=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98

NAME=megaphone
SRCS=megaphone.cpp
OBJS=$(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $@

%.o: %.c
	$(CXX) -c $(SRCS) -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean re
