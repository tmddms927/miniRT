# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 11:28:27 by seungoh           #+#    #+#              #
#    Updated: 2021/05/15 18:00:57 by seungoh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OUT		=	miniRT
CC		=	clang
CFLAGS	=	-Wall -Werror -Wextra
CLIB	=	-Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx 
SRCDIR  =	./srcs/
SRCNAME	=	main.c\
			canvas.c\
			utils.c\
			ray.c\
			object_create.c\
			object_create2.c\
			object_utils.c\
			phong_lighting.c\
			camera.c\
			bmp_save.c\
			camera_utils.c\
			\
			vec3_utils/vec3_utils1.c\
			vec3_utils/vec3_utils2.c\
			vec3_utils/vec3_utils3.c\
			vec3_utils/vec3_utils4.c\
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
			parsing/parsing4.c\
			parsing/get_next_line.c\
			parsing/get_next_line_utils.c
SRCS	=	${addprefix ${SRCDIR}, ${SRCNAME}}
INCDIR	=	./includes/
OBJS	=	${SRCS:.c=.o}

all		: $(OUT)

test	:	re
			./${OUT} 1.rt

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