/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 17:50:18 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/15 17:57:02 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "parsing.h"
#include "structures.h"
#include "trace.h"
#include "utils.h"

void			check_object2(t_scene *scene, char **words)
{
	if (ft_strcmp(*words, "sp") == 0)
		create_sp(scene, words);
	else if (ft_strcmp(*words, "pl") == 0)
		create_pl(scene, words);
	else if (ft_strcmp(*words, "sq") == 0)
		create_sq(scene, words);
	else if (ft_strcmp(*words, "cy") == 0)
		create_cy(scene, words);
	else if (ft_strcmp(*words, "tr") == 0)
		create_tr(scene, words);
	else if (*words[0] == '#')
		;
	else
		error_message_basic("file error");
}
