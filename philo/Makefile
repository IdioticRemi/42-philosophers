# Program name
NAME	= philo
NAME^^	= $(shell echo $(NAME) | tr 'a-z' 'A-Z')

# Directories

INC_DIR	= inc/
SRC_DIR	= src/
OBJ_DIR	= obj/
SUBDIRS = $(addprefix $(OBJ_DIR), $(shell find . -mindepth 1 -type d -path "./src/*" | cut -c 7-))

# Sources
__SRCS	= $(shell find . -type f -path "./src/*.c" | cut -c 7-)

SRCS	= $(addprefix $(SRC_DIR), $(__SRCS))
OBJS	= $(addprefix $(OBJ_DIR), $(__SRCS:.c=.o))

# Compile
CC		= clang

CFLAGS	= -Wall -Werror -Wextra #-fsanitize=thread
INCLUDE	= -I $(INC_DIR)
LIBS	= -lpthread

# Color

RESET	= \033[0;0m
FG_WHIT	= \033[0;97m
FG_GRAY	= \033[0;37m
FG_MAGE	= \033[0;35m
FG_CYAN	= \033[0;36m
FG_GREE	= \033[0;32m
FG_REDD	= \033[0;31m

# Rules
all: log $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_DIR)/$(NAME).h
	@mkdir -p $(OBJ_DIR) $(SUBDIRS)
	@printf "$(FG_GRAY)[ $(NAME^^) ] $(FG_WHIT)$@ $(FG_CYAN)\033[40G[.]$(RESET)\r"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@printf "$(FG_GRAY)[ $(NAME^^) ] $(FG_WHIT)$@ $(FG_GREE)\033[40G[✓]$(RESET)\n"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $(NAME) $(LIBS)
	@printf "$(FG_GRAY)[ $(NAME^^) ] $(FG_GREE)Built '$(NAME)'.$(RESET)\n"

log:
	@printf "$(FG_GRAY)[ $(NAME^^) ] $(FG_CYAN)Starting build process.$(RESET)\n"

clean:
	@rm -rf $(OBJ_DIR)
	@printf "$(FG_GRAY)[ $(NAME^^) ] $(FG_MAGE)Build objects cleaned.$(RESET)\n"

fclean:
	@rm -rf $(NAME) $(OBJ_DIR)
	@printf "$(FG_GRAY)[ $(NAME^^) ] $(FG_MAGE)Program files cleaned.$(RESET)\n"

re: fclean all

.PHONY: all log clean fclean re