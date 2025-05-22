/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giomastr <giomastr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:34:18 by giomastr          #+#    #+#             */
/*   Updated: 2025/04/04 14:41:45 by giomastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_n_null(char **buffer)
{
	while (buffer && *buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
}

char	*get_the_leftovers(char *the_stash)
{
	int		i;
	char	*the_leftovers;

	i = 0;
	while (the_stash[i] != '\0' && the_stash[i] != '\n')
		i++;
	if (the_stash[i] == '\0')
		return (free_n_null(&the_stash), NULL);
	the_leftovers = gnl_substr(the_stash, (i + 1),
			(gnl_strlen(the_stash) - (i - 1)));
	if (!the_leftovers)
		return (NULL);
	free(the_stash);
	return (the_leftovers);
}

char	*get_the_line(char *the_stash)
{
	int	i;

	i = 0;
	while (the_stash[i] != '\0' && the_stash[i] != '\n')
		i++;
	if (the_stash[i] == '\n')
		i++;
	if (i == 0)
		return (NULL);
	return (gnl_substr(the_stash, 0, i));
}

char	*read_the_stuff(int fd, char *the_stash)
{
	int		the_bytes;
	char	*the_chunk;

	the_chunk = (char *)gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!the_chunk)
		return (NULL);
	the_bytes = 1;
	while (the_bytes > 0)
	{
		the_bytes = read(fd, the_chunk, BUFFER_SIZE);
		if (the_bytes == -1)
			return (free_n_null(&the_chunk), free_n_null(&the_stash), NULL);
		the_chunk[the_bytes] = '\0';
		the_stash = gnl_str_add(the_stash, the_chunk);
		if (gnl_strchr(the_stash, '\n') || the_bytes == 0)
			break ;
	}
	free_n_null(&the_chunk);
	return (the_stash);
}

char	*get_next_line(int fd)
{
	static char	*the_stash[MAX_FD];
	char		*the_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	the_stash[fd] = read_the_stuff(fd, the_stash[fd]);
	if (!the_stash[fd])
	{
		free_n_null(&the_stash[fd]);
		return (NULL);
	}
	the_line = get_the_line(the_stash[fd]);
	the_stash[fd] = get_the_leftovers(the_stash[fd]);
	return (the_line);
}
/* 
int main(int argc, char *argv[])
{
	int		fd1;
	//int		fd2;
	//int		fd3;
	char	*line;

	(void)argc;
	//fd1 = 100;
	fd1 = open(argv[1], O_RDONLY);
	//fd2 = open(argv[2], O_RDONLY);
	//fd3 = open(argv[3], O_RDONLY);

	if (fd1 < 0)
	{
		printf("error");
		return (1);
	}
	line = get_next_line(fd1);
	
	while (line != NULL)
	{
		printf("1: %s", line);
		free(line);
		
		// line = get_next_line(fd2);
		// printf("2: %s", line);
		// free(line);
		
		// line = get_next_line(fd3);
		// printf("3: %s", line);
		// free(line);
		
		line = get_next_line(fd1);
	}
	close(fd1);
	//close(fd2);
	//close(fd3);
	free(line);
	return (0);
} */