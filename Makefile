CFLAGS = -Wall -Werror -Wextra -g

NAME = so_long

SRCS = srcs/main.c srcs/init.c srcs/key_hook.c \
	srcs/utils.c srcs/valid.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	gcc $(OBJS) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS) $(NAME)

re: fclean all
