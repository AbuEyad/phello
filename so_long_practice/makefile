
NAME = so_long

CC = cc
CFLAG = -Wall -Werror -Wextra -I./include
MLXFLAG = -Lminilibx -lmlx -framework OpenGL -framework AppKit

MLXLIB = ./minilibx/libmlx.a

SRC_DIR = src
OBJ_DIR = obj

SRCS = src/draw_circle_1.c src/draw_circle_2.c src/filled_circle.c \
		src/random.c src/draw_square.c src/control.c src/update_window.c\
		src/graphics.c src/draw_tringle.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) so_long.c
	$(CC) $(CFLAG) $(MLXFLAG) $(SRCS) so_long.c -o $(NAME)
	

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
