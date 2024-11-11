/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncantona <ncantona@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:16:24 by ncantona          #+#    #+#             */
/*   Updated: 2024/11/07 12:23:26 by ncantona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swaping the first 2 elements of the stack

void	ft_swap(t_list *stack, char *operation)
{
	int	tmp;

	if (stack->numb == stack->next->numb || !stack)
		return ;
	tmp = stack->numb;
	stack->numb = stack->next->numb;
	stack->next->numb = tmp;
	write(1, operation, 3);
	return ;
}

// push the first element into another given stack

t_list	*ft_push(t_list **src, t_list *dest, char *operation)
{
	static int	i;
	t_list		*temp;

	if (!dest)
		i = 1;
	if (i == 1)
		temp = ft_newlst((*src)->numb);
	else
	{
		temp = ft_addlst_front(dest, (*src)->numb);
		if (temp)
			temp->prev->next = temp;
	}
	if (!temp)
	{
		ft_free_list(*src);
		exit(1);
	}
	i++;
	write(1, operation, 3);
	*src = ft_dellst(*src);
	if (!temp)
		ft_free_list(dest);
	return (temp);
}

// shift up all elements in a stack

void	ft_rotate(t_list **stack, char *operation)
{
	t_list	*tmp;

	tmp = *stack;
	*stack = tmp->next;
	if (operation[0] != 'x')
		write(1, operation, 3);
	return ;
}

// shift down all elements in a stack

void	ft_reverse_rotate(t_list **stack, char *operation)
{
	t_list	*tmp;

	tmp = *stack;
	*stack = tmp->prev;
	if (operation[0] != 'x')
		write(1, operation, 4);
	return ;
}
