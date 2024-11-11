/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncantona <ncantona@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:13:54 by ncantona          #+#    #+#             */
/*   Updated: 2024/11/11 17:44:59 by ncantona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// counting the arguments

int	ft_countarg(char **argv)
{
	int	i;

	i = 0;
	if (argv)
	{
		while (argv[i])
			i++;
	}
	return (i);
}

// printing ERROR and exiting the programm

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void ft_free_argv(char **argv)
{
	int index;
	
	index = 0;
	while (argv[index])
	{
		free(argv[index]);
		index++;
	}
	free(argv);
}
