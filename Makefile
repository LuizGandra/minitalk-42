SERVER_NAME := server.exe
CLIENT_NAME := client.exe
CFLAGS := -Wall -Werror -Wextra
HEADERS := minitalk.h
LIBFT := libft
LIBS := -L$(LIBFT) -lft
SERVER_DIR := server
CLIENT_DIR := client
SERVER_SOURCES := $(SERVER_DIR)/server.c
CLIENT_SOURCES := $(CLIENT_DIR)/client.c
SERVER_OBJECTS := $(SERVER_SOURCES:.c=.o)
CLIENT_OBJECTS := $(CLIENT_SOURCES:.c=.o)

all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $< -o $@ $(LIBS)

$(CLIENT_NAME): $(CLIENT_OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $< -o $@ $(LIBS)

$(CLIENT_NAME)/%.o: $(CLIENT_NAME)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

$(SERVER_NAME)/%.o: $(SERVER_NAME)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

$(LIBFT):
	$(MAKE) -C $@

clean:
	$(RM) $(SERVER_OBJECTS) $(CLIENT_OBJECTS)
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	$(RM) $(SERVER_NAME) $(CLIENT_NAME)
	$(MAKE) -C $(LIBFT) fclean

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader

.PHONY: all libft clean fclean re norminette