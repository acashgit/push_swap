/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:08:29 by acash             #+#    #+#             */
/*   Updated: 2022/02/15 20:37:52 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_finder(t_mylist *bb, int *ss, int *code)
{
	while (bb)
	{
		if (bb->del < (*ss))
		{
			(*ss) = bb->del;
			(*code) = bb->bsycele;
		}
		bb = bb->next;
	}
}

int	*ft_checkargv(int *count, char **argv, int *enter)
{
	char	**s;
	int		i;

	i = 0;
	if (ft_strlen(argv[1]) <= 1)
		ft_omegal(&argv[1][0]);
	s = ft_split(argv[1], ' ');
	while (s[i])
		i++;
	(*count) = i;
	if (enter)
		free(enter);
	enter = malloc(sizeof(int) * (i));
	enter = ft_fill(i, enter, s, 0);
	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (enter);
}

void	ft_move_hs(t_mylist *aa, t_mylist **a, t_mylist **b, int *keyw)
{
	while ((*b)->order < ft_lastll(aa)->order && (*b)->order < (*a)->order)
		keyw[2] += ft_rra(a, 1);
	ft_print2(keyw[2], keyw[3], 0);
	ft_pa(a, b);
}

void	ft_myfree(int *enter, t_mylist **stack_a, t_mylist **stack_b)
{
	free(enter);
	ft_list_clear(stack_a);
	ft_list_clear(stack_b);
}

int	main(int argc, char **argv)
{
	int			*enter;
	t_mylist	*stack_a;
	t_mylist	*stack_b;
	int			count;

	count = argc - 1;
	if (argc == 1)
		return (0);
	enter = malloc(sizeof(int) * (count));
	if (argc == 2)
		enter = ft_checkargv(&count, argv, enter);
	else
		enter = ft_fill(count + 1, enter, argv, 1);
	if (enter == NULL)
		ft_error();
	ft_checkargs(count, enter);
	stack_a = ft_filllist(count, enter);
	if (count < 6)
		ft_easysort(count, &stack_a, &stack_b);
	if (count >= 6)
		ft_hardsort(count, &stack_a, &stack_b, enter);
	ft_myfree(enter, &stack_a, &stack_b);
	return (0);
}
