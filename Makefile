NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = client.c server.c utils.c
OBJS = $(SRCS:.c=.o)
BONUS_SRCS = *_bonus.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
RM = rm -rf
AR = ar -rcs
LIBFT = -L libft -l ft

all: client server

bonus: client_bonus server_bonus

client: $(OBJS)
	$(CC) $(CFLAGS) client.o $(LIBFT) -o client

client_bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) client_bonus.o utils_bonus.o $(LIBFT) -o client_bonus

server: $(OBJS)
	$(CC) $(CFLAGS) server.o utils.o $(LIBFT) -o server

server_bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) server_bonus.o $(LIBFT) -o server_bonus

$(OBJS): $(SRCS)
	make -C libft -s
	$(CC) $(CFLAGS) -c $(SRCS)

$(BONUS_OBJS): $(BONUS_SRCS)
	make -C libft -s
	$(CC) $(CFLAGS) -c $(BONUS_SRCS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	make clean -C libft -s

fclean:
	$(RM) $(OBJS) $(BONUS_OBJS) client client_bonus server server_bonus
	make clean -C libft -s

re: fclean all

re_bonus: fclean bonus
