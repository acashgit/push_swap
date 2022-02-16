/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_listop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:51:23 by acash             #+#    #+#             */
/*   Updated: 2021/11/24 12:51:25 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_mylist	*ft_create_elem(int value, int order, int del)
{
	t_mylist	*list;

	list = (t_mylist *)malloc(sizeof(t_mylist));
	if (list)
	{
		list->value = value;
		list->order = order;
		list->del = del;
		list->asycele = -1;
		list->bsycele = -1;
		list->next = NULL;
		list->prev = NULL;
	}
	return (list);
}

void	ft_list_clear(t_mylist **lst)
{
	t_mylist	*mylist;

	if (!lst)
		return ;
	while (*lst)
	{
		mylist = (*lst)->next;
		free(*lst);
		*lst = mylist;
	}
	*lst = NULL;
}

void	ft_print2(int rra, int rrb, int i)
{
	if (rra > rrb)
	{
		while (i < rrb)
		{
			ft_putstr("rrr\n");
			i++;
		}
		while (i < rra)
		{
			ft_putstr("rra\n");
			i++;
		}
	}
	else
	{
		while (rra)
		{
			ft_putstr("rrr\n");
			rra--;
			rrb--;
		}
		while (rrb--)
			ft_putstr("rrb\n");
	}
}

void	ft_printend(int omega, int count)
{
	int	i;

	i = 0;
	if (omega > (count / 2) + 1)
	{
		while (i < omega - count)
		{
			ft_putstr("rra\n");
			i++;
		}
	}
	else
	{
		while (i < omega)
		{
			ft_putstr("ra\n");
			i++;
		}
	}
}

void	ft_fcnorm(t_mylist **a, t_mylist **b, int *keyw)
{
	while ((*a)->order < (*b)->order)
	{
		if ((*b)->asycele == 1)
			keyw[0] += ft_ra(a, 1);
		if ((*b)->asycele == 2)
			keyw[2] += ft_rra(a, 1);
	}
}
