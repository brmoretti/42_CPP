NAME		=	UnnecessaryViolence
SRCS		=	$(wildcard src/*.cpp)
INCLUDE_FLS	=	$(wildcard src/*.hpp)
INCLUDES	=	-Isrc
CC			=	c++
FLAGS		=	-Wall		\
				-Wextra		\
				-Werror		\
				-std=c++98	\
				-pedantic
VALGRIND	=	valgrind 				\
				-q						\
				--leak-check=full		\
				--show-leak-kinds=all	\
				--trace-children=no		\
				--track-fds=no

all: $(NAME)

$(NAME): $(SRCS) $(INCLUDE_FLS)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS) -o $(NAME)

fclean:
	@ rm -rf $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

valgrind: $(NAME)
	$(VALGRIND) ./$<
