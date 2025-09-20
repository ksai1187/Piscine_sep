# ex00/Makefile
NAME    = rush-02
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
INCS    = -I includes
SRCS    = srcs/main.c  srcs/dict_emit.c srcs/to_struct.c srcs/string.c srcs/emit.c srcs/number_to_words.c srcs/three_digits.c srcs/util_num.c srcs/util_str.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
