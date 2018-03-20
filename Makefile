# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvinogra <vvinogra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/25 16:41:32 by vvinogra          #+#    #+#              #
#    Updated: 2018/03/20 20:09:58 by vvinogra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

SRC = main.c solution_m.c image.c zoom_and_iter_move.c \
	solution_j.c hook.c colors.c colors2.c solution_b.c solution_p.c \
	solution_t.c solution_j_s.c frac_comparing.c solution_my.c solution_c.c

LIB_SRC = $(shell find libft | fgrep ".c")

OBJ = $(SRC:.c=.o)

HEADER = libft/includes -I minilibx_macos

HEADER_RELATION = fractol.h libft/includes/libft.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIB_SRC) $(OBJ)
	@make -C minilibx_macos
	@make -C libft
	@$(CC) -o $(NAME) -L minilibx_macos -lmlx -framework OpenGL -framework AppKit $(OBJ) -L libft -lft
	@echo "Compilation finished: ./$(NAME) [-j, -m, -b, -p, -t, -j_s, -my, -c]"

%.o: %.c $(HEADER_RELATION)
	@$(CC) -c $(FLAGS) -o $@ $< -I $(HEADER)

clean:
	@rm -f $(OBJ)
	@make clean -C libft
	@echo "Object files deleted: $(NAME)"

fclean: clean
	@rm -f $(NAME)
	@rm -f libft/libft.a
	@make clean -C minilibx_macos
	@echo "Executable file deleted: libft/libft.a"
	@echo "Executable file deleted: $(NAME)"

re: fclean all
