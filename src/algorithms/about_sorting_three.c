/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_sorting_three.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:41:54 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/04 18:23:03 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort_three(t_var *var)
{
    ft_find_largest_smallest_index(var, var->s_a);
    if (!var->s_a->head)
        ft_finish_program(NULL, var->s_a, var->s_b, var);
    if (var->s_a->size == 1)
        ft_finish_program(NULL, var->s_a, var->s_b, var);
    if (var->s_a->size == 2)
    {
        var->rules->sa(var->s_a, SA);
        ft_finish_program(NULL, var->s_a, var->s_b, var);
    }
    if (var->s_a->head->index == var->largest)
        var->rules->ra(var->s_a, RA);
    if (var->s_a->head->next->index == var->largest)
        var->rules->rra(var->s_a, RRA);
    if (var->s_a->head->index > var->s_a->head->next->index)
        var->rules->sa(var->s_a, SA);
}