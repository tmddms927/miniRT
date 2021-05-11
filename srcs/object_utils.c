#include "utils.h"

/* 리스트에 새로운 오브젝트 추가하는 함수 */
void            oadd(t_object **list, t_object *new)
{
    t_object    *cur;

    if (*list == NULL)
    {
        *list = new;
        return ;
    }
    cur = *list;
    while (cur->next)
        cur = cur->next;
    cur->next = new;
}

/* 카메라 리스트에 새로운 오브젝트 추가하는 함수 */
t_camera        *cam_oadd(t_camera **list, t_camera *new)
{
    t_camera    *cur;

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

/* 리스트의 마지막으로 이동하는 함수 */
t_object        *olast(t_object *list)
{
    if (list == NULL)
        return (NULL);
    while (list->next)
        list = list->next;
    return (list);
}