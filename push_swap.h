/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncantona <ncantona@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:40:57 by ncantona          #+#    #+#             */
/*   Updated: 2024/11/11 17:42:42 by ncantona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// diese header vorm abgegeben löschen
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				numb;
	int				pos;
	int				moves;
	int				rev;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

// sort_utils
void				ft_sort(t_list **stacka, t_list **stackb);
void				ft_count_ops(t_list *stacka, t_list *stackb, int lena,
						int lenb);
int					ft_count_ops2(t_list *stacka, t_list *stackb, int diff,
						int moves);
int					ft_get_value(t_list *stacka, int value, int valnum,
						int length);
void				ft_move_both(t_list **stacka, t_list **stackb,
						int direction);
void				ft_move(t_list *stacka, t_list **stackb);
int					ft_first(t_list *stacka);
void				ft_sort_small(t_list **stacka, int argc);
t_list				*ft_first_sort(t_list **stacka, t_list *stackb, int argc);
void				ft_sort_3(t_list **stacka);
t_list				*ft_first_sort(t_list **stacka, t_list *stackb, int argc);
t_list				*ft_move_to_first(t_list *stacka);

// list utils
int					ft_lstlen(t_list *stack);
t_list				*ft_fill_stack(int argc, char **argv);
t_list				*ft_addlst_bottom(t_list *stack, int numb);
t_list				*ft_addlst_front(t_list *stack, int numb);
t_list				*ft_newlst(int numb);
t_list				*ft_dellst(t_list *lst);
void				ft_free_list(t_list *head);

// utils
int					ft_atoi(char *nptr);
int long			ft_atol(char *nptr);
int					ft_calc(t_list *stacka, t_list *stackb);
void				*ft_calloc(size_t nmemb, size_t size);
size_t				ft_strlen(const char *s);
char				**ft_split(char const *s, char c);
int					ft_countarg(char **argv);
void				ft_error(void);
void 				ft_free_argv(char **argv);

// error
int					ft_checkup(int argc, char **argv);

// operations that are allowed to use
void				ft_swap(t_list *stack, char *operation);
t_list				*ft_push(t_list **src, t_list *dest, char *operation);
void				ft_rotate(t_list **stack, char *operation);
void				ft_reverse_rotate(t_list **stack, char *operation);

#endif