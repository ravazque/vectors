
NAME = libvectors.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS = src/vectors.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(EXAMPLE_OBJS)

fclean: clean
	$(RM) $(NAME) $(EXAMPLE)

re: fclean all

.PHONY: all clean fclean re test
