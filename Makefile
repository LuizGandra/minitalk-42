SERVER_NAME := server
CLIENT_NAME := client
CFLAGS := -Wall -Werror -Wextra
HEADERS := minitalk.h
LIBFT := libft
LIBS := -L$(LIBFT) -lft
INCLUDES := -I$(LIBFT)/include -I$(LIBFT)/ft_printf/include -I.
SRC_DIR := src
SERVER_SOURCES := $(SRC_DIR)/server.c
CLIENT_SOURCES := $(SRC_DIR)/client.c
SERVER_OBJECTS := $(SERVER_SOURCES:.c=.o)
CLIENT_OBJECTS := $(CLIENT_SOURCES:.c=.o)
# BONUS
BONUS_DIR := bonus
SERVER_NAME_BONUS := server_bonus
CLIENT_NAME_BONUS := client_bonus
HEADERS_BONUS := minitalk_bonus.h
SERVER_SOURCES_BONUS := $(BONUS_DIR)/server_bonus.c
CLIENT_SOURCES_BONUS := $(BONUS_DIR)/client_bonus.c
SERVER_OBJECTS_BONUS := $(SERVER_SOURCES_BONUS:.c=.o)
CLIENT_OBJECTS_BONUS := $(CLIENT_SOURCES_BONUS:.c=.o)

all: $(LIBFT) $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJECTS)
	$(CC) $(CFLAGS) $< -o $@ $(LIBS)

$(CLIENT_NAME): $(CLIENT_OBJECTS)
	$(CC) $(CFLAGS) $< -o $@ $(LIBS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(LIBFT) $(SERVER_NAME_BONUS) $(CLIENT_NAME_BONUS)

$(SERVER_NAME_BONUS): $(SERVER_OBJECTS_BONUS)
	$(CC) $(CFLAGS) $< -o $@ $(LIBS)

$(CLIENT_NAME_BONUS): $(CLIENT_OBJECTS_BONUS)
	$(CC) $(CFLAGS) $< -o $@ $(LIBS)

$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c $(BONUS_HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $@

clean:
	$(RM) $(SERVER_OBJECTS) $(CLIENT_OBJECTS) $(SERVER_OBJECTS_BONUS) $(CLIENT_OBJECTS_BONUS)
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	$(RM) $(SERVER_NAME) $(CLIENT_NAME) $(SERVER_NAME_BONUS) $(CLIENT_NAME_BONUS)
	$(MAKE) -C $(LIBFT) fclean

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader

.PHONY: all bonus libft clean fclean re norminette