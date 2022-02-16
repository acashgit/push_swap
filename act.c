/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 22:13:59 by acash             #+#    #+#             */
/*   Updated: 2021/11/26 22:14:02 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sa(t_mylist **stack_a, int code)
{
	t_mylist	*a;
	int			tmp;
	int			tmps;
	int			tmpo;

	a = *stack_a;
	if (a == NULL || a->next == NULL)
		return (1);
	tmp = a->value;
	a->value = a->next->value;
	a->next->value = tmp;
	tmps = a->del;
	a->del = a->next->del;
	a->next->del = tmps;
	tmpo = a->order;
	a->order = a->next->order;
	a->next->order = tmpo;
	if (code == 0)
		ft_putstr("sa\n");
	return (1);
}

int	ft_sb(t_mylist **stack_b, int code)
{
	t_mylist	*b;
	int			tmp;
	int			tmps;
	int			tmpo;

	b = *stack_b;
	if (b == NULL || b->next == NULL)
		return (1);
	tmp = b->value;
	b->value = b->next->value;
	b->next->value = tmp;
	tmps = b->del;
	b->del = b->next->del;
	b->next->del = tmps;
	tmpo = b->order;
	b->order = b->next->order;
	b->next->order = tmpo;
	if (code == 0)
		ft_putstr("sb\n");
	return (1);
}

int	ft_ss(t_mylist **stack_a, t_mylist **stack_b, int code)
{
	ft_sa(stack_a, 1);
	ft_sb(stack_b, 1);
	if (code == 0)
		ft_putstr("ss\n");
	return (1);
}

int	ft_pa(t_mylist **stack_a, t_mylist **stack_b)
{
	t_mylist	*save;
	t_mylist	*a;
	t_mylist	*b;

	a = *stack_a;
	b = *stack_b;
	if (b == NULL)
		return (0);
	save = b;
	b = b->next;
	*stack_b = b;
	if (a == NULL)
	{
		a = save;
		a->next = NULL;
		*stack_a = a;
	}
	else
	{
		save->next = a;
		*stack_a = save;
	}
	ft_putstr("pa\n");
	return (1);
}

int	ft_pb(t_mylist **stack_a, t_mylist **stack_b)
{
	t_mylist	*save;
	t_mylist	*a;
	t_mylist	*b;

	a = *stack_a;
	b = *stack_b;
	if (a == NULL)
		return (1);
	save = a;
	a = a->next;
	*stack_a = a;
	if (b == NULL)
	{
		b = save;
		b->next = NULL;
		*stack_b = b;
	}
	else
	{
		save->next = b;
		*stack_b = save;
	}
	ft_putstr("pb\n");
	return (1);
}
