/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_position_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 08:17:14 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/05 08:27:24 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static  void ft_position_helper(t_cdlst *list);

void    ft_add_position_node(t_cdlst *s_a, t_cdlst *s_b)
{
    if(s_a->size != 0)
        ft_position_helper(s_a);
    if(s_b->size != 0)
        ft_position_helper(s_b);
}

static  void ft_position_helper(t_cdlst *list)
{
    t_sv v;

    v.i = 1;
    list->head->pos = 0;
    v.node_a = list->head->next;
    while (v.node_a != list->head)
    {
        v.node_a->pos = v.i;
        v.node_a = v.node_a->next;
        v.i++;
    }
}