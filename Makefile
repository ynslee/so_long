# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 12:07:15 by yoonslee          #+#    #+#              #
#    Updated: 2023/06/02 10:52:18 by yoonslee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = main.c error.c validate_map.c utils.c make_map.c movement.c later_delete.c
OBJS= $(SRCS:.c=.o)
CC = cc
HEADER = so_long.h
FLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

all:$(NAME)

$(NAME):$(OBJS)
	make -C libft all
	$(CC) $(FLAGS) $(OBJS) -I$(HEADER) ./libft/libft.a $(MLX_FLAGS) -o $(NAME) 

$(OBJS):$(SRCS)
	$(CC) -c $(FLAGS) $(SRCS) -I$(HEADER)

clean:
		rm -rf $(OBJS)
		make -C libft clean

fclean:clean
		rm -rf $(NAME)
		rm -rf libft/libft.a

re: fclean clean all

.PHONY: all clean fclean re
