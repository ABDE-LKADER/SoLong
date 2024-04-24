# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 17:23:22 by abadouab          #+#    #+#              #
#    Updated: 2024/03/27 15:51:34 by abadouab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

SRCS		=	mandatory/moves.c   \
				mandatory/so_long.c  \
				mandatory/parce_in.c  \
				mandatory/mlx_init.c   \
				mandatory/load_png.c    \
				mandatory/set_keys.c     \
				mandatory/mlx_space.c

OBJS		=	$(SRCS:.c=.o)

HEADER		=	mandatory/so_long.h

MYLB		=	MYLIB
MYAR		=	MYLIB/libar.a

MLX			=	MLX42/MLX
GLFW		=	/Users/abadouab/.brew/opt/glfw/lib

FLAGS		=	cc -Wall -Wextra
RM			=	rm -fr

GREEN		=	"\033[1;32m"
YELOW 		=	"\033[1;33m"
REDCL 		=	"\033[1;31m"
RESET 		=	"\033[0m"

all: $(MLX) $(MYLB) $(NAME)

$(MLX):
	@cd MLX42; cmake -B MLX
	@make -C $(MLX) --no-print-directory

$(MYLB):
	@make -C $(MYLB) --no-print-directory

$(NAME): $(OBJS)
	@$(FLAGS) $^ -L$(MYLB) -lar -L$(MLX) -lmlx42 -L$(GLFW) -lglfw -o $(NAME)

$(OBJS): %.o: %.c $(HEADER) $(MYAR)
	@$(FLAGS) -c -I $(MYLB) -I MLX42/include/MLX42 $< -o $@

clean:
	@$(RM) $(OBJS)
	@make clean -C $(MYLB) --no-print-directory

fclean: clean
	@$(RM) $(NAME)
	@make clean -C $(MLX) --no-print-directory
	@make fclean -C $(MYLB) --no-print-directory

re: fclean all

.PHONY: $(MYLB) $(MLX)
