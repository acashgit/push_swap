/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:00:09 by acash             #+#    #+#             */
/*   Updated: 2022/02/15 20:37:17 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ra(t_mylist **stack_a, int code)
{
	t_mylist	*save;
	t_mylist	*save1;
	t_mylist	*a;

	a = *stack_a;
	if (a == NULL || a->next == NULL)
		return (-1);
	save = a;
	a = a->next;
	save1 = a;
	while (save1->next)
		save1 = save1->next;
	save1->next = save;
	save->next = NULL;
	*stack_a = a;
	if (code == 0)
		ft_putstr("ra\n");
	return (1);
}

int	ft_rb(t_mylist **stack_b, int code)
{
	t_mylist	*save;
	t_mylist	*save1;
	t_mylist	*b;

	b = *stack_b;
	if (b == NULL || b->next == NULL)
		return (-1);
	save = b;
	b = b->next;
	save1 = b;
	while (save1->next)
		save1 = save1->next;
	save1->next = save;
	save->next = NULL;
	*stack_b = b;
	if (code == 0)
		ft_putstr("rb\n");
	return (1);
}

int	ft_rr(t_mylist **stack_a, t_mylist **stack_b, int code)
{
	ft_ra(stack_a, 1);
	ft_rb(stack_b, 1);
	if (code == 0)
		ft_putstr("rr\n");
	return (1);
}
