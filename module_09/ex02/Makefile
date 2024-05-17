NAME		=	PmergeMe
SRCS		=	$(wildcard src/*.cpp)
INCLUDE_FLS	=	$(wildcard include/*.hpp)
INCLUDES	=	-Isrc		\
				-Iinclude
CC			=	c++
FLAGS		=	-Wall		\
				-Wextra		\
				-Werror		\
				-std=c++98	\
				-pedantic	\
				-g3
VALGRIND	=	valgrind 				\
				-q						\
				--leak-check=full		\
				--show-leak-kinds=all	\
				--trace-children=no		\
				--track-fds=no
ARGS		=	`shuf -i 1-100000 -n 3000 | tr "\n" " "`

all: $(NAME)

$(NAME): $(SRCS) $(INCLUDE_FLS)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS) -o $(NAME)

fclean:
	@ rm -rf $(NAME)

re: fclean all

run: $(NAME)
	./$< $(ARGS)

valgrind: $(NAME)
	$(VALGRIND) ./$< $(ARGS)
