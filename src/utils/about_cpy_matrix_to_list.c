/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_cpy_matrix_to_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:56:12 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/06 15:24:36 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cpy_matrix_to_list(t_var *var, char *matrix[])
{
	int	i;

	i = 1;
	while (matrix[i])
	{
		ft_creating_node(var->s_a, ft_atol(matrix[i]));
		i++;
	}
}
