SRCS	=	push_swap.c \
			debug.c \
			exit.c \
			parsing.c \
			general_utils.c \

OBJS	=	${SRCS:%.c=%.o}

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

LIB		=	-L./library/printf -lftprintf -L./library/libft -lft

NAME	=	push_swap

#rules    -------------------------------------------------------------    rules

all:		${NAME}

${NAME}:	${OBJS}	library
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
	@rm -f ${OBJS}
	@make -s -C ./library/printf clean
	@echo "object files removed"

fclean:		clean
	@rm -f ${NAME}
	@make -s -C ./library/printf fclean
	@echo "${NAME} file removed"

re:		fclean all

debug: library
	${CC} ${CFLAGS} ${LIB} ${SRCS} -g -fsanitize=address -o ${NAME}

.PHONY:		all clean fclean re debug
