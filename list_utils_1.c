/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncantona <ncantona@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 04:33:12 by ncantona          #+#    #+#             */
/*   Updated: 2024/11/11 16:12:15 by ncantona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returning the length of the linked list

int	ft_lstlen(t_list *stack)
{
	t_list	*tmp;
	int		len;

	if (!stack)
		return (0);
	tmp = stack;
	len = 1;
	stack = stack->next;
	while (stack->numb != tmp->numb)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

// filling up stacka the first time

t_list	*ft_fill_stack(int argc, char **argv)
{
	t_list	*stack;
	int		i;

	stack = ft_newlst(ft_atoi(argv[1]));
	if (!stack)
		exit(0);
	i = 2;
	while (i < argc)
	{
		stack = ft_addlst_bottom(stack, ft_atoi(argv[i]));
		if (!stack)
			exit(1);
		i++;
		if (i == argc)
			stack->next->prev = stack;
	}
	return (stack->next);
}

// creating a list and adding this list to the bottom of the given list

t_list	*ft_addlst_bottom(t_list *stack, int numb)
{
	t_list	*newlst;

	newlst = malloc(sizeof(t_list));
	if (!newlst)
	{
		ft_free_list(stack);
		return (newlst);
	}
	newlst->numb = numb;
	newlst->pos = 0;
	newlst->rev = 0;
	newlst->moves = 0;
	newlst->prev = stack;
	newlst->next = stack->next;
	newlst->prev->next = newlst;
	return (newlst);
}

// creating a list and adding this list to the top of the given list

t_list	*ft_addlst_front(t_list *stack, int numb)
{
	t_list	*newlst;

	newlst = malloc(sizeof(t_list));
	if (!newlst)
	{
		ft_free_list(stack);
		return (NULL);
	}
	newlst->numb = numb;
	newlst->pos = 0;
	newlst->rev = 0;
	newlst->moves = 0;
	newlst->prev = stack->prev;
	newlst->next = stack;
	newlst->next->prev = newlst;
	return (newlst);
}

// creating the head of the list and linking it to itself

t_list	*ft_newlst(int numb)
{
	t_list	*newlst;

	newlst = malloc(sizeof(t_list));
	if (!newlst)
		return (NULL);
	newlst->numb = numb;
	newlst->pos = 0;
	newlst->rev = 0;
	newlst->moves = 0;
	newlst->prev = newlst;
	newlst->next = newlst;
	return (newlst);
}
