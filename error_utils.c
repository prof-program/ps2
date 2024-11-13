/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncantona <ncantona@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 04:33:28 by ncantona          #+#    #+#             */
/*   Updated: 2024/11/11 17:55:01 by ncantona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checking if the giving arguments are something else than numbers

int	ft_arg_error(int argc, char **argv)
{
	int	i;
	int	j;

	j = argc - 1;
	while (j > 0)
	{
		i = 0;
		if ((argv[j][i] == '-' || argv[j][i] == '+') && argv[j][i + 1]
			&& argv[j][i + 1] >= '0' && argv[j][i] <= '9')
			i++;
		while (argv[j][i] || i == 0)
		{
			if (argv[j][i] < '0' || argv[j][i] > '9')
			{
				if (argv[0][0] == '!')
					ft_free_argv(argv);
				write(2, "Error\n", 6);
				exit(1);
			}
			i++;
		}
		j--;
	}
	return (0);
}

// checks if any number in the given arguments is a dublicate

int	ft_dub_error(char **argv)
{
	int	numb;
	int	i;
	int	j;
	int	isdub;

	i = 1;
	while (argv[i])
	{
		j = 1;
		isdub = 0;
		numb = ft_atoi(argv[i]);
		while (argv[j])
		{
			if (ft_atoi(argv[j]) == numb)
				isdub++;
			j++;
		}
		if (isdub > 1)
		{
			if (argv[0][0] == '!')
				ft_free_argv(argv);
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	return (0);
}

// checks if the stack is sorted already

int	ft_is_sorted(char **argv)
{
	int	numb;
	int	i;

	i = 1;
	numb = ft_atoi(argv[i]);
	i = 2;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) > numb)
			numb = ft_atoi(argv[i]);
		else
			return (1);
		i++;
	}
	if (argv[0][0] == '!')
		ft_free_argv(argv);
	exit(0);
}

// checks for an integer overflow error

int	ft_overflow_error(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if ((long)ft_atoi(argv[i]) != ft_atol(argv[i]))
		{
			if (argv[0][0] == '!')
				ft_free_argv(argv);
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	return (0);
}

// main function that checks if there are any arguments 
// given and calls the other error functions and the is_sorted function

int	ft_checkup(int argc, char **argv)
{
	if (argc < 2)
		exit(1);
	ft_arg_error(argc, argv);
	ft_overflow_error(argv);
	ft_dub_error(argv);
	ft_is_sorted(argv);
	return (0);
}
