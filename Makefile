##
## Makefile for MUL_2014_rtracer in /home/zack/Projects/MUL_2014_rtracer
##
## Made by Antoine Favarel
## Login   <favare_a@epitech.net>
##
## Started on  dim. févr. 22 02:02:57 2015 Antoine Favarel
## Last update dim. juin 07 16:03:03 2015 Antoine Favarel
##

CC=		gcc
CFLAGS=		-Wall -Wextra -ansi -pedantic -D_REENTRANT -I./include/ -O3
LDFLAGS=	-L./lib/ -lneptune -lpthread -lm -L./lib/mlx -lmlx \
		-L/usr/lib64/X11 -lXext -lX11

NAME=		rt

NAME_SLAVE=	slave

MAIN=		src/main.c

MAIN_SLAVE=	src/main_slave.c

RM=		rm
RMFLAGS=	-fr

SRC_G=		src/rt_test.c\
		src/init/rt_init.c \
		src/intersection/rt_inter_cone.c \
		src/intersection/rt_inter_cylinder.c \
		src/intersection/rt_inter_plan.c \
		src/intersection/rt_inter_sphere.c \
		src/reflexion/rt_reflexion.c \
		src/transparence/rt_transparence.c \
		src/light/rt_light.c \
		src/light/rt_lights.c \
		src/myriad/myriad_actor.c \
		src/myriad/myriad_dispatcher.c \
		src/myriad/myriad_getrt.c \
		src/myriad/myriad_manager.c \
		src/myriad/myriad_putorder.c \
		src/myriad/myriad_setrt.c \
		src/myriad/new_pixel.c \
		src/shadow/rt_shadow.c \
		src/shadow/rt_shadows.c \
		src/tool/rt_aliasing.c\
		src/tool/rt_average.c \
		src/tool/rt_exit.c \
		src/tool/rt_getnorme.c \
		src/tool/rt_checkobj.c \
		src/tool/rt_mkobj.c \
		src/tool/rt_mkspot.c \
		src/tool/rt_delta.c \
		src/tool/rt_delta_shadow.c \
		src/tool/rt_pixel_put_to_image.c \
		src/tool/rt_ptr_expose.c \
		src/tool/rt_ptr_key.c \
		src/tool/rt_ptr_mouse.c \
		src/tool/rt_loop.c \
		src/tool/rt_rotate.c \
		src/tool/rt_translate.c \
		src/tool/rt_putimage.c \

SRC=		$(MAIN) \
		$(SRC_G)

SRC_SLAVE=	$(MAIN_SLAVE) \
		$(SRC_G)

OBJ=		$(SRC:.c=.o)

OBJ_SLAVE=	$(SRC_SLAVE:.c=.o)

all:		$(NAME) $(NAME_SLAVE)

$(NAME):	$(OBJ)
	make -C ./lib/neptune/ re
	cp ./lib/neptune/libneptune.a ./lib/
	make -C ./lib/mlx/
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

$(NAME_SLAVE):	$(OBJ_SLAVE)
	$(CC) -o $(NAME_SLAVE) $(OBJ_SLAVE) $(LDFLAGS)

clean:
	$(RM) $(RMFLAGS) $(OBJ) $(OBJ_SLAVE)
	make -C ./lib/neptune/ clean
	make clean -C ./lib/mlx/

fclean:		clean
	$(RM) $(RMFLAGS) $(NAME) $(NAME_SLAVE)

re:		fclean all
