# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 23:27:53 by tmoragli          #+#    #+#              #
#    Updated: 2022/01/29 23:43:47 by tmoragli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRCS	=	srcs/so_long.c														\
			srcs/get_next_line.c												\
			srcs/parsing.c														\
			srcs/get_next_line_utils.c											\
			srcs/memory_allocs.c												\
			srcs/textures_init.c												\

INCLUDES	=	-Iincludes								\
				-Imlx

OBJS		=	$(SRCS:.c=.o)

CC			=	clang
RM			=	@rm -f

LD_FLAGS	=	-Lmlx -lbsd -lmlx -lXext -lX11 -lm -g -fsanitize=leak libft/libft.a
FLAGS		=	-Wall -Werror -Wextra $(INCLUDES) -g -D BONUS=0
LIBFT		=	libft/libft.a

.c.o:
				$(CC) -c $< -o $(<:.c=.o) $(FLAGS)

$(NAME):		start_message $(LIBFT) $(OBJS) start_link
				$(CC) $(OBJS) $(FLAGS) -o $(NAME) $(LD_FLAGS)
				@echo "\033[1;31mso_long\033[0m is ready to use!"

$(LIBFT):
				make -C libft -f Makefile

all:			$(NAME)

bonus:			add_flag re

add_flag:
			$(eval FLAGS := -D BONUS=1)

clean:
#					@clear
					@make -s -C libft -f Makefile clean
					@echo "\033[0;33mCleaning \033[1;31m$(NAME)\033[0;33m's objects\033[0m"
					$(RM) $(OBJS)

fclean:				clean
					@make -s -C libft -f Makefile fclean
					@echo "\033[0;33mRemoving \033[1;31m$(NAME)\033[0;33m.\033[0m"
					$(RM) $(NAME)

start_message:
#				@clear
				@echo "\033[0;31mMaking \033[1;31mso_long"
				@echo "\033[1;32mCompiling objects\033[0;32m"

start_link:
				@echo "\033[1;32mLinking all objects\033[0;32m"

re:				fclean all

.PHONY:			all clean fclean re