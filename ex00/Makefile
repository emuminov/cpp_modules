CXX=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98

NAME=megaphone
SRCS=megaphone.cpp
OBJS=$(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all --no-print-directory

.PHONY: all clean fclean re
