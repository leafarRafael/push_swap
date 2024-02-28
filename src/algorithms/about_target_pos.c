/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_target_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:37:24 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/28 18:05:32 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_target(t_var *var, int index_b)
{
	t_node	*node;
	int 	i;
	int 	big;
	int		target;

	big = 0;
	i = 0;
	target = 0;
	node = var->s_a->head;
	while (i != var->s_a->size)
	{
		if (node->index < index_b && node->next->index > index_b)
			return (node->next->pos);
		node = node->next;
		i++;
	}
	return (0);
}

void    ft_add_target_pos_list(t_var *var)
{
	t_node	*node_b;
	int		i_b;
	int 	size;

	ft_add_position_list(var);
	i_b = 0;
	node_b = var->s_b->head;
	while (i_b != var->s_b->size)
	{
		node_b->target_pos = ft_find_target(var, node_b->index);
		node_b = node_b->next;
		i_b++;
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
	while (i != 0)
	{
		if (tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->prev;
        i--;
	}
	return (target_pos);
}

void	get_target_position(t_cdlst *a, t_cdlst *b, t_var *var)
{
    t_node  *tmp_b;
	int		target_pos;
    int i;

    i = 0;
	tmp_b = b->head;
	ft_add_position_list(var);
	target_pos = 0;
	while (i != b->size)
	{
		target_pos = get_target(a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
        i++;
	}
}