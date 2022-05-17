#Name
NAME 		= 	push_swap

#Commands
CC			= 	gcc
DMK			=	mkdir -p
RM			=	rm -rf
AR			=	ar rc
MK			=	make -s -C

#Compilation flags
INCLUDES	=	-I$(H_DIR) -I$(LFT_DIR)includes
FLAGS		=	$(WFLAGS) #) $(MEM_FLAGS)
WFLAGS		=	-Wall -Werror -Wextra
MEM_FLAGS	=	-g3 -fsanitize=address

#Directories
H_DIR		=	includes/
SRC_DIR		=	src/
OBJ_DIR		=	obj/
LFT_DIR		=	libft/

#Libft
MK_LFT		=	$(MK) $(LFT_DIR)
LFT			=	$(LFT_DIR)libft.a

#Source files
SRC_FILES	=	push_swap.c\
				ps_debug.c\
				ps_init.c\

OBJ_FILES	=	$(SRC_FILES:.c=.o)

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

#---------------------#

all:	${NAME}

libft:
			@echo -n "\n"
			@echo -n "COMPILING LIBFT..."
			@$(MK_LFT)
			@echo "\033[32m\t\t[OK]\033[0m\n"

$(NAME):	libft $(OBJS)
			@echo -n "\n"
			@echo -n "COMPILING PUSH_SWAP..."
			@$(CC) $(OBJS) $(LFT) -o $@ $(FLAGS) 
			@echo "\033[32m\t\t[OK]\033[0m\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
				@$(DMK) $(OBJ_DIR)
				@$(CC) -c  $(INCLUDES) $< -o $@ $(FLAGS)
clean:
	@$(MK_LFT) clean
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(MLX) $(LFT)
	@$(MK_LFT) fclean

re: fclean all

.PHONY: all libft clean fclean re