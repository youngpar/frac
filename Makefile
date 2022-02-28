# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 23:10:03 by youngpar          #+#    #+#              #
#    Updated: 2022/02/28 23:10:06 by youngpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CLFAGS		= -Wall -Wextra -Werror

NAME		= fractol

GRAPHIC		= -framework Metal -framework Metalkit

LIBFT		= ft
MLX			= mlx

MLXDIR		= mlx
LIBFTDIR	= libft

INCLUDE		= ./include

SRCSDIR		= srcs
BSRCSDIR	= bonus

SRCSFILE	= main.c \
			  hook.c \
			  image.c \
			  window.c \
			  mandelbrot.c \
			  julia.c

BSRCSFILE	= main_bonus.c \
			  hook_bonus.c \
			  image_bonus.c \
			  window_bonus.c \
			  mandelbrot_bonus.c \
			  julia_bonus.c

SRCS		= $(addprefix $(SRCSDIR)/, $(SRCSFILE))
BSRCS		= $(addprefix $(BSRCSDIR)/, $(BSRCSFILE))

OBJS		= $(SRCS:.c=.o)
BOBJS		= $(BSRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

all			: $(NAME)

$(NAME)		: lib $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I $(INCLUDE) -L. -l$(LIBFT) -l$(MLX) $(GRAPHIC) -o $(NAME)

bonus		: lib $(BOBJS)
	$(CC) $(CFLAGS) $(BOBJS) -I $(INCLUDE) -L. -l$(LIBFT) -l$(MLX) $(GRAPHIC) -o $(NAME)

lib			:
	@make -C $(LIBFTDIR)
	@make -C $(MLXDIR)
	cp $(LIBFTDIR)/libft.a ./
	cp $(MLXDIR)/libmlx.dylib ./

clean		:
	rm -rf $(OBJS) $(BOBJS) libmlx.dylib libft.a
	@make clean -C $(LIBFTDIR)
	@make clean -C $(MLXDIR)

fclean		: clean
	rm -rf $(NAME)
	@make fclean -C $(LIBFTDIR)

re			: fclean all

.PHONY		: all fclean clean re bonus lib
