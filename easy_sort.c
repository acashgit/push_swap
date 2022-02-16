/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:04:41 by acash             #+#    #+#             */
/*   Updated: 2021/11/24 15:04:43 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sortth(t_mylist **a)
{
	if ((*a)->value > (*a)->next->value
		&& (*a)->value > (*a)->next->next->value)
	{
		if ((*a)->next->value > (*a)->next->next->value)
		{
			ft_ra(a, 0);
			ft_sa(a, 0);
		}
		else
			ft_ra(a, 0);
	}
	else if ((*a)->next->value > (*a)->value
		&& (*a)->next->value > (*a)->next->next->value)
	{
		ft_rra(a, 0);
		if ((*a)->value > (*a)->next->value)
			ft_sa(a, 0);
	}
	else if ((*a)->next->next->value > (*a)->next->value
		&& (*a)->next->next->value > (*a)->value
		&& (*a)->value > (*a)->next->value)
		ft_sa(a, 0);
}

void	ft_sortfo(t_mylist **a, t_mylist **b)
{
	if ((*a)->next->value > (*a)->value
		&& (*a)->next->value > (*a)->next->next->value
		&& (*a)->next->value > (*a)->next->next->next->value)
		ft_ra(a, 0);
	else if ((*a)->next->next->value > (*a)->next->value
		&& (*a)->next->next->value > (*a)->value
		&& (*a)->next->next->value > (*a)->next->next->next->value)
	{
		ft_ra(a, 0);
		ft_ra(a, 0);
	}
	else if ((*a)->next->next->next->value > (*a)->next->value
		&& (*a)->next->next->next->value > (*a)->next->next->value
		&& (*a)->next->next->next->value > (*a)->value)
		ft_rra(a, 0);
	ft_pb(a, b);
	ft_sortth(a);
	ft_pa(a, b);
	ft_ra(a, 0);
}

void	ft_sortfi(t_mylist **a, t_mylist **b)
{
	if ((*a)->next->value > (*a)->value && (*a)->next->value
		> (*a)->next->next->value && (*a)->next->value
		> (*a)->next->next->next->value
		&& (*a)->next->value > (*a)->next->next->next->next->value)
		ft_ra(a, 0);
	else if ((*a)->next->next->value > (*a)->value
		&& (*a)->next->next->value > (*a)->next->value
		&& (*a)->next->next->value > (*a)->next->next->next->value
		&& (*a)->next->next->value > (*a)->next->next->next->next->value)
		fc_norm_help(a, b, 1);
	else if ((*a)->next->next->next->value > (*a)->value
		&& (*a)->next->next->next->value > (*a)->next->value
		&& (*a)->next->next->next->value > (*a)->next->next->value
		&& (*a)->next->next->next->value > (*a)->next->next->next->next->value)
		fc_norm_help(a, b, 2);
	else if ((*a)->next->next->next->next->value > (*a)->value
		&& (*a)->next->next->next->next->value > (*a)->next->value
		&& (*a)->next->next->next->next->value > (*a)->next->next->value
		&& (*a)->next->next->next->next->value > (*a)->next->next->next->value)
		ft_rra(a, 0);
	fc_norm_help(a, b, 3);
}

void	fc_norm_help(t_mylist **a, t_mylist **b, int code)
{
	if (code == 1)
	{
		ft_ra(a, 0);
		ft_ra(a, 0);
	}
	if (code == 2)
	{
		ft_rra(a, 0);
		ft_rra(a, 0);
	}
	if (code == 3)
	{
		ft_pb(a, b);
		ft_sortfo(a, b);
		ft_pa(a, b);
		ft_ra(a, 0);
	}
}

void	ft_easysort(int count, t_mylist **stack_a, t_mylist **stack_b)
{
	if (count == 2)
		ft_sa(stack_a, 0);
	if (count == 3)
		ft_sortth(stack_a);
	if (count == 4)
		ft_sortfo(stack_a, stack_b);
	if (count == 5)
		ft_sortfi(stack_a, stack_b);
}
