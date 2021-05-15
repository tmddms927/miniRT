/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:33:48 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/15 15:30:57 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

#include "minirt.h"

#pragma pack(push, 1)
typedef struct		s_fileheader
{
	unsigned char	sign1;
	unsigned char	sign2;
	unsigned int	file_size;
	unsigned short	reserved1;
	unsigned short	reserved2;
	unsigned int	start_bmp;
}					t_fileheader;

typedef struct		s_infoheader
{
	unsigned int	size;
	unsigned int	witdh;
	unsigned int	height;
	unsigned short	planes;
	unsigned short	bitCount;
	unsigned int	compression;
	unsigned int	sizeimage;
	unsigned int	x_pelspermeter;
	unsigned int	y_pelspermeter;
	unsigned int	color_used;
	unsigned int	color_important;
}					t_infoheader;

typedef struct		s_bmp
{
	t_fileheader	file_h;
	t_infoheader	info_h;
}					t_bmp;
#pragma pack(pop)

void		bmp_save(t_scene *scene);
void		check_save(char *argv, t_scene *scene);
t_bmp		bmp_set_header(t_scene *scene);

#endif