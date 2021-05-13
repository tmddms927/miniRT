OUT		=	miniRT
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -fsanitize=address -g
CLIB	=	-Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx 
SRCDIR  =	./srcs/
SRCNAME	=	main.c\
			canvas.c\
			utils.c\
			ray.c\
			vec3_utils.c\
			object_create.c\
			object_utils.c\
			phong_lighting.c\
			camera.c\
			\
			hit/hit.c\
			hit/hit_sphere.c\
			hit/hit_plane.c\
			hit/hit_square.c\
			hit/hit_triangle.c\
			hit/hit_cylinder.c\
			\
			libft/ft_split.c\
			libft/ft_split2.c\
			libft/ft_strcmp.c\
			\
			parsing/parsing1.c\
			parsing/parsing2.c\
			parsing/parsing3.c\
			parsing/get_next_line.c\
			parsing/get_next_line_utils.c
SRCS	=	${addprefix ${SRCDIR}, ${SRCNAME}}
INCDIR	=	./includes/
OBJS	=	${SRCS:.c=.o}

test	:	re
			./${OUT} 1.rt

all		: $(OUT)

.c.o	:
	${CC} ${CFLAGS} -I ${INCDIR} -I ./mlx -c ${<} -o ${<:.c=.o}

${OUT}: ${OBJS}
	${CC} ${CFLAGS} ${CLIB} -o ${OUT} ${OBJS}
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib ${OUT}

clean	:
	rm -rf ${OBJS}

fclean	: clean
	rm -rf	${OUT}

re		: fclean all

.PHONY: all clean fclean re