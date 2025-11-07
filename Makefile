
NAME = libvectors.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS = src/vectors.c
OBJS = $(SRCS:.c=.o)

EXAMPLE = example
EXAMPLE_SRCS = src/example.c
EXAMPLE_OBJS = $(EXAMPLE_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(EXAMPLE): $(NAME) $(EXAMPLE_OBJS)
	$(CC) $(CFLAGS) $(EXAMPLE_OBJS) -L. -lvectors -o $(EXAMPLE)

clean:
	$(RM) $(OBJS) $(EXAMPLE_OBJS)

fclean: clean
	$(RM) $(NAME) $(EXAMPLE)

re: fclean all

test: $(EXAMPLE)
	./$(EXAMPLE)

.PHONY: all clean fclean re test
