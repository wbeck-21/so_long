NAME		=	so_long

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

MLX			=	mlx/Makefile.gen

LFT			=	libft/libft.a

INC			=	-I ./libft -I ./mlx #makefiles

LIB			=	-L ./libft -lft -L ./mlx -lmlx -lXext -lX11 -lm

SRC			=	srcs/so_long.c srcs/events.c \
				srcs/map_size.c srcs/map_isvalid.c \
				srcs/map_processor.c srcs/create_map.c \
				srcs/get_position.c srcs/render_images.c \
				srcs/update.c srcs/move.c

OBJ			=	$(SRC:.c=.o)

RM			=	rm -rf

all:		$(MLX) $(NAME)

$(NAME):	$(OBJ)
			@make -s -C libft
			$(CC) $(FLAGS) -o $(NAME) $^ $(LIB)

$(MLX):
			@make -s -C mlx

%.o:	%.c
			$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
			@make -s $@ -C libft
			@$(RM) $(OBJ)

fclean:		clean
			@make -s $@ -C libft
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re