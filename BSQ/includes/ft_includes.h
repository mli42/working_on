/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_includes.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:09:41 by mli               #+#    #+#             */
/*   Updated: 2019/10/03 12:16:40 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INCLUDES_H
# define FT_INCLUDES_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include <stdio.h>

int		ft_first_line(int fd, char *content, int size, char fills[4]);
int		ft_map_len(int fd, char content, char fills[4]);

void	ft_print_map(char **map, int size, int len);
char	**ft_create_map_and_fill(int fd, int size, int len, char content);
int		ft_is_map_ok(int fd, int fd1);

void	ft_bsq(char **map, char fills[4]);

#endif
