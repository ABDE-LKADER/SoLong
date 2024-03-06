# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 17:23:22 by abadouab          #+#    #+#              #
#    Updated: 2024/02/22 10:44:26 by abadouab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
SRCS		=	mandatory/so_long.c \
				mandatory/parce_in.c

OBJS		=	$(SRCS:.c=.o)

HEADER		=	mandatory/so_long.h

MYLB		=	MYLIB
MYAR		=	MYLIB/libar.a

FLAGS		=	cc -Wall -Wextra
RM			=	rm -fr

GREEN		=	"\033[1;32m"
YELOW 		=	"\033[1;33m"
REDCL 		=	"\033[1;31m"
RESET 		=	"\033[0m"

all: $(MYLB) $(NAME)
	@echo $(GREEN)Done !!$(RESET)

$(MYLB):
	@make -C $(MYLB) --no-print-directory

$(NAME): $(OBJS)
	$(FLAGS) $^ -L$(MYLB) -lar -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(OBJS): %.o: %.c $(HEADER) $(MYAR)
	$(FLAGS) -c -I $(MYLB) -I/usr/include -Imlx_linux -O3 $< -o $@

clean:
	@$(RM) $(OBJS)
	@make clean -C $(MYLB) --no-print-directory
	@echo $(YELOW)Done !!$(RESET)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(MYLB) --no-print-directory
	@echo $(REDCL)Done !!$(RESET)

re: fclean all

.PHONY: $(MYLB)
