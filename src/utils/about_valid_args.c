/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_valid_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:32:39 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/01 16:57:14 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_valid_args_heper(int argc, char *argv[]);
static int ft_validating_nbr(char c);
static int ft_validating_signs(char c);

void	ft_valid_arg(int argc, char *argv[])
{
	int	n;

	n = 0;
	if (argc == 1 || argc == 2)
	{
		if (argc == 2)
		{
			while (argv[1][n] != '\0')
			{
				if (!ft_validating_nbr(argv[1][n]) && !ft_validating_signs(argv[1][n]))
					ft_error("error", NULL);
				n++;
			}
		}
		exit(1);
	}
	ft_valid_args_heper(argc, argv);
}

static void	ft_valid_args_heper(int argc, char *argv[])
{
	int	i;
	int	x;

	i = 1;
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

static int ft_validating_nbr(char c)
{
    return ((c >= '0' && c <= '9'));
}

static int ft_validating_signs(char c)
{
	return (c == '+' || c == '-');
}