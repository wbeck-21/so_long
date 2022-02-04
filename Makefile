NAME		=	so_long

B_NAME      =	so_long_bonus

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

MLX			=	mlx/Makefile.gen

LFT			=	libft/libft.a

INC			=	-I ./libft -I ./mlx #makefiles

LIB			=	-L ./libft -lft -L ./mlx -lmlx -lXext -lX11 -lm

SRCS		=	mandatory/srcs/so_long.c mandatory/srcs/events.c \
				mandatory/srcs/map_size.c mandatory/srcs/check_valid_map.c \
				mandatory/srcs/map_processor.c mandatory/srcs/create_map.c \
				mandatory/srcs/get_position.c mandatory/srcs/render_images.c \
				mandatory/srcs/update.c mandatory/srcs/move.c mandatory/srcs/exit_game.c

B_SRCS		=	bonus/srcs/so_long_bonus.c bonus/srcs/events_bonus.c \
				bonus/srcs/map_size_bonus.c bonus/srcs/check_valid_map_bonus.c \
				bonus/srcs/map_processor_bonus.c bonus/srcs/create_map_bonus.c \
				bonus/srcs/get_position_bonus.c bonus/srcs/render_images_bonus.c \
				bonus/srcs/update_bonus.c bonus/srcs/move_bonus.c bonus/srcs/exit_game_bonus.c

OBJS		=	$(SRCS:.c=.o)

B_OBJS		=	$(B_SRCS:.c=.o)

LIBH	=	./mandatory/so_long.h

B_LIBH	=	./bonus/so_long_bonus.h

RM			=	rm -rf

all:		$(MLX) $(NAME)

bonus:		fclean $(MLX) $(B_NAME)

$(NAME):	$(OBJS)
			rm -rf $(NAME)
			make -s -C libft
			$(CC) $(FLAGS) -fsanitize=address -o $(NAME) $? $(LIB)

$(B_NAME):	$(B_OBJS)
			rm -rf $(NAME)
			make -s -C libft
			$(CC) $(FLAGS) -fsanitize=address -o $(NAME) $? $(LIB)

$(MLX):
			make -s -C mlx

%.o:	%.c 
			$(CC) $(FLAGS) $(INC) -o $@ -c $<

%_bonus.o:	%_bonus.c ${B_LIBH}
			$(CC) $(FLAGS) $(INC) -o $@ -c $<


clean:
			@make -s $@ -C libft
			@$(RM) $(OBJS) $(B_OBJS)

fclean:		clean
			@make -s $@ -C libft
			@$(RM) $(NAME) $(B_NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re