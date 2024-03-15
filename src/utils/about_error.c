/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:52:32 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/15 14:58:48 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *msg, t_cdlst *list)
{
	if (msg)
	{
		write(STDERR_FILENO, msg, ft_strlen(msg));
		write(STDERR_FILENO, "\n", 1);
	}
	if (list)
		ft_free_list(list);
	exit(EXIT_FAILURE);
}

void	ft_finish_program(char *msg, t_cdlst *s_a, t_cdlst *s_b, t_var *var)
{
	if (msg)
	{
		write(STDERR_FILENO, msg, ft_strlen(msg));
		write(STDERR_FILENO, "\n", 1);
	}
	if (s_a)
		ft_free_list(s_a);
	if (s_b)
		ft_free_list(s_b);
	if (var)
		free(var);
	exit(EXIT_FAILURE);
}
