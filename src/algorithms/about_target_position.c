/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_target_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 08:29:54 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/05 13:35:38 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  ft_target(t_cdlst *a, int i, int size, int target);

void    ft_find_target_position(t_cdlst *s_a, t_cdlst *s_b)
{
    t_sv    v;

    ft_add_position_node(s_a, s_b);
    v.node_b = s_b->head;
    v.target_pos = 0;
    v.i = 0;
    while (v.i != s_b->size)
    {
        v.target_pos = ft_target(s_a, v.node_b->index, INT_MAX, v.target_pos);
        v.node_b->target_pos = v.target_pos;
        v.node_b = v.node_b->next;
        v.i++;
    }
}

static int  ft_target(t_cdlst *a, int i_b, int size, int target)
{
    t_sv    v;

    v.i = 0;
    while (v.i != a->size)
    {
        if (a->head->index > i_b && a->head->index < size)
        {
            size = a->head->index;
            target = a->head->pos;
        }
        a->head = a->head->next;
        v.i++;
    }
    if (size != INT_MAX)
        return (target);
    while (v.i != 0)
    {
        if (a->head->index < size)
        {
            size = a->head->index;
            target = a->head->pos;
        }
        a->head = a->head->prev;
        v.i--;
    }
    return (target);
}
