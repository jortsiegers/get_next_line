/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jsiegers <jsiegers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 17:45:57 by jsiegers      #+#    #+#                 */
/*   Updated: 2022/01/02 15:18:48 by jsiegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*set_remainder(char *remainder, char *buffer, int i_read)
{
	char		*tmp;

	if (i_read < 0)
		return (0);
	buffer[i_read] = '\0';
	if (remainder == 0 && i_read == 0)
		return (0);
	if (remainder == 0)
	{
		return (ft_strdup_util(buffer));
	}
	tmp = ft_strjoin_util(remainder, buffer);
	free(remainder);
	return (tmp);
}

char	*not_found(char **remainder, int i_read, int fd)
{
	char	*tmp;

	if (i_read < BUFFER_SIZE)
	{
		tmp = ft_strdup_util(*remainder);
		free(*remainder);
		*remainder = 0;
		return (tmp);
	}
	return (get_next_line(fd));
}

char	*reset_remainder(char *remainder, char *pos)
{
	char	*tmp;

	tmp = remainder;
	remainder = ft_strdup_util(pos + 1);
	free(tmp);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		buffer[BUFFER_SIZE + 1];
	int			i_read;
	char		*pos;
	char		*res;

	i_read = read(fd, buffer, BUFFER_SIZE);
	remainder = set_remainder(remainder, buffer, i_read);
	if (remainder == 0)
		return (0);
	pos = ft_strchr_util(remainder, '\n');
	if (pos == 0)
		return (not_found(&remainder, i_read, fd));
	res = malloc((pos - remainder + 1) * sizeof(char));
	if (res == 0)
		return (0);
	ft_strlcpy_util(res, remainder, (pos - remainder + 2));
	remainder = reset_remainder(remainder, pos);
	if (*remainder == 0)
	{
		free(remainder);
		remainder = 0;
	}
	return (res);
}

// int	main()
// {
// 	int fd;

// 	fd = open("test.txt", O_RDONLY);
// 	// free((void *)1);
// 	// buffer = malloc(sizeof(char) * BUFFER_SIZE);
// 	// characters_read = get_next_line(fd);
// 	// printf("Fd: %i\n", fd);
// 	printf("Res:%s\n", get_next_line(fd));
// 	printf("Res:%s\n", get_next_line(fd));
// 	printf("Res:%s\n", get_next_line(fd));
// 	printf("Res:%s\n", get_next_line(fd));
// 	printf("Res:%s\n", get_next_line(fd));
// 	printf("Res:%s\n", get_next_line(fd));
// 	printf("Res:%s\n", get_next_line(fd));
// 	printf("Res:%s\n", get_next_line(fd));
// 	// get_next_line(fd);
// 	// get_next_line(fd);

// }
