/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jsiegers <jsiegers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 17:45:59 by jsiegers      #+#    #+#                 */
/*   Updated: 2022/01/02 15:18:12 by jsiegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char				*ft_strdup_util(char *src);
char				*get_next_line(int fd);
unsigned int		ft_strlcpy_util(char *dest, char *src, unsigned int size);
char				*ft_strchr_util(char *s, int c);
char				*ft_strjoin_util(char const *s1, char const *s2);
int					ft_strlen_util(char *str);

#endif
