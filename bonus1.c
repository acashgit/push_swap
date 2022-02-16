/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 10:40:12 by acash             #+#    #+#             */
/*   Updated: 2021/12/09 10:40:13 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && (s1[i] == s2[i]))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_bpb(t_mylist **stack_a, t_mylist **stack_b)
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
	return (1);
}

int	ft_bpa(t_mylist **stack_a, t_mylist **stack_b)
{
	t_mylist	*save;
	t_mylist	*a;
	t_mylist	*b;

	a = *stack_a;
	b = *stack_b;
	if (b == NULL)
		return (1);
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
	return (1);
}

int	ft_read_comm(t_mylist **a, t_mylist **b, char *line)
{
	if (!(ft_strcmp(line, "sa")))
		return (ft_sa(a, 1));
	if (!(ft_strcmp(line, "sb")))
		return (ft_sb(b, 1));
	if (!(ft_strcmp(line, "ss")))
		return (ft_ss(a, b, 1));
	if (!(ft_strcmp(line, "pa")))
		return (ft_bpa(a, b));
	if (!(ft_strcmp(line, "pb")))
		return (ft_bpb(a, b));
	if (!(ft_strcmp(line, "ra")))
		return (ft_ra(a, 1));
	if (!(ft_strcmp(line, "rb")))
		return (ft_rb(b, 1));
	if (!(ft_strcmp(line, "rr")))
		return (ft_rr(a, b, 1));
	if (!(ft_strcmp(line, "rra")))
		return (ft_rra(a, 1));
	if (!(ft_strcmp(line, "rrb")))
		return (ft_rrb(b, 1));
	if (!(ft_strcmp(line, "rrr")))
		return (ft_rrr(a, b, 1));
	return (0);
}

void	ft_bcheckargs(size_t count, int *a)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (a[i] == a[j])
				ft_error();
			j++;
		}
		i++;
	}
	i = 0;
	while (i < count - 1)
	{
		if (a[i] > a[i + 1])
			return ;
		i++;
	}
}
