# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irozhkov <irozhkov@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 14:03:00 by irozhkov          #+#    #+#              #
#    Updated: 2024/09/22 17:57:54 by irozhkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = $(shell find . -name "*.c" ! -name "*_bonus.c")
SRC_BONUS = $(shell find . -name "*_bonus.c")

OBJ = $(patsubst %.c,%.o,$(SRC))
OBJ_BONUS = $(patsubst %.c,%.o,$(SRC_BONUS))

COMPILE = $(CC) $(CFLAGS) -c $< -o $@
LIB = ar rc $(NAME)
REMOVE = rm -f

all: $(NAME)

$(NAME): $(OBJ) Makefile
	$(LIB) $(OBJ)

%.o: %.c $(HEADER)
	$(COMPILE)

bonus: $(OBJ_BONUS)
	$(LIB) $(OBJ_BONUS)

clean:
	$(REMOVE) $(OBJ)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
