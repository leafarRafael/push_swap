/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_lowest_cost_move.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:00:56 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/05 10:37:56 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static  int ft_abs(int i);

void    ft_find_lowest_cost_and_move(t_var *var, t_cdlst *s_a, t_cdlst *s_b)
{
    t_sv    v;

    v.node_b = s_b->head;
    v.size = s_a->size + s_b->size +1;
    v.i = 0;
    v.c_a = 0;
    v.c_b = 0;
    while (v.i != s_b->size)
    {
        if (ft_abs(v.node_b->cost_a) + ft_abs(v.node_b->cost_b) < v.size)
        {
            v.size = ft_abs(v.node_b->cost_a) + ft_abs(v.node_b->cost_b);
            v.c_a = v.node_b->cost_a;
            v.c_b = v.node_b->cost_b;
        }
        v.node_b = v.node_b->next;
        v.i++;
    }
    ft_make_move(var, v.c_a, v.c_b);
}

static  int ft_abs(int i)
{
    if (i < 0)
        return (-i);
    return (i);
}
