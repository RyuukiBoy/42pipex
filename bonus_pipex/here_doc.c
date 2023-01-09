/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:12:41 by oait-bad          #+#    #+#             */
/*   Updated: 2023/01/08 16:34:02 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	read_here_doc(int *fd, char *limiter)
{
	char	*line;
	char	*new_limiter;

	line = "";
	while (1)
	{
		ft_putstr_fd("here_doc> ", 1);
		line = get_next_line(0);
		new_limiter = ft_strjoin(limiter, "\n");
		if (ft_strcmp(new_limiter, line) == 0)
			exit(0);
		write(fd[1], line, ft_strlen(line));
	}
	free (line);
	exit(0);
}

void	ft_here_doc(char **argv)
{
	int	fd[2];
	int	pid;

	pipe(fd);
	pid = fork();
	if (pid == -1)
		perror("Error ");
	if (pid == 0)
	{
		close(fd[0]);
		read_here_doc(fd, argv[2]);
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		waitpid(pid, NULL, 0);
	}
}
