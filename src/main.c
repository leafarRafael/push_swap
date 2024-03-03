/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:42:20 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/03 15:29:37 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ft_sort(t_var *var);
int		ft_find(t_var *var, int index);
void	ft_push_and_rotate(t_var *var);
void	ft_make_find(t_var *var, int find, int media, int limit);

int main(int argc, char *argv[])
{
	t_var	*var;

	ft_valid_arg(argc, argv);
	var = malloc(sizeof(t_var));
	if (!var)
		ft_error("error", NULL);
	var->s_a = ft_init_list();
	var->s_b = ft_init_list();
	var->rules = ft_init_get_rules();
	ft_cpy_matrix_to_list(var, argv);
	ft_assigned_index_node(var);
	if (ft_check_repeated_numbers(var->s_a) != 0)
		ft_error_cpy_m_l("error\n", var->s_a, var->s_b, var);
	if (ft_already_sorted(var->s_a) == 0)
		ft_error_cpy_m_l(NULL, var->s_a, var->s_b, var);
	ft_sort(var);
	printf("lista A\n");
	ft_print_list_index(var->s_a);
	printf("lista B\n");
	ft_print_list_index(var->s_b);
	ft_free_list(var->s_a);
	ft_free_list(var->s_b);
	free(var);
	return (1);
}

void	ft_sort(t_var *var)
{
	int	size;
	int	media;
	int find;

	ft_find_largest_smallest_index(var, var->s_a);
	media = (var->s_a->size /2);
	find = ft_find(var, media);
	var->i_a = 1;
	while (var->i_a != 0)
	{
		if (find < (var->largest /2))
			ft_make_find(var, find, media, 0);
		else if (find >= (var->largest /2))
			ft_make_find(var, find, media, var->largest);
		if (var->s_a->head->index == media)
		{
			ft_push_and_rotate(var);;
			var->i_a--;
		}
		find = ft_find(var, media);
	}
}

int	ft_find(t_var *var, int index)
{
	int		i;
	t_node	*node;

	node = var->s_a->head;
	i = 0;
	while (i != var->s_a->size)
	{
		if (index == node->index)
			return (i) ;
		node = node->next;
		i++;
	}
	return (-1);
}

void	ft_push_and_rotate(t_var *var)
{
	var->rules->pb(var->s_b, var->s_a, PB);
	if (var->s_b->head->index < var->s_b->last->index)
	{
		if (var->s_a->head->index < var->s_a->last->index)
			var->rules->rr(var->s_a, var->s_b, RR);
		else
			var->rules->rb(var->s_b, RB);
	}
	if (var->s_b->head->index < var->s_b->head->next->index)
	{
		if (var->s_a->head->index < var->s_a->head->next->index)
			var->rules->ss(var->s_a, var->s_b, SS);
		else
			var->rules->sb(var->s_b, SB);
	}
}

void	ft_make_find(t_var *var, int find, int media, int limit)
{
	if (find == limit)
		return ;
	if (var->s_a->head->index == media +1)
		ft_push_and_rotate(var);
	if (var->s_a->head->index == media -1)
		ft_push_and_rotate(var);
	if (limit == 0)
	{
		var->rules->ra(var->s_a, RA);
		ft_make_find(var, find -1, media, limit);
	}
	else
	{
		var->rules->rra(var->s_a, RRA);
		ft_make_find(var, find +1, media, limit);
	}
}