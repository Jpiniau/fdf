# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/03 13:52:39 by jpiniau           #+#    #+#              #
#    Updated: 2015/12/22 15:06:25 by jpiniau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Werror -Wextra

INCLUDES = libft/includes 

INCLUDES2 = minilibx_macos

SRC_PATH = ./src/

SRC_NAME = fdf.c\
		   create_matrix.c\
		   check_matrix.c\
		   set_point.c\
		   transform.c\
		   ft_collect.c\
		   ft_line.c\
		   ft_vue.c\
		   ft_pixel_put.c\
		   action.c\
		   ft_line.c\
		   ft_switch.c\
		   ft_menu.c

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_PATH = ./obj/

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all : lib $(NAME)

lib :
	@echo "creation de la libft"
	@make -C libft
	@echo "creation de mlx"
	@make -C minilibx_macos

$(NAME) : $(OBJ)
	@gcc $(FLAGS) -o $@ $^ -L libft/ -lft -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit
	@echo "creation de fdf"

$(OBJ_PATH)%.o : $(SRC_PATH)%.c fdf.h
	@mkdir -p $(OBJ_PATH)
	gcc $(FLAGS) -o $@ -c $< -I $(INCLUDES) -I $(INCLUDES2) -I .

clean :
	rm -fr $(OBJ_PATH)

fclean : clean
	rm -fr $(NAME)

re : fclean all
