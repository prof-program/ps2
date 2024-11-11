/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncantona <ncantona@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 04:30:22 by ncantona          #+#    #+#             */
/*   Updated: 2024/11/07 11:57:18 by ncantona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sorts a list of size 2

void	ft_sort_2(t_list **stacka)
{
	ft_swap(*stacka, "sa\n");
	ft_free_list(*stacka);
	exit(0);
}

// sorts a list of size 3

void	ft_sort_3(t_list **stacka)
{
	t_list	*tmp;

	tmp = *stacka;
	if (tmp->numb < tmp->next->numb && tmp->numb > tmp->next->next->numb)
		ft_reverse_rotate(stacka, "rra\n");
	else if (tmp->numb > tmp->next->numb
		&& tmp->next->numb > tmp->next->next->numb)
	{
		ft_swap(*stacka, "sa\n");
		ft_reverse_rotate(stacka, "rra\n");
	}
	else if (tmp->numb < tmp->next->numb && tmp->numb < tmp->next->next->numb)
	{
		ft_swap(*stacka, "sa\n");
		ft_rotate(stacka, "ra\n");
	}
	else if (tmp->numb > tmp->next->numb && tmp->numb > tmp->next->next->numb)
		ft_rotate(stacka, "ra\n");
	else if (tmp->numb > tmp->next->numb && tmp->numb < tmp->next->next->numb)
		ft_swap(*stacka, "sa\n");
}

// checking if its less than 3 and if true its getting sorted

void	ft_sort_small(t_list **stacka, int argc)
{
	if (argc < 5)
	{
		if (argc == 4)
			ft_sort_3(stacka);
		if (argc == 3)
			ft_sort_2(stacka);
		ft_free_list(*stacka);
		exit(0);
	}
}

// pushes everything above size 3 to b and sorts the remaining 3

t_list	*ft_first_sort(t_list **stacka, t_list *stackb, int argc)
{
	int	i;

	i = 0;
	while (argc > 4)
	{
		stackb = ft_push(stacka, stackb, "pb\n");
		if (!stackb)
		{
			ft_free_list(*stacka);
			exit(1);
		}
		argc--;
	}
	if ((*stacka)->numb < (*stacka)->next->numb
		&& (*stacka)->next->numb < (*stacka)->next->next->numb)
		i = 1;
	if (i == 0)
		ft_sort_3(stacka);
	return (stackb);
}
