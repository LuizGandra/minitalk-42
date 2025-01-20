CFLAGS := -Wall -Werror -Wextra
ARFLAGS := -rcs
RM := rm -rf
HEADERS := ft_printf_bonus.h
SOURCES := \
	ft_printf_bonus.c utils_bonus.c ft_putaddress_bonus.c ft_puthex_bonus.c \
	ft_putchar_bonus.c ft_putnbr_bonus.c ft_putstr_bonus.c
OBJECTS := $(SOURCES:.c=.o)

all: $(OBJECTS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader

.PHONY: all clean fclean re norm