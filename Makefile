SRCS	=	push_swap.c \

OBJS	=	${SRCS:%.c=%.o}

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

LIB		=	-L./library/printf -lftprintf

NAME	=	push_swap

#rules    -------------------------------------------------------------    rules

all:		${NAME}

${NAME}:	${OBJS}	library
	@${CC} ${CFLAGS} ${LIB} ${OBJS} -o ${NAME}
	@echo "code compiled succesfully"

library:	printf

printf:
	@make -s -C ./library/printf
	@echo "printf compiled"

clean:
	@rm -f ${OBJS}
	@make -s -C ./library/printf clean
	@echo "object files removed"

fclean:		clean
	@rm -f ${NAME}
	@make -s -C ./library/printf fclean
	@echo "${NAME} file removed"

re:		fclean all

.PHONY:		all clean fclean re
