/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:19:26 by ldatilio          #+#    #+#             */
/*   Updated: 2021/09/30 16:46:00 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*make_backup(int fd, char *backup, char	*buffer)
{
	int		bytes;
	int		control;
	char	*temp;

	bytes = 1;
	control = 0;
	while (control == 0 && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1 )
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(backup, buffer);
		free(temp);
		if (ft_strchr(backup, '\n'))
			control = 1;
	}
	free(buffer);
	return (backup);
}

static char	*make_line(char *backup)
{
	int		i;
	char	*line;

	i = 0;
	while (backup[i] && backup[i - 1] != '\n')
		i++;
	line = malloc(sizeof(char *) * (i + 1));
	if (!line)
		return (NULL);
	ft_strlcpy(line, backup, i + 1);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static char	*make_newbackup(char *backup)
{
	int		i;
	int		lenbackup;
	char	*newbackup;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (backup[i] == '\0')
	{
		free(backup);
		return (NULL);
	}
	lenbackup = ft_strlen(backup);
	newbackup = (char *)malloc(sizeof(char) * (lenbackup - i + 1));
	if (!newbackup)
		return (NULL);
	ft_strlcpy(newbackup, backup + i + 1, lenbackup - i + 1);
	free(backup);
	return (newbackup);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*backup[FD_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_MAX)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	backup[fd] = make_backup(fd, backup[fd], buffer);
	if (!backup[fd])
		return (NULL);
	line = make_line(backup[fd]);
	backup[fd] = make_newbackup(backup[fd]);
	return (line);
}
