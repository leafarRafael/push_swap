/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:42:20 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/24 15:33:32 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_var	*var;
	t_rules *rules;

	rules = ft_init_get_rules();
	ft_valid_arg(argc, argv);
	var = malloc(sizeof(t_var));
	if (!var)
		ft_error("error", NULL);
	var->matrix = ft_cpy_matrix(argv, argc);
	var->s_a = ft_init_list();
	var->s_b = ft_init_list();
	ft_cpy_matrix_to_list(var);
	ft_assigned_index_node(var);
	if (ft_check_repeated_numbers(var->s_a) != 0)
		ft_error_cpy_m_l("error\n", var->s_a, var->s_b, var);
	if (ft_already_sorted(var->s_a) == 0)
		ft_error_cpy_m_l(NULL, var->s_a, var->s_b, var);
	ft_bubble_sort(var, var->s_a, var->s_b);
	ft_free_list(var->s_a);
	ft_free_list(var->s_b);
	free(var);
	return (1);
}