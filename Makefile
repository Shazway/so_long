# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 23:27:53 by tmoragli          #+#    #+#              #
#    Updated: 2022/01/24 15:37:56 by tmoragli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRCS	=	srcs/so_long.c														\
			srcs/get_next_line.c												\
			srcs/parsing.c														\
			srcs/get_next_line_utils.c											\
			srcs/memory_allocs.c												\
			srcs/textures_init.c													\
			
LIBFTSRCS = ft_memccpy.c														\
			ft_memchr.c															\
			ft_memcmp.c															\
			ft_memcpy.c															\
			ft_memmove.c														\
			ft_memset.c															\
			ft_putchar_fd.c														\
			ft_putendl_fd.c														\
			ft_putnbr_fd.c														\
			ft_putstr_fd.c														\
			ft_split.c															\
			ft_strchr.c															\
			ft_strdup.c															\
			ft_strjoin.c														\
			ft_strlcat.c														\
			ft_strlcpy.c														\
			ft_strlen.c															\
			ft_strmapi.c														\
			ft_strncmp.c														\
			ft_strnstr.c														\
			ft_strrchr.c														\
			ft_strtrim.c														\
			ft_substr.c															\
			ft_tolower.c														\
			ft_toupper.c														\
			ft_atoi.c															\
			ft_bzero.c															\
			ft_calloc.c															\
			ft_isalnum.c														\
			ft_isalpha.c														\
			ft_isascii.c														\
			ft_isdigit.c														\
			ft_isprint.c														\
			ft_itoa.c															\
			ft_putnbrbase_fd.c													\
			ft_putnbru_fd.c														\
			ft_putnbrubase_fd.c													\
			ft_numlen.c															\
			get_next_line.c														\
			get_next_line_utils.c												\
			ft_strjoin_free.c													\
			ft_strcmp.c															\
			ft_lst_add_back.c													\
			ft_lstadd_front.c													\
			ft_lstclear.c														\
			ft_lstdelone.c														\
			ft_lstiter.c														\
			ft_lstlast.c														\
			ft_lstmap.c															\
			ft_lstnew.c															\
			ft_lstsize.c														\

MLXHEADER = mlx/mlx.h

LOCLIBREP = /usr/local/lib/

LOCLIBMLX	= ${LOCLIBREP}libmlx.a

LIBMLX_DIR = ./mlx/

LIBMLX	= ${LIBMLX_DIR}libmlx.a

LIBFTOBJS =${LIBFTSRCS:.c=.o}

OBJS	= ${SRCS:.c=.o}

CC		= gcc

LIBFT	= ./libft/libft.a

CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address

LIBFT_DIR = ./libft

LIBS	= -L${LIBMLX_DIR} -lmlx -lXext -lX11 -lm -L${LIBFT_DIR} -lft

RM		= rm -f

${NAME}:	${LIBFT} ${MLXHEADER} ${LIBMLX} ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}
	mv srcs/*.o objs

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${LIBFT}:
	@make -sC ./libft -j

${LOCLIBMLX}: ${LIBMLX}
	@echo allow creation of the mlx librairy
	@sudo cp ${LIBMLX} ${LOCLIBREP}

${LIBMLX}:
	@make -sC ./mlx

${LOCMLXHEADER}:
	@echo allow creation of the mlx.h header
	@sudo mv ./mlx/mlx.h /usr/local/include/

all:	${NAME}

clean:
	 ${RM} objs/*.o ${BONUSOBJS}

fclean:	clean
	${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
