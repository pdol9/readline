/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 01:43:27 by pdolinar          #+#    #+#             */
/*   Updated: 2022/04/06 20:48:32 by pdolinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

/* libft functions */
void	ft_bzero(void *s, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s, size_t len);
char	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *str);

/* get_next_line functions */
char	*get_next_line(int fd);
char	*ft_return_line(char **holder);
char	*ft_remainder(char **holder);
char	*ft_read_buffer(int fd, char *holder);
size_t	ft_check_for_nl(const char *str, int c);

#endif
