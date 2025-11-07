
CC     = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

NAME    = libvectors.a
OBJ_DIR = objects

SRCS = $(wildcard src/*.c)

OBJS = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

TEST_SRC = test/test.c
TEST_BIN = test_vectors

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

test: $(NAME)
	$(CC) $(CFLAGS) $(TEST_SRC) -L. -lvectors -o $(TEST_BIN)
	./$(TEST_BIN)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(TEST_BIN)

re: fclean all

.PHONY: all clean fclean re test
