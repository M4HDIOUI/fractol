CC= cc

CFLAGS= -Wall -Wextra -Werror

HDR = fractol.h

SRC = fract-ol.c julia.c mandelbrot.c burningship.c zoom.c utils.c hooks.c

OBJ = $(SRC:.c=.o)

NAME = fract-ol

all: fract-ol

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c $(HDR)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
	rm -rf  $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all