##
## EPITECH PROJECT, 2022
## Graphical Programming, My Radar
## File description:
## Makefile
##

NAME	=		my_radar

CFLAGS	= 		-W -Wall -Wextra

SRC		=		./src/background.c \
	./src/init.c \
	./src/my_radar.c \
	./src/plane.c \
	./src/tower.c \
	./src/help.c \
	./src/graphics.c \
	./src/cleanup.c \
	./extras/my_printf/src/my_0.c \
	./extras/my_printf/src/my_c.c \
	./extras/my_printf/src/my_d.c \
	./extras/my_printf/src/my_e.c \
	./extras/my_printf/src/my_ee.c \
	./extras/my_printf/src/my_f.c \
	./extras/my_printf/src/my_g.c \
	./extras/my_printf/src/my_o.c \
	./extras/my_printf/src/my_p.c \
	./extras/my_printf/src/my_plus.c \
	./extras/my_printf/src/my_printf_core.c \
	./extras/my_printf/src/my_put_decimal.c \
	./extras/my_printf/src/my_strcat.c \
	./extras/my_printf/src/my_revstr.c \
	./extras/my_printf/src/my_s.c \
	./extras/my_printf/src/my_space.c \
	./extras/my_printf/src/my_strlen.c \
	./extras/my_printf/src/my_u.c \
	./extras/my_printf/src/my_w.c \
	./extras/my_printf/src/my_x.c \
	./extras/my_printf/src/my_xx.c \
	./extras/my_printf/src/my_strdup.c \
	./extras/my_printf/src/my_strcmp.c

OBJ		=		$(SRC:.c=.o)

CSFML	=		-lcsfml-graphics -lcsfml-system -lcsfml-audio \
	-lcsfml-window -lm

all:	$(OBJ)
		gcc $(OBJ) -o $(NAME) -I../include $(CFLAGS) $(CSFML)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:		fclean all

debug:	CFLAGS+= -g
debug:	all
