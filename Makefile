NAME_CLIENT = client
NAME_SERVER = server

C_BONUS = client_bonus
S_BONUS = server_bonus

CC = gcc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC_CLIENT = client.c func_client.c
SRC_SERVER = server.c func_server.c

BONUS_CLIENT = client_bonus.c func_client_bonus.c
BONUS_SERVER = server_bonus.c func_server_bonus.c

OBJS_CLIENT = $(SRC_CLIENT:.c=.o)
OBJS_SERVER = $(SRC_SERVER:.c=.o)

OBONUS_CLIENT = $(BONUS_CLIENT:.c=.o)
OBONUS_SERVER = $(BONUS_SERVER:.c=.o)

all: $(NAME_CLIENT) $(NAME_SERVER)

bonus: $(C_BONUS) $(S_BONUS)

$(NAME_CLIENT): $(OBJS_CLIENT)
		$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER)
		$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER)

$(C_BONUS): $(OBONUS_CLIENT)
		$(CC) $(CFLAGS) -o $(C_BONUS) $(OBONUS_CLIENT)

$(S_BONUS): $(OBONUS_SERVER)
		$(CC) $(CFLAGS) -o $(S_BONUS) $(OBONUS_SERVER)

clean:
		$(RM) $(OBJS_CLIENT) $(OBJS_SERVER) $(OBONUS_CLIENT) $(OBONUS_SERVER)

fclean: clean
		$(RM) $(NAME_CLIENT) $(NAME_SERVER) $(C_BONUS) $(S_BONUS)

re: fclean all
