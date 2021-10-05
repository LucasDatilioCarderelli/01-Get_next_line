/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 22:18:45 by ldatilio          #+#    #+#             */
/*   Updated: 2021/10/05 13:50:20 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mandatory/get_next_line.h"
#include "./bonus/get_next_line_bonus.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

static void	readfd(int fd)
{
	int		i;
	char	*line;

	i = 0;
	printf("\nfd: %i\n", fd);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("Line %i >>> %s", i++, line);
		free(line);
	}
	close(fd);
}

int	main(void)
{
	int		fd0;
	int		fd1;
	int		fd2;

	fd0 = open("test0", O_RDONLY);
	fd1 = open("test1", O_RDONLY);
	fd2 = open("test2", O_RDONLY);
	readfd(fd0);
	readfd(fd1);
	readfd(fd0);
	readfd(fd2);
	return (0);
}
