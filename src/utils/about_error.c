/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:52:32 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/06 15:24:02 by rbutzke          ###   ########.fr       */
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

void	ft_finish_program(char *msg, t_cdlst *s_a, t_cdlst *s_b, t_var *var)
{
	if (msg)
		ft_printf("%s\n", msg);
	if (s_a)
		ft_free_list(s_a);
	if (s_b)
		ft_free_list(s_b);
	if (var)
		free(var);
	exit(EXIT_FAILURE);
}
