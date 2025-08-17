NAME = span
CC = g++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

GREEN = \033[0;32m
BLUE = \033[0;34m
PURPLE = \033[0;35m
COLOUR_END = \033[0m

MAKEFLAGS += -s

SRCS = $(wildcard src/*.cpp) \
		main.cpp
OBJ_DIR = obj
OBJ = $(SRCS:src/%.cpp=$(OBJ_DIR)/%.o)

$(NAME): $(OBJ)
	@$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "$(PURPLE)EVERYTHING COMPILED!$(COLOUR_END)"

$(OBJ_DIR)/%.o: src/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)EVERYTHING CLEANED!$(COLOUR_END)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BLUE)EVERYTHING CLEANED COMPLETELY!$(COLOUR_END)"

re: fclean $(NAME)