/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_cost_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:39:28 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/05 09:58:25 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_calculate_cost_move(t_cdlst *s_a, t_cdlst *s_b)
{
    t_sv    v;

    v.node_b = s_b->head;
    v.i = 0;
    while (v.i != s_b->size)
    {
        v.node_b->cost_b = v.node_b->pos;
        v.node_b->cost_a = v.node_b->target_pos;
        if (v.node_b->pos > s_b->size / 2)
            v.node_b->cost_b = (s_b->size - v.node_b->pos) *-1;
        if (v.node_b->target_pos > s_a->size /2)
            v.node_b->cost_a = (s_a->size - v.node_b->target_pos) *-1;
        v.node_b = v.node_b->next;
        v.i++;
    }
}
