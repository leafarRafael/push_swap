/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:42:20 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/05 10:55:56 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ft_finish_program("error\n", var->s_a, var->s_b, var);
	if (ft_already_sorted(var->s_a) == 0)
		ft_finish_program(NULL, var->s_a, var->s_b, var);
	ft_sort(var);
	ft_free_list(var->s_a);
	ft_free_list(var->s_b);
	free(var);
	return (1);
}
