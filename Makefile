SRCS	=	push_swap.c \
			debug.c \
			exit.c \
			parsing.c \
			parsing_index.c \
			general_utils.c \
			stack_utils.c \
			moves/push.c \
			moves/rev_rotate.c \
			moves/rotate.c \
			moves/swap.c \
			sorting/do_sorting.c \
			sorting/sort_five.c \
			sorting/sort_three.c \
			sorting/sort_many.c \
			sorting/utils.c \

OBJS	=	${SRCS:%.c=%.o}

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

LIB		=	-L./library/printf -lftprintf -L./library/libft -lft

NAME	=	push_swap

#rules    -------------------------------------------------------------    rules

all:		${NAME}

${NAME}: ${OBJS}	library
	@${CC} ${CFLAGS} ${LIB} ${OBJS} -o ${NAME}
	@echo "code compiled succesfully"

library:	printf libft

printf:
	@make -s -C ./library/printf
	@echo "printf compiled"

libft:
	@make -s -C ./library/libft
	@echo "libft compiled"

clean:
	@rm -rf ${OBJS} ${NAME}.dSYM
	@make -s -C ./library/printf clean
	@make -s -C ./library/libft clean
	@echo "object files removed"

fclean:		clean
	@rm -f ${NAME} generator
	@make -s -C ./library/printf fclean
	@make -s -C ./library/libft fclean
	@echo "${NAME} file removed"

re:		fclean all

debug: library
	${CC} ${CFLAGS} ${LIB} ${SRCS} -g -fsanitize=address -o ${NAME}

generator:
	${CC} ${CFLAGS} -o get_nbrs nb_generator/generator.c

.PHONY:		all clean fclean re debug
