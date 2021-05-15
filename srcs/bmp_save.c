/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:00:17 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/15 15:25:05 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "structures.h"
# include "bmp.h"
# include "parsing.h"

void			bmp_save(t_scene *scene)
{
    t_bmp       bmp_h;
    int         fd;
    int         i;
    t_data      image;

	printf("save bmp file!\n");
    fd = open("miniRT.bmp", O_WRONLY | O_CREAT | O_TRUNC);
    bmp_h = bmp_set_header(scene);
    write(fd, &bmp_h, 54);
    i = 0;
    image = scene->main_camera->image;
    while (i < (image.line_length / 4) * scene->canvas.height)
    {
    	if (i % (image.line_length / 4) < scene->canvas.width)
			write(fd, &image.addr[i * 4], 4);
		++i;
    }
    close(fd);
    exit(0);
}

/*
** 헤더값 입력하기
*/

t_bmp           bmp_set_header(t_scene *scene)
{
    t_bmp       bmp;

    bmp.file_h.sign1 = 'B';
    bmp.file_h.sign2 = 'M';
    bmp.file_h.file_size = 14 + 40 +
            scene->canvas.width * scene->canvas.height * 4;
    bmp.file_h.reserved1 = 0;
    bmp.file_h.reserved2 = 0;
    bmp.file_h.start_bmp = 14 + 40;
    bmp.info_h.size = 40;
    bmp.info_h.witdh = scene->canvas.width;
    bmp.info_h.height = -scene->canvas.height;
    bmp.info_h.planes = 1;
    bmp.info_h.bitCount = 32;
    bmp.info_h.compression = 0;
    bmp.info_h.sizeimage = 4 * scene->canvas.width * scene->canvas.height;
    bmp.info_h.x_pelspermeter = scene->canvas.width;
    bmp.info_h.y_pelspermeter = scene->canvas.height;
    bmp.info_h.color_used = 0xffffff;
    bmp.info_h.color_important = 0;
    return (bmp);
}

/*
** 이미지 저장하는지 확인
*/

void		check_save(char *argv, t_scene *scene)
{
	if (!ft_strcmp(argv, "--save") || !ft_strcmp(argv, "--s"))
		bmp_save(scene);
}
