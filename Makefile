NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES = error_utils.c list_utils_1.c list_utils_2.c \
operations.c push_swap.c sort_utils_1.c sort_utils_2.c \
utils.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all