/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_make_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:23:25 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/05 10:46:42 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_revert_rotate(t_var *var, int *c_a, int *c_b);
static void ft_rrotate(t_var *var, int *c_a, int *c_b);
static void ft_rotate_a(t_var *var, int *c_a);
static void ft_rotate_b(t_var *var, int *c_b);

void    ft_make_move(t_var *var, int c_a, int c_b)
{
    if (c_a < 0 && c_b < 0)
        ft_revert_rotate(var, &c_a, &c_b);
    else if (c_a > 0 && c_b > 0)
        ft_rrotate(var, &c_a, &c_b);
    ft_rotate_a(var, &c_a);
    ft_rotate_b(var, &c_b);
    var->rules->pa(var->s_a, var->s_b, PA);
}

static void ft_revert_rotate(t_var *var, int *c_a, int *c_b)
{
    while ((*c_a) < 0 && (*c_b) < 0)
    {
        (*c_a)++;
        (*c_b)++;
        var->rules->rrr(var->s_a, var->s_b, RRR); 
    }
}

static void ft_rrotate(t_var *var, int *c_a, int *c_b)
{
    while ((*c_a) > 0 && (*c_b) > 0)
    {
        (*c_a)--;
        (*c_b)--;
        var->rules->rr(var->s_a, var->s_b, RR); 
    }
}

static void ft_rotate_b(t_var *var, int *c_b)
{
    while ((*c_b))
    {
        if ((*c_b > 0))
        {
            var->rules->rb(var->s_b, RB);
            (*c_b)--;
        }
        if ((*c_b < 0))
        {
            var->rules->rrb(var->s_b, RRB);
            (*c_b)++;
        }
    }
}

static void ft_rotate_a(t_var *var, int *c_a)
{
    while ((*c_a))
    {
        if ((*c_a > 0))
        {
            var->rules->ra(var->s_a, RA);
            (*c_a)--;
        }
        if ((*c_a < 0))
        {
            var->rules->rra(var->s_a, RRA);
            (*c_a)++;
        }
    }
}