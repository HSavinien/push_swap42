SRCS	=	checker.c \
			debug.c \
			exit.c \
			general_utils.c \
			moves/push.c \
			moves/rev_rotate.c \
			moves/rotate.c \
			moves/swap.c \
			parsing.c \
			parsing_index.c \
			stack_utils.c \
			stack_utils2.c \


OBJS	=	${SRCS:%.c=%.o}

NB_SRCS	=	$(words $(SRCS))

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -Ilibrary -I./

LIB		=	-L../library/libft -lft -L ../library/printf -lftprintf

NAME	=	../checker

#rules    -------------------------------------------------------------    rules

#standart rules

all:	${NAME}

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[1mcompiling\033[0m: $<                                 \n"
	@printf $$'\033[2m'
	@printf '%*s' $(NB_SRCS) '' | tr ' ' '*' #print one star per file in SRCS
	@printf $$'\033[0;1;33m|\033[0m⌛\r\033[0;1m'
	@cat .loading_bar 2>/dev/null || printf "" > .loading_bar
	@printf '*\r'
	@printf "\033[0m\033[A\r"
	@printf '*' >> .loading_bar

${NAME}: ${OBJS}
	@echo "\033[0;1m"
	@printf '%*s' $(NB_SRCS) '' | tr ' ' '*' #print one star per file in SRCS
	@printf "\033[0m\033[C✅\n"
	@echo "\033[1;32mcompiled\033[0m"
	@echo "\033[34mcompiling library :\033[0m"
	@make library
	@echo "\033[1;34mlinking files:\033[0m"
	@${CC} ${CFLAGS} ${LIB} ${OBJS} -o ${NAME}
	@rm -f .loading_bar
	@echo "\033[1;32mcode compiled succesfully\033[0m ✅"

clean:
	@make -s -C ../library/libft clean
	@echo "\033[1;31mlibft cleaned\033[0m"
	@make -s -C ../library/printf clean
	@echo "\033[1;31mprintf cleaned\033[0m"
	@rm -rf ${OBJS} ${NAME}.dSYM ${BOBJS} test .loading_bar
	@echo "\033[1;31mobject files removed\033[0m"

fclean:		clean
	@make -s -C ../library/libft fclean
	@echo "\033[1;33mlibft.a file removed\033[0m"
	@make -s -C ../library/printf fclean
	@echo "\033[1;33mlibftprintf.a file removed\033[0m"
	@rm -f ${NAME}
	@echo "\033[1;33m${NAME} file removed\033[0m"

re:		fclean all

#library rules
library:	libft printf

libft:
	@echo "\033[94mcompiling libft :\033[0m"
	@make -s -C ../library/libft
	@echo "\033[1;33mlibft compiled\033[0m\n"

printf:
	@echo "\033[94mcompiling printf :\033[0m"
	@make -s -C ../library/printf
	@echo "\033[1;33mprintf compiled\033[0m\n"

#debug rules
debug:	library
	@${CC} ${CFLAGS} ${LIB} ${SRCS} -o ${NAME}-debug -g

sanitize:	library
	@${CC} ${CFLAGS} ${LIB} ${SRCS} -o ${NAME}-sanitize -g -fsanitize=address

.PHONY:		all clean fclean re debug sanitize bonus
