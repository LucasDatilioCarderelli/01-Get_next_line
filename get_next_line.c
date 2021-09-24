/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:37:17 by ldatilio          #+#    #+#             */
/*   Updated: 2021/09/23 16:37:12 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

BUFFER_SIZE = 42;

char	*make_backup(fd, backup, buffer)
{
	if (read(fd, buffer, BUFFER_SIZE) == -1)
		return (NULL);
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*backup;

	if (!BUFFER_SIZE || !fd)
		return (0);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	backup = make_backup(fd, backup, buffer);
	line = make_line(backup);
	return (line);
}

int	main(void)
{
	FILE	*file;

	file = open("test.txt", "r");
	printf("%s", get_next_line(file));
	return (0);
}
