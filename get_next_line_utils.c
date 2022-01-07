/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jsiegers <jsiegers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 17:45:54 by jsiegers      #+#    #+#                 */
/*   Updated: 2022/01/02 15:17:50 by jsiegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_util(char const *s1, char const *s2)
{
	int		l1;
	int		l2;
	char	*res;
	int		i;

	if (!s1 || !s2)
		return (0);
	l1 = ft_strlen_util((char *)s1);
	l2 = ft_strlen_util((char *)s2);
	res = malloc(l1 + l2 + 1);
	if (res == 0)
		return (0);
	i = 0;
	while (i < l1)
	{
		res[i] = (char)s1[i];
		i++;
	}
	i = -1;
	while (++i < l2)
		res[l1 + i] = (char)s2[i];
	res[l1 + i] = 0;
	return (res);
}

char	*ft_strdup_util(char *src)
{
	int		len;
	char	*mem;
	int		c;

	len = ft_strlen_util(src);
	mem = malloc(sizeof(char) * (len + 1));
	if (mem == 0)
		return (0);
	c = 0;
	while (c < len)
	{
		mem[c] = src[c];
		c++;
	}
	mem[c] = '\0';
	return (mem);
}

char	*ft_strchr_util(char *s, int c)
{
	while (*s != c && *s)
		s++;
	if (*s == c)
		return (s);
	return (0);
}

unsigned int	ft_strlcpy_util(char *dest, char *src, unsigned int size)
{
	unsigned int	c;

	c = 0;
	if (size == 0)
		return (ft_strlen_util(src));
	while (c < size - 1 && src[c] != '\0')
	{
		dest[c] = src[c];
		c++;
	}
	if (c < size)
		dest[c] = '\0';
	return (ft_strlen_util(src));
}

int	ft_strlen_util(char *str)
{
	int	c;

	c = 0;
	while (*str)
	{
		str += 1;
		c++;
	}
	return (c);
}
