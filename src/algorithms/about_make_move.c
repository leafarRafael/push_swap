/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_make_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:23:16 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/01 18:00:52 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rr(t_var *var, int *cost_a, int *cost_b);
static void rrr(t_var *var, int *cost_a, int *cost_b);
static void ra(t_var *var, int *cost_a);
static void ra(t_var *var, int *cost_b);

void	ft_make_best_move(t_var *var, int *cost_a, int *cost_b)
{
	if ((*cost_a) > 0 && (*cost_b) > 0)
		rr(var, cost_a, cost_b);
	else if ((*cost_a) < 0 && (*cost_b) < 0)
		rrr(var, cost_a, cost_b);
}

static void rr(t_var *var, int *cost_a, int *cost_b)
{
	while ((*cost_a) > 0 && (*cost_b) > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		var->rules->rr(var->s_a, var->s_a, RR);
	}
}

static void rrr(t_var *var, int *cost_a, int *cost_b)
{
	while ((*cost_a) < 0 && (*cost_b) < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		var->rules->rrr(var->s_a, var->s_a, RRR);
	}
}

static void ra(t_var *var, int *cost_a)
{
	while ((*cost_a) != 0)
	{
		if ((*cost_a) > 0)
		{
			var->rules->ra(var->s_a, RA);
			(*cost_a)--;
		}
		else if (cost_a > 0)
		{
			var->rules->ra(var->s_a, RA);
			(*cost_a)++;
		}
	}
}

static void ra(t_var *var, int *cost_b)
{
	while ((*cost_b) != 0)
	{
		if ((*cost_b) > 0)
		{
			var->rules->rb(var->s_b, RB);
			(*cost_b)--;
		}
		else if ((*cost_b) < 0)
		{
			var->rules->rb(var->s_b, RB);
			(*cost_b)++;
		}
	}
}