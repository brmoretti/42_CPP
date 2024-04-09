NAME		=	harlFilter
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
<<<<<<< HEAD
ARGS		=
=======
ARGS		=	
>>>>>>> 8f87bec9ecd8adb0da63612b9b8a0538a1175c45

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
