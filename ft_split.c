/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncantona <ncantona@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:13:37 by ncantona          #+#    #+#             */
/*   Updated: 2024/11/11 17:48:27 by ncantona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_count(char *str, char c)
{
	size_t	index1;
	size_t	index2;

	index1 = 0;
	index2 = 0;
	while (str[index1] && str[index1] == c)
		index1++;
	while (str[index1])
	{
		while (str[index1] != c && str[index1])
			index1++;
		if (str[index1] == c)
			index2++;
		while (str[index1] == c && str[index1])
			index1++;
	}
	if (ft_strlen(str) != 0 && str[index1 - 1] != c && str[index1 - 1])
		index2++;
	return (index2 + 1);
}

static int	ft_free(char **ptr, int index3)
{
	while (index3 >= 0)
	{
		free(ptr[index3]);
		index3--;
	}
	free(ptr);
	return (1);
}

static int	ft_declare(char **ptr, char c, int index2, char *str)
{
	int	index1;
	int	index3;
	int	index4;

	index1 = 0;
	index3 = 1;
	ptr[0] = ft_calloc(1, 2);
	if (!ptr[0])
		return (1);
	while (index3 < index2 && str[index1])
	{
		index4 = 0;
		while (str[index1] == c && str[index1])
			index1++;
		while (str[index1] != c && str[index1])
		{
			index1++;
			index4++;
		}
		ptr[index3] = ft_calloc(1, index4 + 1);
		if (!ptr[index3])
			return (ft_free(ptr, index3 - 1));
		index3++;
	}
	return (0);
}

static void	ft_sign(char **ptr, int index2, char c, char *str)
{
	int	index1;
	int	index3;
	int	index4;

	index1 = 0;
	index3 = 1;
	index4 = 0;
	if (ptr[0])
		ptr[0][0] = '!';
	while (index3 < index2 && str[index1])
	{
		while (str[index1] == c && str[index1])
			index1++;
		while (str[index1] != c && str[index1])
		{
			ptr[index3][index4] = str[index1];
			index1++;
			index4++;
		}
		index4 = 0;
		index3++;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	index2;
	char	**ptr;

	if (!s)
		return (NULL);
	index2 = ft_count((char *)s, c);
	if (index2 == 1)
		ft_error();
	if (index2 == 0)
	{
		ptr = ft_calloc(sizeof(char *), 1);
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	if (c == '\0' && index2 == 2)
		index2 = 1;
	ptr = ft_calloc(sizeof(char *), index2 + 1);
	if (!ptr)
		return (NULL);
	if (ft_declare(ptr, c, index2, (char *)s) == 1)
		return (NULL);
	ft_sign(ptr, index2, c, (char *)s);
	return (ptr);
}
