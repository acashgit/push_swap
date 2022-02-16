/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_aegcheck.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:21:07 by acash             #+#    #+#             */
/*   Updated: 2021/11/24 14:21:08 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_checkargs(size_t count, int *a)
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
	exit(0);
}

int	*ft_fill(int count, int *stack_a, char **str, int code)
{
	int		*save;
	int		i;
	int		j;

	i = 0;
	if (code == 0)
		j = 0;
	else
		j = 1;
	save = malloc(sizeof(int) * (count - j));
	if (save == NULL)
		return (NULL);
	while (j < count)
	{
		save[i] = ft_atoi(str[j]);
		i++;
		j++;
	}
	free(stack_a);
	stack_a = save;
	return (stack_a);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

t_mylist	*ft_filllist(int count, int *a)
{
	t_mylist	*list;
	t_mylist	*save;
	int			i;

	list = ft_create_elem(a[0], 0, 0);
	i = 1;
	save = list;
	while (i < count)
	{
		list->next = ft_create_elem(a[i], 0, 0);
		list = list->next;
		i++;
	}
	save->prev = list;
	return (save);
}

void	ft_print(int ra, int rb, int i)
{
	if (ra > rb)
	{
		while (i < rb)
		{
			ft_putstr("rr\n");
			i++;
		}
		while (i < ra)
		{
			ft_putstr("ra\n");
			i++;
		}
	}
	else
	{
		while (ra)
		{
			ft_putstr("rr\n");
			ra--;
			rb--;
		}
		while (rb--)
			ft_putstr("rb\n");
	}
}
