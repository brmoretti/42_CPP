NAME		=	megaphone
SRCS		=	megaphone.cpp
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

$(NAME): $(SRCS)
	$(CC) $(FLAGS) -o $(NAME) $(SRCS)

fclean:
	@ rm -rf $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

valgrind: $(NAME)
	$(VALGRIND) ./$<
