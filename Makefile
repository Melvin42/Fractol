## Name of Project

NAME = fractol

## Color for compilating (pink)

COLOR = \0033[1;35m

## List of Directories

LIB = libft/libft.a
LIB_DIR = libft
LIBX_DIR = minilibx
BONUS_DIR = bonus
INC_DIR = inc
OBJ_DIR = obj
SRC_DIR	= src

# Add dirs here

CONTROL_DIR	= control
FRACTALS_DIR= fractals
UTILS_DIR	= utils
PARSING_DIR	= parsing

## Compilating Utilities

FAST = -Ofast

#DEBUG = -g3 -fsanitize=address

FLAGS = -Wall -Wextra -Werror $(FAST) $(DEBUG) -D_REENTRANT

INC = $(./$(INC_DIR)/-I%.h)

CC = clang $(FLAGS) $(INC)

INSTALL_LIBX = $(shell cd minilibx && sh configure && cd ..)

UTILS_FT		= mlx_utils error free

PARSING_FT		= args

CONTROL_FT		= control control_two change_constant zoom mouse_control print_vars

FRACTALS_FT		= mandelbrot julia dragon_curve bship

SRC_FT 			= main launch color renders loops

## List of Utilities

SRC = $(SRC_FT:%=$(SRC_DIR)/%.c) \
	$(UTILS_FT:%=$(SRC_DIR)/$(UTILS_DIR)/%.c) \
	$(PARSING_FT:%=$(SRC_DIR)/$(PARSING_DIR)/%.c) \
	$(CONTROL_FT:%=$(SRC_DIR)/$(CONTROL_DIR)/%.c) \
	$(FRACTALS_FT:%=$(SRC_DIR)/$(FRACTALS_DIR)/%.c)

OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

OBJ_DIRS = $(OBJ_DIR) \
	$(UTILS_DIR:%=$(OBJ_DIR)/%) \
	$(PARSING_DIR:%=$(OBJ_DIR)/%) \
	$(CONTROL_DIR:%=$(OBJ_DIR)/%) \
	$(FRACTALS_DIR:%=$(OBJ_DIR)/%)


## Rules of Makefile

all: $(NAME)
	@echo "$(COLOR)$(NAME) \033[100D\033[40C\0033[1;30m[All OK]\0033[1;37m"

bonus: $(LIB)
	@echo "$(COLOR)$(NAME) \033[100D\033[40C0033[1;30m[All OK]\0033[1;37m"
	@make -s -C $(BONUS_DIR)

$(OBJ_DIRS):
	@mkdir -p $@
	@echo "$(COLOR)$@ \033[100D\033[40C\0033[1;32m[Created]\0033[1;37m"
	@echo "$(COLOR)Creating :\t\0033[0;32m$@\0033[1;37m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	@$(CC) -c $< -o $@
	@echo "$(COLOR)$(@:$(OBJ_DIR)/%=%) \033[100D\033[40C\0033[1;32m[Compiled]\0033[1;37m"

$(NAME):  $(LIB) $(OBJ_DIRS) $(SRC) $(INC)
	@$(MAKE) -j -s $(OBJ)
	@echo "$(COLOR)Objects \033[100D\033[40C\0033[1;32m[Created]\0033[1;37m"
	@$(CC) $(OBJ) -Llibft -lft -Lminilibx -lmlx -lmlx_Linux -lXext -lX11 -lm -o $@
	@echo "$(COLOR)$(NAME) \033[100D\033[40C\0033[1;32m[Created]\0033[1;37m"

$(LIB):
	@make -s -C $(LIB_DIR)
	@echo $(INSTALL_LIBX)

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -s -C $(LIBX_DIR)
	@make clean -s -C $(LIB_DIR)
	@echo "$(COLOR)Objects \033[100D\033[40C\0033[1;31m[Removed]\0033[1;37m"

fclean: clean
	@rm -f $(NAME)
	@echo "$(COLOR)$(NAME) \033[100D\033[40C\0033[1;31m[Removed]\0033[1;37m"
	@make fclean -s -C $(LIB_DIR)

re:	fclean all

define print_aligned_coffee
    @t=$(NAME); \
	l=$${#t};\
	i=$$((8 - l / 2));\
	echo "             \0033[1;32m\033[3C\033[$${i}CAnd Your program \"$(NAME)\" "
endef

coffee: all clean
	@echo ""
	@echo "                                {"
	@echo "                             {   }"
	@echo "                              }\0033[1;34m_\0033[1;37m{ \0033[1;34m__\0033[1;37m{"
	@echo "                           \0033[1;34m.-\0033[1;37m{   }   }\0033[1;34m-."
	@echo "                          \0033[1;34m(   \0033[1;37m}     {   \0033[1;34m)"
	@echo "                          \0033[1;34m| -.._____..- |"
	@echo "                          |             ;--."
	@echo "                          |            (__  \ "
	@echo "                          |             | )  )"
	@echo "                          |   \0033[1;96mCOFFEE \0033[1;34m   |/  / "
	@echo "                          |             /  / "
	@echo "                          |            (  / "
	@echo "                          \             | "
	@echo "                            -.._____..- "
	@echo ""
	@echo ""
	@echo "\0033[1;32m\033[3C                    Take Your Coffee"
	$(call print_aligned_coffee)

.PHONY: all bonus clean fclean re coffee
