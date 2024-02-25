/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_valid_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:32:39 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/25 14:13:33 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_validating_nbr(char c)
{
    return ((c >= '0' && c <= '9'));
}

static int ft_validating_signs(char c)
{
	return (c == '+' || c == '-');
}

void	ft_valid_arg(int argc, char *argv[])
{
	int	i;
	int	x;

	i = 1;
	if (argc == 1 || argc == 2)
	{
		exit(1);
	}
	while (argv[i])
	{
		x = 0;
		while (argv[i][x])
		{
			if (!ft_validating_nbr(argv[i][x]) && !ft_validating_signs(argv[i][x]))
				ft_error("error", NULL);
			if (ft_validating_signs(argv[i][x]) && !ft_validating_nbr(argv[i][x+1]))
				ft_error("error", NULL);
			x++;
		}
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
			ft_error("error", NULL);
		i++;
	}
}
