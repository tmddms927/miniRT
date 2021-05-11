/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 01:51:07 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/12 01:51:09 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

double write_color(int t, t_color3 pixel_color)
{
	return (t << 24 | (int)(255.999 * pixel_color.x) << 16 | (int)(255.0 * pixel_color.y) << 8 | (int)(255.0 * pixel_color.z));
}