/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:18:29 by acash             #+#    #+#             */
/*   Updated: 2021/12/04 13:18:30 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_scoreb(int count, t_mylist **b, int a_count)
{
	int			i;
	t_mylist	*bb;
	int			size;

	i = 0;
	bb = *b;
	size = count - a_count;
	while (i < size)
	{
		if (i < (size / 2 + 1))
		{
			bb->del = i;
			bb->bsycele = 1;
		}
		else
		{
			bb->del = size - i;
			bb->bsycele = 2;
		}
		bb = bb->next;
		i++;
	}
}

int	ft_dssl(int i, int a_count, t_mylist *b, int minsc)
{
	if (i < ((a_count / 2) + 1))
	{
		if (minsc > i)
		{	
			b->asycele = 1;
			return (i);
		}
	}
	else
	{
		if (minsc > i)
		{	
			b->asycele = 2;
			return (a_count - i);
		}
	}
	return (minsc);
}

void	ft_findasc(t_mylist *b, t_mylist **a, int a_count)
{
	t_mylist	*aa;
	int			minsc;
	int			i;

	aa = *a;
	minsc = 10000;
	i = 0;
	while (i < a_count)
	{
		while (aa->order < b->order)
		{
			aa = aa->next;
			i++;
		}
		minsc = ft_dssl(i, a_count, b, minsc);
		i++;
	}
	b->del += minsc;
}

void	ft_scoreuodate(int count, t_mylist **b, t_mylist **a, int a_count)
{
	int			i;
	t_mylist	*bb;
	int			size;

	i = 0;
	bb = *b;
	size = count - a_count;
	while (i < size)
	{
		ft_findasc(bb, a, a_count);
		bb = bb->next;
		i++;
	}
}

void	ft_help_hs(int count, t_mylist **a, t_mylist **b, int a_count)
{
	int	i;
	int	omega;

	i = 0;
	omega = 0;
	while (i < count - 3)
	{
		ft_move(a, b);
		a_count++;
		ft_scoreb(count, b, a_count);
		ft_scoreuodate(count, b, a, a_count);
		i++;
	}
	while ((*a)->order != 0)
		omega += ft_ra(a, 1);
	ft_printend(omega, count);
}
