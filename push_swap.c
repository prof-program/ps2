/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncantona <ncantona@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:35:18 by ncantona          #+#    #+#             */
/*   Updated: 2024/11/11 17:55:50 by ncantona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stacka;
	t_list	*stackb;

	stackb = NULL;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			exit (1);
		argc = ft_countarg(argv);
	}
	ft_checkup(argc, argv);
	stacka = ft_fill_stack(argc, argv);
	ft_sort_small(&stacka, argc);
	stackb = ft_first_sort(&stacka, stackb, argc);
	while (argc > 4)
	{
		ft_count_ops(stackb, stacka, ft_lstlen(stackb), ft_lstlen(stacka));
		ft_sort(&stackb, &stacka);
		argc--;
	}
	stacka = ft_move_to_first(stacka);
	ft_free_list(stacka);
}

// giving each number the value pos for the position in stacka

void	ft_count_ops(t_list *stacka, t_list *stackb, int lena, int lenb)
{
	int	stackpos;
	int	i;
	int	j;
	int	diff;

	i = 0;
	stackpos = 0;
	while (i < lena)
	{
		j = 0;
		diff = ft_calc(stacka, stackb) + 1;
		while (j < lenb)
		{
			diff = ft_count_ops2(stacka, stackb, diff, j);
			stackb = stackb->next;
			j++;
		}
		stacka->pos = stackpos;
		while (j-- > 0)
			stackb = stackb->next;
		stacka = stacka->next;
		i++;
		stackpos++;
	}
}

// setting the values moves for the moves needed
// to get the number in the right place in stackb
// and rev for saying in which direction stackb need
// to get rotated for more efficiency

int	ft_count_ops2(t_list *stacka, t_list *stackb, int diff, int moves)
{
	int	putfront;
	int	lenb;

	lenb = ft_lstlen(stackb);
	putfront = 0;
	if (ft_calc(stacka, stackb) < diff)
	{
		diff = ft_calc(stacka, stackb);
		if (stacka->numb > stackb->numb)
			putfront = 1;
		else
			putfront = 0;
		if (moves > lenb / 2)
		{
			stacka->moves = lenb - moves - putfront;
			stacka->rev = 1;
		}
		else
		{
			stacka->moves = moves + putfront;
			stacka->rev = 0;
		}
	}
	return (diff);
}

// using the values setted in the previous function
// to get the number in the right position

void	ft_sort(t_list **stacka, t_list **stackb)
{
	int	pos;
	int	moves;
	int	direction;

	pos = ft_get_value(*stacka, 0, 1, ft_lstlen(*stacka));
	moves = ft_get_value(*stacka, 0, 2, ft_lstlen(*stacka));
	direction = ft_get_value(*stacka, 0, 3, ft_lstlen(*stacka));
	while (pos > 0 && moves > 0)
	{
		ft_move_both(stacka, stackb, direction);
		pos--;
		moves--;
	}
	while (pos-- > 0)
		ft_rotate(stacka, "rb\n");
	ft_move(*stacka, stackb);
	*stackb = ft_push(stacka, *stackb, "pa\n");
	if (!*stackb)
	{
		ft_free_list(*stackb);
		exit(1);
	}
}
