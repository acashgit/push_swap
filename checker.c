/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:36:04 by acash             #+#    #+#             */
/*   Updated: 2021/12/08 23:36:06 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_bcheckargv(int *count, char **argv, int *enter)
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

void	ft_myfree(int *enter, t_mylist **stack_a, t_mylist **stack_b)
{
	free(enter);
	ft_list_clear(stack_a);
	ft_list_clear(stack_b);
}

void	ft_resulttt(t_mylist *a, t_mylist *b)
{
	int		flag;
	long	tmp;

	tmp = -2147483699;
	flag = 0;
	(void)b;
	if (b != NULL)
		flag = 1;
	while (a)
	{
		if (a->value < tmp)
			flag = 1;
		tmp = a->value;
		a = a->next;
	}
	if (flag == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

void	ft_step(t_mylist **a, t_mylist **b)
{
	char	*line;

	while (get_next_line(&line))
	{
		if (ft_read_comm(a, b, line) == 0)
			ft_error();
		free(line);
	}
	free(line);
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
		enter = ft_bcheckargv(&count, argv, enter);
	else
		enter = ft_fill(count + 1, enter, argv, 1);
	if (enter == NULL)
		ft_error();
	ft_bcheckargs(count, enter);
	stack_a = ft_filllist(count, enter);
	ft_step(&stack_a, &stack_b);
	ft_resulttt(stack_a, stack_b);
	ft_myfree(enter, &stack_a, &stack_b);
	return (0);
}
