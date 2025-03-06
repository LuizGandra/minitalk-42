CC := clang
CFLAGS := -Wall -Wextra -Werror
ARFLAGS := -rcs
RM := rm -rf

NAME := libft.a

FT_PRINTF_DIR = ft_printf

SRC_DIR := src
OBJ_DIR := build
FT_PRINTF_SRC_DIR := $(FT_PRINTF_DIR)/$(SRC_DIR)

INCLUDE_DIR := include
FT_PRINTF_INCLUDE_DIR := $(FT_PRINTF_DIR)/$(INCLUDE_DIR)

INCLUDES := -I$(INCLUDE_DIR) -I$(FT_PRINTF_INCLUDE_DIR) 

HEADERS := $(INCLUDE_DIR)/libft.h $(INCLUDE_DIR)/get_next_line_bonus.h

SRCS := \
	ft_abs.c \
	ft_atoi.c \
	ft_atol.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_clean_mem_grid.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_lstadd_back_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstmap_bonus.c \
	ft_lstnew_bonus.c \
	ft_lstsize_bonus.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strcmp.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strjoin_free.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	get_next_line_bonus.c
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))

FT_PRINTF_SRCS := \
	ft_printf_bonus.c \
	ft_putchar_bonus.c \
	ft_putaddress_bonus.c \
	ft_puthex_bonus.c \
	ft_putnbr_bonus.c \
	ft_putstr_bonus.c \
	utils_bonus.c

OBJS := $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

FT_PRINTF_OBJS := $(addprefix $(OBJ_DIR)/, $(notdir $(FT_PRINTF_SRCS:.c=.o)))

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF_OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJ_DIR):
	mkdir -p $@

$(FT_PRINTF_OBJS):
	$(MAKE) -C ft_printf

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader

.PHONY: all ft_printf clean fclean re norm
