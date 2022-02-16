/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hardsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:17:45 by acash             #+#    #+#             */
/*   Updated: 2021/12/01 16:17:46 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_orderec(int count, int *ar, t_mylist **a)
{
	t_mylist	*ls;
	int			i;

	ls = *a;
	while (ls)
	{
		i = 0;
		while (i < count)
		{
			if (ar[i] == ls->value)
				ls->order = i;
			i++;
		}
		ls = ls->next;
	}
}

void	ft_presort(int count, int *ar, t_mylist **a)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (ar[i] > ar[j])
			{
				tmp = ar[i];
				ar[i] = ar[j];
				ar[j] = tmp;
			}
			j++;
		}
		i++;
	}
	ft_orderec(count, ar, a);
}

void	ft_start(int count, t_mylist **a, t_mylist **b, int *mmm)
{
	int	i;

	i = count - 1;
	while (i >= 0)
	{
		if ((*a)->order == mmm[2] || (*a)->order == mmm[0]
			|| (*a)->order == mmm[1])
			ft_ra(a, 0);
		else
		{
			if ((*a)->order > mmm[1])
			{
				ft_pb(a, b);
				ft_rb(b, 0);
			}
			else
				ft_pb(a, b);
		}
		i--;
	}
}

void	ft_move(t_mylist **a, t_mylist **b)
{
	t_mylist	*bb;
	t_mylist	*aa;
	int			ss;
	int			code;
	int			keyw[4];

	keyw[0] = 0;
	keyw[1] = 0;
	keyw[2] = 0;
	keyw[3] = 0;
	bb = *b;
	aa = *a;
	ss = 10000;
	ft_finder(bb, &ss, &code);
	while ((*b)->del != ss)
	{
		if (code == 1)
			keyw[1] += ft_rb(b, 1);
		if (code == 2)
			keyw[3] += ft_rrb(b, 1);
	}
	ft_fcnorm(a, b, keyw);
	ft_print(keyw[0], keyw[1], 0);
	ft_move_hs(aa, a, b, keyw);
}

void	ft_hardsort(int count, t_mylist **a, t_mylist **b, int *arr)
{
	int	mmm[3];
	int	a_count;

	mmm[2] = count - 1;
	mmm[1] = (count - 1) / 2;
	mmm[0] = 0;
	a_count = 3;
	ft_presort(count, arr, a);
	ft_start(count, a, b, mmm);
	ft_sortth(a);
	ft_scoreb(count, b, a_count);
	ft_scoreuodate(count, b, a, a_count);
	ft_help_hs(count, a, b, a_count);
}
