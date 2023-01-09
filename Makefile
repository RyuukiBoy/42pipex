NAME= pipex
CFLAGS= -Wall -Wextra -Werror

SRCS= pipex.c pipex_utils.c ft_split.c find_path.c 

SRC_BONUS = bonus_pipex/pipex_bonus.c \
			bonus_pipex/pipex_utils_bonus.c \
			bonus_pipex/find_path_bonus.c \
			bonus_pipex/GNL/gnl.c \
			bonus_pipex/GNL/gnl_u.c \
			ft_split.c bonus_pipex/here_doc.c \
			bonus_pipex/ft_strcmp.c \


OBJ       = $(SRCS:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	gcc $(CFLAGS) -o $(NAME) $(OBJ)

bonus: $(OBJ_BONUS)
	gcc $(CFLAGS) $(OBJ_BONUS) -o $(NAME)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all