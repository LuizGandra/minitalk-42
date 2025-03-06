CC := clang
CFLAGS := -Wall -Wextra -Werror
ARFLAGS := -rcs
RM := rm -rf

SRC_DIR := src
OBJ_DIR := ../build

INCLUDE_DIR := include

INCLUDES := -I$(INCLUDE_DIR)

HEADERS := $(INCLUDE_DIR)/ft_printf_bonus.h

SRCS := \
	ft_printf_bonus.c \
	ft_putchar_bonus.c \
	ft_putaddress_bonus.c \
	ft_puthex_bonus.c \
	ft_putnbr_bonus.c \
	ft_putstr_bonus.c \
	utils_bonus.c
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))
	
OBJS := $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

all: $(OBJ_DIR) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJ_DIR):
	mkdir -p $@

.PHONY: all