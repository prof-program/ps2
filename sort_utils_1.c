/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncantona <ncantona@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 04:30:48 by ncantona          #+#    #+#             */
/*   Updated: 2024/11/07 11:57:07 by ncantona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returning the wanted value (position of the number,
// how many moves to get it into postion, direction of rotation)

int	ft_get_value(t_list *stacka, int value, int valnum, int length)
{
	size_t	sum;
	int		i;
	int		pos;

	sum = stacka->pos + stacka->moves;
	i = 0;
	while (i < length)
	{
		pos = stacka->pos;
		if (pos < 0)
			pos *= -1;
		if ((size_t)pos + (size_t)stacka->moves < sum)
		{
			sum = pos + stacka->moves;
			if (valnum == 1)
				value = stacka->pos;
			if (valnum == 2)
				value = stacka->moves;
			if (valnum == 3)
				value = stacka->rev;
		}
		stacka = stacka->next;
		i++;
	}
	return (value);
}

// rotating both lists

void	ft_move_both(t_list **stacka, t_list **stackb, int direction)
{
	if (direction == 0)
	{
		ft_rotate(stacka, "rr\n");
		ft_rotate(stackb, "x\n");
	}
	else if (direction == 1)
	{
		ft_rotate(stacka, "rb\n");
		ft_reverse_rotate(stackb, "rra\n");
	}
}

// rotating the list until the number is ready to push

void	ft_move(t_list *stacka, t_list **stackb)
{
	stacka->moves -= stacka->pos;
	while (stacka->moves > 0 && stacka->rev == 0)
	{
		ft_rotate(stackb, "ra\n");
		stacka->moves--;
	}
	while (stacka->moves > 0 && stacka->rev == 1)
	{
		ft_reverse_rotate(stackb, "rra\n");
		stacka->moves--;
	}
}

// searching for what should be the first number in stacka and returning it

int	ft_first(t_list *stacka)
{
	int	num;
	int	num1;

	num = stacka->numb;
	num1 = stacka->numb;
	stacka = stacka->next;
	while (stacka->numb != num1)
	{
		if (stacka->numb < num)
			num = stacka->numb;
		stacka = stacka->next;
	}
	return (num);
}

// rotates list until the head is the smallest number

t_list	*ft_move_to_first(t_list *stacka)
{
	int		first_num;
	int		ij;
	t_list	*temp;

	first_num = ft_first(stacka);
	ij = 1;
	temp = stacka;
	while (temp->numb != first_num && ij++)
		temp = temp->next;
	if (ij < (ft_lstlen(stacka) / 2 + 2))
		while (stacka->numb != first_num)
			ft_rotate(&stacka, "ra\n");
	else
		while (stacka->numb != first_num)
			ft_reverse_rotate(&stacka, "rra\n");
	return (stacka);
}
