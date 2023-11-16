CC = clang

CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=42 -g

SRCS = get_next_line_utils.c \
		get_next_line.c

OBJS = $(SRCS:.c=.o)

NAME = libget_next_line.a

all: $(NAME)

$(NAME): $(OBJS)
	ar cr $(NAME) $(OBJS)
	$(CC) $(CFLAGS) main.c -I . -lget_next_line
	make clean
	valgrind ./a.out

%.o: %.c $(SRCS)
	${CC} ${CFLAGS} -o $@ -c $<

clean:
	rm -rf  $(OBJS)
	
fclean: clean
	rm -rf $(NAME)
	
re: fclean all

.PHONY: all clean fclean re