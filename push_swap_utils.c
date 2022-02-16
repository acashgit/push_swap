/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:41:51 by acash             #+#    #+#             */
/*   Updated: 2021/11/24 12:41:52 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putstr("-2147483648");
			return ;
		}
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr((n / 10));
		ft_putchar('0' + n % 10);
	}
	else
		ft_putchar('0' + n);
}

int	ft_atoi(char *str)
{
	size_t	i;
	int		sign;
	long	digit;

	i = 0;
	sign = 1;
	digit = 0;
	if (ft_strlen(str) > 12)
		ft_error();
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			ft_error();
		digit = (digit * 10) + (str[i] - '0');
		i++;
	}
	if ((digit > 2147483647 && sign > 0) || (digit > 2147483648 && sign < 0))
		ft_error();
	return (digit * sign);
}

void	ft_error(void)
{
	ft_putstr("Error\n");
	exit (0);
}
