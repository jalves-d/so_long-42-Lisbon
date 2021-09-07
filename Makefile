CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address

NAME = so_long

SRCS = srcs/main.c srcs/init.c srcs/key_hook.c srcs/errorwall.c\
	srcs/utils.c srcs/valid.c srcs/get_next_line.c srcs/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	gcc $(OBJS) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS) $(NAME)

re: fclean all
