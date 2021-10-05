CC 		:= 	gcc
FLAGS 	:= 	-Wall -Wextra -Werror
BUFFER 	:=	42
RM		:=	rm -f

NAME	:=	./mandatory/get_next_line.a
BONUS_N :=	./bonus/get_next_line_bonus.a

SRCS	:= 	./mandatory/get_next_line.c ./mandatory/get_next_line_utils.c
BONUS_S :=	./bonus/get_next_line_bonus.c ./bonus/get_next_line_utils_bonus.c

OBJS	:=	$(SRCS:.c=.o)
BONUS_O :=	$(BONUS_S:.c=.o)


$(NAME):	$(SRCS) $(OBJS)
			ar -rcs $(NAME) $(OBJS)
			$(CC) $(FLAGS) main.c $(NAME) && ./a.out
			@printf "\033[1m\033[32m[OK]\033[0m Aparently its works\n"

$(BONUS_N): $(BONUS_S) $(BONUS_O)
			ar -rcs $(BONUS_N) $(BONUS_O)
			$(CC) $(FLAGS) main.c $(BONUS_N) && ./a.out
			@printf "\033[1m\033[32m[OK]\033[0m Aparently its works\n"


all:		$(NAME)

bonus:		$(BONUS_N)

.c.o:
			$(CC) $(FLAGS) -D BUFFER_SIZE=$(BUFFER) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJS) a.out $(BONUS_O)

fclean: 	clean
			$(RM) $(NAME) $(BONUS_N)

re:			fclean all

rebonus:	fclean bonus

.PHONY: 	all clean fclean re
