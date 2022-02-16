/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:19:31 by acash             #+#    #+#             */
/*   Updated: 2021/12/09 12:19:33 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *remains, char *buffer)
{
	char	*omegalul;
	int		i;
	int		j;

	i = ft_strlen(remains) + ft_strlen(buffer);
	if (!remains && !buffer)
		return (NULL);
	omegalul = malloc(sizeof(char) * (i + 1));
	if (omegalul == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (remains)
	{
		while (remains[i])
			omegalul[j++] = remains[i++];
		i = 0;
	}
	while (buffer[i])
		omegalul[j++] = buffer[i++];
	omegalul[ft_strlen(remains) + ft_strlen(buffer)] = '\0';
	free(remains);
	return (omegalul);
}

char	*push_line(char *remains)
{
	int		i;
	char	*omega;

	i = 0;
	while (remains[i] && remains[i] != '\n')
		i++;
	omega = malloc(sizeof(char) * (i + 1));
	if (omega == NULL)
		return (NULL);
	i = 0;
	while (remains[i] && remains[i] != '\n')
	{
		omega[i] = remains[i];
		i++;
	}
	omega[i] = '\0';
	return (omega);
}

char	*cut(char *remains)
{
	int		i;
	int		j;
	char	*omega;

	i = 0;
	j = 0;
	while (remains[i] && remains[i] != '\n')
		i++;
	if (!remains)
	{
		free(remains);
		return (NULL);
	}
	omega = (char *)malloc(sizeof(char) * (ft_strlen(remains) - i + 1));
	if (omega == NULL)
		return (NULL);
	i++;
	while (remains[i] && remains[i] != '\n')
		omega[j++] = remains[i++];
	omega[j] = '\0';
	free(remains);
	return (omega);
}

int	get_next_line(char **line)
{
	int			count;
	char		buffer[BUFFER_SIZE + 1];
	static char	*remains;
	int			fd;

	count = 1;
	fd = 0;
	if (!line)
		return (-1);
	while (buffer[0] != '\n' && count != 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
			return (-1);
		buffer[count] = '\0';
		remains = ft_strjoin(remains, buffer);
	}
	*line = push_line(remains);
	remains = cut(remains);
	if (count != 0)
		return (1);
	return (0);
}
