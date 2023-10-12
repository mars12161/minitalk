# Files
SERVER		=	ft_server.c

CLIENT		=	ft_client.c

PRINTF		=	cd ft_printf && make

LIB			=	ft_printf/libftprintf.a

# Sources and objects
SERVER_SRC	=	$(SERVER)

SERVER_OBJS	=	$(SERVER_SRC:.c=.o)

CLIENT_SRC	=	$(CLIENT)

CLIENT_OBJS	=	$(CLIENT_SRC:.c=.o)

OBJS		=	$(CLIENT_OBJS) \
				$(SERVER_OBJS)

# ------------------------------ Constant strings ------------------------------

GCC			=	cc

FLAGS		=	-Wall -Wextra -Werror

SERVER_NAME	=	server

CLIENT_NAME	=	client

NAME		=	server


# ------------------------------ Rules ------------------------------


all: start $(SERVER_NAME) $(CLIENT_NAME)

start:
	@$(PRINTF)

$(SERVER_NAME): $(SERVER_OBJS)
	@$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIB) -o $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_OBJS)
	@$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIB) -o $(CLIENT_NAME)

clean:
	rm -rf $(OBJS)
	@cd ft_printf && make --silent clean

fclean: clean
	rm -rf $(SERVER_NAME) $(CLIENT_NAME)
	@cd ft_printf && make --silent fclean

re:	fclean all

.PHONY: all clean fclean re 
