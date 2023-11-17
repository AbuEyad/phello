NAME = so_long

CC = cc
CFLAG = -Wall -Werror -Wextra
MLXFLAG = -framework OpenGL -framework AppKit 
MLXLIB = ./minilibx/libmlx.a
SRC = main.c draw_circle_1.c draw_circle_2.c filled_circle.c
INCLUDE = main.h

all:$(SRC) $(INCLUDE)
	$(CC) $(CFLAG) $(MLXFLAG) $(MLXLIB) $(SRC) -o $(NAME)


fclean:
	rm -rf $(NAME)

re: fclean all
