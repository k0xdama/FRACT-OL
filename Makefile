# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 18:05:18 by pmateo            #+#    #+#              #
#    Updated: 2024/03/18 07:17:14 by pmateo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Werror -Wextra -Wall -g3 -g
RM = rm -f
.DEFAULT_GOAL := all

NAME = fractol

DIR_MLX = ./minilibx-linux
MLX = ${DIR_MLX}/libmlx.a

DIR_LIBFT = ./LIBFT
LIBFT = ${DIR_LIBFT}/libft.a

DIRINC_FRACTOL = ./INCLUDES
DIRINC_LIBFT = ${DIR_LIBFT}/INCLUDES
DIRINC_MLX = ${DIR_MLX}
INCFILES = ${DIRINC_FRACTOL}/fractol.h

DIR_SRCS = ./SRCS/
SRCS =				main.c ini.c \
					render.c utils.c \
					utils_maths.c error.c \
					mandelbrot.c julia.c mandelbox.c

OBJ = ${SRCS:.c=.o}

%.o: ${DIR_SRCS}%.c ${INCFILES}
	@${CC} ${FLAGS} -c $< -o $@ -I ${DIRINC_FRACTOL} -I ${DIRINC_LIBFT} -I ${DIRINC_MLX}

${LIBFT}:
	@${MAKE} -s -C ${DIR_LIBFT}

${MLX}:
	@${MAKE} -s -C ${DIR_MLX}

${NAME}: ${OBJ} ${LIBFT} ${MLX} ${INCFILES}
	@${CC} ${FLAGS} -o ${NAME} ${OBJ} -I ${DIRINC_FRACTOL} -I ${DIRINC_LIBFT} -I ${DIRINC_MLX} -L ${DIR_MLX} -lXext -lX11 -lmlx -lm -L ${DIR_LIBFT} -lft

all: ${LIBFT} ${MLX} ${NAME}

bonus: all

clean:
		@${MAKE} -s -C ${DIR_LIBFT} clean
		@${MAKE} -s -C ${DIR_MLX} clean
		@${RM} ${OBJ}
		@echo "\033[1;9;35m# No more object files. #\033[0m"

fclean: clean
		@${MAKE} -s -C ${DIR_LIBFT} fclean
		@${RM} ${NAME}
		@echo "\033[1;9;35m# No more executable files. #\033[0m"

re: fclean all

.PHONY: all re clean fclean