
NAME	=	push_swap
CC	=	clang
FLAGS	=	-Wall -Werror -Wextra
SRCS	=	srcs/actions1.c srcs/actions2.c srcs/actions3.c srcs/dlist.c srcs/dlist2.c srcs/dlist3.c srcs/main.c srcs/parse_utils.c srcs/sort.c srcs/sort1.c srcs/sort2.c srcs/sort_utils.c
INCS	=	$(addprefix includes/, push_swap.h)
OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): ${OBJS} $(INCS)
	$(CC) $(FLAGS) -I includes -o $(NAME) $(OBJS)

%.o: %.c $(INCS)
	$(CC) $(FLAGS) -I includes -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
