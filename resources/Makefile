# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sly <sly@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/09 17:18:10 by sly               #+#    #+#              #
#    Updated: 2016/10/09 22:37:55 by sly              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
SRC_PATH = ./src/
SRC_NAME = $(shell ls $(SRC_PATH) | grep "\.c")
OBJ_PATH = ./obj/
INC_PATH = ./include/
LIBFT_PATH = ./libft/
LIBFT_NAME = -lft
AR = ar rc
CC = cc
CFLAGS += -Wall -Wextra -Werror
SDL = -I /Library/Frameworks/SDL.framework/Headers
FRAMEWORKS = -framework SDL2
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
LIBDIR = -L
INC = $(addprefix -I , $(INC_PATH))

all: $(LIBFT_NAME) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LIBDIR) $(LIBFT_PATH) $(LIBFT_NAME) $(INC) -o $(NAME) $(OBJ) $(FRAMEWORKS)

$(LIBFT_NAME):
	@make -C $(LIBFT_PATH)

libftclean:
	@make -C $(LIBFT_PATH) fclean

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(INC) -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean libftclean
	@rm -fv $(NAME)

re: fclean
	@make

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

.PHONY: clean $(LIBFT_NAME) fclean all re norme libftclean
