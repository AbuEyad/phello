# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/19 13:54:21 by habu-zua          #+#    #+#              #
#    Updated: 2023/11/19 13:54:23 by habu-zua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME		=	philo

CC			= 	cc
RM			=   rm -f
CFLAGS		=	-pthread -Wall -Werror -Wextra #-fsanitize=thread -g

SRCS		=	philo.c arguments_check.c utils.c display_message.c time.c \
				initialize.c control.c routine.c destroy_and_free.c
OBJS		=	$(SRCS:.c=.o)

BLUE		=	\033[0;94m
GREEN		=	\033[0;32m
RESET		=	\033[0m

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			echo "$(GREEN)✅🚀 Program compiled successfully 🚀✅$(RESET)"

clean:
			$(RM) $(OBJS)
			echo "$(BLUE)✨🧹🧺✨ Removed object files ✨🧺🧹✨$(RESET)"

fclean:		clean
			$(RM) $(NAME)
			echo "$(BLUE)✨💦🛁✨ Removed executable ✨🛁💦✨$(RESET)"
	
re:			fclean all

.PHONY:		all clean fclean re