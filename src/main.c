/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:42:20 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/22 18:01:23 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bubble_sort(t_var *var, t_cdlst *s_a, t_cdlst *s_b)
{
	t_rules *rules;
	long	next_small;
	int		i;

	i = 0;
	rules = ft_init_get_rules();
	next_small = var->smaller;
	while (1)
	{
		if (s_a->head->content > s_a->head->next->content)
		{
			if (s_a->head->content > s_a->last->content)
				rules->rra(s_a, "rra");
			else
				rules->sa(s_a, "sa");
			rules->pa(s_b, s_a, "pa");
		}
		else
			rules->pa(s_b, s_a, "pa");
			
		rules->rra(s_a, "rra");
		if (s_a->size == 1)
		{
			rules->pa(s_b, s_a, "pa");
			break ;
		}
	}
	while (1)
	{
		if (s_b->head->content < s_b->head->next->content)
			rules->sb(s_b, "sb");
		rules->pb(s_a, s_b, "pb");
		if (s_b->size == 0)
			break ;
	}

}

int main(int argc, char *argv[])
{
	t_cdlst	*s_a;
	t_cdlst	*s_b;
	t_var	*var;

	ft_valid_arg(argc, argv);
	var = malloc(sizeof(t_var));
	if (!var)
		ft_error("error", NULL);
	var->matrix = ft_cpy_matrix(argv, argc);
	s_a = ft_init_list();
	s_b = ft_init_list();
	ft_cpy_matrix_to_list(s_a, s_b, var);
	ft_bubble_sort(var, s_a, s_b);
	ft_print_list(s_a);
	ft_free_list(s_a);
	ft_free_list(s_b);
	free(var);
	return (1);
}