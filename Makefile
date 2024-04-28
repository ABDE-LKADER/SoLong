# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 17:23:22 by abadouab          #+#    #+#              #
#    Updated: 2024/04/27 15:38:01 by abadouab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

SRCS		=	mandatory/moves.c   \
				mandatory/so_long.c  \
				mandatory/parce_in.c  \
				mandatory/set_keys.c   \
				mandatory/allocate.c    \
				mandatory/load_img.c     \
				mandatory/mlx_space.c

OBJS		=	$(SRCS:.c=.o)

HEADER		=	mandatory/so_long.h

MYLB		=	MYLIB
MYAR		=	MYLIB/libar.a

MLX			=	MLX42/MLX
GLFW		=	/Users/abadouab/.brew/opt/glfw/lib
MXAR		=	$(MLX)/libmlx42.a

FLAGS		=	cc
RM			=	rm -fr

GREEN		=	"\033[1;32m"
YELOW 		=	"\033[1;33m"
REDCL 		=	"\033[1;31m"
RESET 		=	"\033[0m"

all: $(MLX) start $(MYLB) $(NAME) finish

start:
	@printf "\n"
	@echo $(GREEN)"Starting build..."
	@sleep 1
	@printf "Loading [ "

finish:
	@echo $(GREEN) ] 100%$(RESET)
	@echo $(GREEN)Project built.$(RESET)
	@printf "\n"

$(MLX):
	@echo $(GREEN)MINILIBX Building ...$(RESET)
	@cd MLX42; cmake -B MLX
	@make -C $(MLX) --no-print-directory

$(MYLB):
	@make -C $(MYLB) --no-print-directory

$(NAME): $(OBJS)
	@$(FLAGS) $^ -L$(MYLB) -lar -L$(MLX) -lmlx42 -L$(GLFW) -lglfw -o $(NAME)

$(OBJS): %.o: %.c $(HEADER) $(MYAR) $(MXAR)
	@$(FLAGS) -c -I $(MYLB) -I MLX42/include/MLX42 $< -o $@
	@printf $(GREEN)"."$(RESET)

clean:
	@$(RM) $(OBJS)
	@make clean -C $(MYLB) --no-print-directory
	@echo $(YELOW)Cleaning up 🧹💫$(RESET)

fclean: clean
	@$(RM) $(MLX)
	@$(RM) $(NAME)
	@make fclean -C $(MYLB) --no-print-directory
	@echo $(REDCL)Purging all files 🗑️$(RESET)

re: fclean all

.PHONY: $(MLX) $(MYLB)
