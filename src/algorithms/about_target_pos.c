/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_target_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:37:24 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/27 16:36:25 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_add_target_pos_list(t_var    *var)
{
    t_node  *node_b;
    t_node  *node_a;
    int     i_b;
    int     i_a;

    if (!var->s_a->head || !var->s_b->head)
        return ;
    i_b = 0;
    node_b = var->s_b->head;
    while (i_b != var->s_b->size)
    {
        node_a = var->s_a->head;
        i_a =  i_b;
        while (i_a != var->s_a->size)
        {
            if (node_a->index > node_b->index 
                && node_a->next->index < node_b->index)
                node_b->target_pos = i_a;
            node_a = node_a->next;
            i_a++;
        }
        node_b = node_b->next;
        i_b++;
    }
}

static void	get_position(t_cdlst *stack)
{
	t_node	*tmp;
	int		i;

	tmp = stack->head;
	i = 0;
	while (i != stack->size)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

static int	get_target(t_cdlst *a, int b_idx, int target_idx, int target_pos)
{
	t_node	*tmp_a;
    int i;

    i = 0;
	tmp_a = a->head;
	while (i != a->size)
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
        i++;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	tmp_a = a->head;
    i = 0;
	while (i != a->size)
	{
		if (tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
        i++;
	}
	return (target_pos);
}

void	get_target_position(t_cdlst *a, t_cdlst *b)
{
    t_node  *tmp_b;
	int		target_pos;
    int i;

    i = 0;
	tmp_b = b->head;
	get_position(a);
	get_position(b);
	target_pos = 0;
	while (i != b->size)
	{
		target_pos = get_target(a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
        i++;
	}
}