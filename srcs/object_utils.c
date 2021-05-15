/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 01:51:02 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/15 16:54:08 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
** 리스트에 새로운 오브젝트 추가하는 함수
*/

t_object	*oadd(t_object **list, t_object *new)
{
	t_object	*cur;

	if (*list == NULL)
	{
		*list = new;
		return (*list);
	}
	cur = *list;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
	return (*list);
}

/*
** 카메라 리스트에 새로운 오브젝트 추가하는 함수
*/

t_camera	*cam_oadd(t_camera **list, t_camera *new)
{
	t_camera	*cur;

	cur = *list;
	if (*list == NULL)
	{
		*list = new;
		return (*list);
	}
	while (cur->next)
		cur = cur->next;
	cur->next = new;
	return (*list);
}

/*
** 카메라 리스트의 마지막으로 이동하는 함수
*/

t_camera	*cam_olast(t_camera *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

/*
** 카메라 리스트의 넥스트로 이동하는 함수
*/

t_camera	*cam_onext(t_camera *list)
{
	if (list == NULL)
		return (NULL);
	if (list->next)
		return (list->next);
	return (NULL);
}

/*
** 리스트의 마지막으로 이동하는 함수
*/

t_object	*olast(t_object *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}
