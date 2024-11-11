/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncantona <ncantona@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 04:32:49 by ncantona          #+#    #+#             */
/*   Updated: 2024/11/11 17:49:17 by ncantona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// function to convert a string into an integer

int	ft_atoi(char *nptr)
{
	int	result;
	int	isminus;

	result = 0;
	isminus = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			isminus = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * isminus);
}

// calculating the difference between the two stacks
// and give back always a positive number

int	ft_calc(t_list *stacka, t_list *stackb)
{
	if (stacka->numb > stackb->numb)
		return (stacka->numb - stackb->numb);
	else
		return (stackb->numb - stacka->numb);
}

// converts a string number into a long int

int long	ft_atol(char *nptr)
{
	int long	result;
	int			isminus;

	result = 0;
	isminus = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			isminus = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * isminus);
}

// allocating some memory and sets everything to NULl

void	*ft_calloc(size_t nmemb, size_t size)
{
	int				result;
	unsigned char	*ptr;
	int				index;

	index = 0;
	result = nmemb * size;
	if (nmemb != 0)
		if (result / nmemb != size)
			return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (index < result)
	{
		ptr[index] = 0;
		index++;
	}
	return ((void *)ptr);
}

// counting the length of a string and returning it

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}
