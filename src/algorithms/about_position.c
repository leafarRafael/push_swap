/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:10:29 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/01 11:23:33 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_position_helper(t_cdlst *list);

void    ft_add_position_list(t_var *var)
{
    if (var->s_a)
        ft_position_helper(var->s_a);
    if (var->s_b)
        ft_position_helper(var->s_b);
}
static void ft_position_helper(t_cdlst *list)
{
    t_node  *node;
    int     i_a;

    i_a = 1;
    if (list->size == 0)
        return ;
    if (list->size == 1)
        list->head->pos = 0;
    else
    {
        node = list->head->next;
        list->head->pos = 0;
        while (i_a != list->size)
        {
            node->pos = i_a;
            node = node->next;
            i_a++;
        }
    }
}