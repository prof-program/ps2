/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncantona <ncantona@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 04:33:04 by ncantona          #+#    #+#             */
/*   Updated: 2024/11/07 11:56:35 by ncantona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// deletes the head of the linked list

t_list	*ft_dellst(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	temp->prev->next = lst->next;
	temp->next->prev = lst->prev;
	temp = temp->next;
	free(lst);
	return (temp);
}
// freeing the whole given list

void	ft_free_list(t_list *lst)
{
	t_list	*temp;
	t_list	*next;

	if (lst == NULL)
		return ;
	temp = lst;
	next = NULL;
	while (temp->next != lst)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	free(temp);
	lst = NULL;
}
