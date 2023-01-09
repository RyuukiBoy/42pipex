/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 03:48:56 by oait-bad          #+#    #+#             */
/*   Updated: 2023/01/07 17:15:37 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	free_split(char **split);
size_t	ft_strlen(const char *str);
char	*path_finder(char **envp, char *command);
void	exec_first_cmd(int *fd, char **argv, char **envp);
void	exec_second_cmd(int *fd, char **argv, char **envp);
char	*ft_strdup(const char *s1);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	ft_putstr_fd(char *s, int fd);
char	**get_env(char **envp);
char	*path_join(char **path);
void	command_not_found(char *cmd);
void	error(char *str);

#endif