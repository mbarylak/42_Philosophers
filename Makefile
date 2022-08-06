SRCS	=	atoi.c	main.c error.c utils.c create_philo.c routine.c

OBJS 	=	$(SRCS:.c=.o)

NAME 	=	philo

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra -pthread

INCLUDE	=	philo.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) 

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
