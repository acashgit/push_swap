/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:02:29 by acash             #+#    #+#             */
/*   Updated: 2021/11/28 20:02:32 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rra(t_mylist **stack_a, int code)
{
	t_mylist	*save;
	t_mylist	*save1;
	t_mylist	*a;

	a = *stack_a;
	if (a == NULL || a->next == NULL)
		return (-1);
	save = a;
	while (save->next)
	{
		save1 = save;
		save = save->next;
	}
	save->next = a;
	save1->next = NULL;
	*stack_a = save;
	if (code == 0)
		ft_putstr("rra\n");
	return (1);
}

int	ft_rrb(t_mylist **stack_b, int code)
{
	t_mylist	*save;
	t_mylist	*save1;
	t_mylist	*b;

	b = *stack_b;
	if (b == NULL || b->next == NULL)
		return (-1);
	save = b;
	while (save->next)
	{
		save1 = save;
		save = save->next;
	}
	save->next = b;
	save1->next = NULL;
	*stack_b = save;
	if (code == 0)
		ft_putstr("rrb\n");
	return (1);
}

int	ft_rrr(t_mylist **stack_a, t_mylist **stack_b, int code)
{
	ft_rra(stack_a, 1);
	ft_rrb(stack_b, 1);
	if (code == 0)
		ft_putstr("rrr\n");
	return (1);
}

t_mylist	*ft_lastll(t_mylist *stack_a)
{
	t_mylist	*ls;

	ls = stack_a;
	while (ls->next)
	{
		ls = ls->next;
	}
	return (ls);
}

void	ft_omegal(char *s)
{
	int	digit;

	digit = ft_atoi(s);
}
