NAME = form
SRCS = main.cpp Bureaucrat.cpp Form.cpp
OBJS = $(SRCS:.cpp=.o)

CXX = clang++
CXXSTD = -std=c++98
CXXFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXSTD) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)
fclean:
	$(RM) $(NAME)
	$(RM) $(OBJS)
re: fclean all