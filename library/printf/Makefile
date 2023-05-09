SRCS		=	ft_printf.c \
				ft_handle_format.c \
				ft_printchar.c \
				ft_printstr.c \
				ft_printptr.c \
				ft_printnbr.c \
				ft_printbase.c \
				pf_strlen.c \

NB_SRCS	=	$(words $(SRCS))

OBJS		=	${SRCS:.c=.o}

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

NAME		= libftprintf.a

#rules

all:		${NAME}

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

${NAME}:	${OBJS}
		@echo ""
		@cat .loading_bar
		@printf "\033[C✅\n"
		@echo "\033[1;32mcompiled\033[0m"
		@ar rcs ${NAME} ${OBJS}
		@ranlib ${NAME}
		@echo $$'\033[33mft_printf compiled successfully'

clean:
		@rm -f ${OBJS} .loading_bar
		@echo $$'\033[31mremoving ft_printf object files'

fclean:		clean
		@rm -f ${NAME}
		@echo $$'\033[31mremoving libftprintf.a'

re:			fclean all

.PHONY: all clean fclean re
