/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 01:41:27 by pdolinar          #+#    #+#             */
/*   Updated: 2022/04/11 10:55:17 by pdolinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* if there is no newline character '\n' in a string, return 0, otherwise 1 */

size_t	ft_check_for_nl(const char *str, int c)
{
	size_t	len;
	size_t	counter;

	if (str == NULL)
		return (0);
	len = ft_strlen(str);
	counter = 0;
	while (str[counter] != c && counter < len)
			counter++;
	if (counter == len)
		return (0);
	else
		return (1);
}

/*  read from a file and concatenate strings of buffer as long as there is no
	'\n' in	holder (static variable) or -> an empty buffer and an empty holder.
*/

char	*ft_read_buffer(int fd, char *holder)
{
	char		*buffer;
	ssize_t		v;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	v = 1;
	while (v > 0 && ft_check_for_nl(holder, '\n') == 0)
	{
		v = read(fd, buffer, BUFFER_SIZE);
		if (v == -1 || (holder == NULL && buffer[0] == '\0'))
		{
			free(buffer);
			return (NULL);
		}
		holder = ft_strjoin(holder, buffer);
		ft_bzero(buffer, BUFFER_SIZE + 1);
	}
	free(buffer);
	return (holder);
}

/*  process the output from *ft_read_buffer function into a final line
	(including '\n') if there is a '\n' present. The remainder gets
	stored into the holder. Otherwise call ft_remainder.
*/

char	*ft_return_line(char **holder)
{
	char	*tmp;
	char	*t1;
	int		i;
	int		j;

	if (ft_check_for_nl(*holder, '\n') == 1)
	{
		i = 0;
		while ((*holder)[i] != '\n')
			i++;
		tmp = ft_strdup(*holder, i + 1);
		j = i + 1;
		while ((*holder)[i] != '\0')
			i++;
		t1 = *holder;
		if ((*holder)[j] == '\0')
			*holder = NULL;
		else
			*holder = ft_strdup(*holder + j, ft_strlen(*holder) - j);
		free(t1);
	}
	else
		tmp = ft_remainder(holder);
	return (tmp);
}

/* return a final line (with no '\n') and set ("empty") the holder to NULL */

char	*ft_remainder(char **holder)
{
	char	*tmp;
	char	*t1;

	tmp = ft_strdup(*holder, ft_strlen(*holder));
	t1 = *holder;
	*holder = NULL;
	free(t1);
	return (tmp);
}

/*  bonus part of this project requires keeping track of
	reading lines from different files, which is done by using
	a pointer to an array of pointers (e.i. file descriptors).
*/

char	*get_next_line(int fd)
{
	static char	*holder[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	holder[fd] = ft_read_buffer(fd, holder[fd]);
	if (!holder[fd])
		return (NULL);
	line = ft_return_line(&holder[fd]);
	return (line);
}
