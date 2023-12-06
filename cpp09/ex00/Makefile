BLACK   := \033[30;1m
RED     := \033[31;1m
GREEN   := \033[32;1m
YELLOW  := \033[33;1m
BLUE    := \033[34;1m
MAGENTA := \033[35;1m
CYAN    := \033[36;1m
WHITE   := \033[37;1m
RESET   := \033[0m

NAME = btc

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
# -fsanitize=address -g3

INCLUDE_DIR = ./include
HEADERS = -I $(INCLUDE_DIR)

SRC_DIR = ./src/
SRC = \
BitcoinExchange.cpp \
Database.cpp \
Parser.cpp \
main.cpp
SRCS = $(addprefix $(SRC_DIR),$(SRC))

OBJ_DIR = ./obj/
OBJS = $(patsubst $(SRC_DIR)%.cpp,$(OBJ_DIR)%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) && \
	echo "$(WHITE)Compilation of $(CYAN)>>$(NAME)<<$(RESET)$(WHITE) successful!$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re