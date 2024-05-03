/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_valid_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:32:39 by rbutzke           #+#    #+#             */
/*   Updated: 2024/05/03 14:47:13 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_valid_args_heper(char *argv[]);
static int	ft_valid_nbr(char c);
static int	ft_valid_signs(char c);
static int	ft_valid_is_sing(char *argv[]);

void	ft_valid_arg(int argc, char *argv[])
{
	int	n;

	n = 0;
	if (argc == 1 || argc == 2)
	{
		if (argc == 2)
		{
			if (!ft_valid_nbr(argv[1][n]) && !ft_valid_signs(argv[1][n]))
				ft_error(MSG_ERROR, NULL);
			if (ft_valid_signs(argv[1][n]) && !ft_valid_nbr(argv[1][n +1]))
				ft_error(MSG_ERROR, NULL);
			n++;
			while (argv[1][n] != '\0')
			{
				if (!ft_valid_nbr(argv[1][n]))
					ft_error(MSG_ERROR, NULL);
				n++;
			}
			if (ft_atol(argv[1]) > INT_MAX
				|| ft_atol(argv[1]) < INT_MIN)
				ft_error(MSG_ERROR, NULL);
		}
		exit(1);
	}
	ft_valid_args_heper(argv);
}

static void	ft_valid_args_heper(char *argv[])
{
	int	i;
	int	x;

	i = 1;
	while (argv[i])
	{
		x = 0;
		if (!ft_valid_nbr(argv[1][x]) && !ft_valid_signs(argv[1][x]))
			ft_error(MSG_ERROR, NULL);
		if (ft_valid_signs(argv[1][x]) && !ft_valid_nbr(argv[1][x +1]))
			ft_error(MSG_ERROR, NULL);
		x++;
		while (argv[i][x] != '\0')
		{
			if (!ft_valid_nbr(argv[i][x]))
				ft_error(MSG_ERROR, NULL);
			x++;
		}
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
			ft_error(MSG_ERROR, NULL);
		i++;
	}
	if (ft_valid_is_sing(argv) != 0)
		ft_error(MSG_ERROR, NULL);
}

static int	ft_valid_nbr(char c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_valid_signs(char c)
{
	return (c == '+' || c == '-');
}

static int	ft_valid_is_sing(char *argv[])
{
	int	i;
	int	x;
	int	error;

	error = 0;
	i = 1;
	while (argv[i])
	{
		x = 0;
		while (argv[i][x] != '\0')
		{
			if (ft_valid_signs(argv[i][x]) && !ft_valid_nbr(argv[i][x +1]))
				error++;
			x++;
		}
		i++;
	}
	return (error);
}
