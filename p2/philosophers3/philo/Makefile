# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 08:22:06 by habu-zua          #+#    #+#              #
#    Updated: 2023/11/18 17:18:54 by habu-zua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src/
OBJ_DIR = objects/

SRC =	philo \
    	parse \
    	init_data \
    	routine \
    	time \
		utils \
    	monitor \
       	eat_1 \
    	eat_2 \
    	sleep \
    	think \
    	getters_1 \
    	getters_2 \
    	setters

SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC)))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c 
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) 

re: fclean all
#-g #-fsanitize=thread
# $(SRC_DIR)%.c 
.PHONY: all clean fclean re