/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:52:32 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/21 15:28:04 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *msg, t_cdlst *list)
{
	ft_printf("%s\n", msg);
	if (list)
		ft_free_list(list);
	exit(EXIT_FAILURE);
}

void	ft_error_cpy_m_l(char *msg, t_cdlst *stack_a, t_cdlst *stack_b, t_var *var)
{
	ft_printf("%s\n", msg);
	if (stack_a)
		ft_free_list(stack_a);
	if (stack_b)
		ft_free_list(stack_b);
	if (var->matrix)
		ft_free_matrix(var->matrix);
	if (var)
		free(var);
	exit(EXIT_FAILURE);
}