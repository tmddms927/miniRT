OUT		=	miniRT
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
CLIB	=	-Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx
SRCDIR  =	./srcs/
SRCNAME	=	main.c\
			canvas.c\
			print.c\
			ray.c\
			vec3_utils.c\
			hit_sphere.c\
			object_create.c\
			normal.c\
			hit.c\
			object_utils.c\
			phong_lighting.c\
			hit_plane.c\
			hit_square.c\
			hit_triangle.c\
			hit_cylinder.c\
			libft/ft_split.c\
			libft/ft_strcmp.c\
			parsing/parsing1.c\
			parsing/parsing2.c\
			parsing/get_next_line.c\
			parsing/get_next_line_utils.c
SRCS	=	${addprefix ${SRCDIR}, ${SRCNAME}}
INCDIR	=	./includes/
OBJS	=	${SRCS:.c=.o}

test	:	re
			./${OUT} 2.rt

all		: $(OUT)

.c.o	:
	${CC} ${CFLAGS} -I ${INCDIR} -c ${<} -o ${<:.c=.o}

${OUT}: ${OBJS}
	${CC} ${CFLAGS} ${CLIB} -o ${OUT} ${OBJS}
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib ${OUT}

clean	:
	rm -rf ${OBJS}

fclean	: clean
	rm -rf	${OUT}

re		: fclean all

.PHONY: all clean fclean re