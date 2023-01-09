/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:52:47 by oait-bad          #+#    #+#             */
/*   Updated: 2023/01/07 16:31:53 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_first_cmd(int *fd, char **argv, char **envp)
{
	int		exe;
	char	**cmd;

	cmd = ft_split(argv[3], ' ');
	close(fd[0]);
	dup2(fd[1], 1);
	exe = execve(path_finder(envp, *cmd), cmd, envp);
	if (exe == -1)
		command_not_found(cmd[0]);
}

void	exec_second_cmd(int *fd, char **argv, char **envp)
{
	int		ffd;
	int		exe;
	char	**cmd;

	ffd = open(argv[5], O_RDWR | O_CREAT | O_APPEND, 0644);
	cmd = ft_split(argv[4], ' ');
	close(fd[1]);
	dup2(fd[0], 0);
	dup2(ffd, 1);
	close(ffd);
	exe = execve(path_finder(envp, *cmd), cmd, envp);
	if (exe == -1)
		command_not_found(cmd[0]);
}

void	close_and_wait(int *pid, int *fd)
{
	close(fd[0]);
	close(fd[1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	if (WIFEXITED(pid))
		exit(WEXITSTATUS(pid));
}

void	command_not_found(char *cmd)
{
	char	*msg;

	msg = ft_strjoin(cmd, " : command not found\n");
	ft_putstr_fd(msg, 2);
	free(msg);
	exit(127);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid[2];

	if (argc != 6)
		error("Error: invalid number of arguments\n");
	else if (ft_strcmp(argv[1], "here_doc") == 0)
		ft_here_doc(argv);
	else
	{
		perror("Error: invalid command");
		exit(1);
	}
	pipe(fd);
	pid[0] = fork();
	if (pid[0] == -1)
		perror("Error 1");
	else if (pid[0] == 0)
		exec_first_cmd(fd, argv, envp);
	pid[1] = fork();
	if (pid[1] == -1)
		perror("Error 2");
	else if (pid[1] == 0)
		exec_second_cmd(fd, argv, envp);
	else
		close_and_wait(pid, fd);
}
