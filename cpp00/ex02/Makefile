CXX=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98

NAME=main
SRCS=Account.cpp tests.cpp
HEADERS=Account.hpp
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

test: $(NAME)
	@./$(NAME) | awk '{print $$2 onward}' > our_logs
	@cat 19920104_091532.log | awk '{print $$2 onward}' > their_logs
	@diff our_logs their_logs -s
	@rm -f our_logs their_logs

.PHONY: all clean fclean re test
