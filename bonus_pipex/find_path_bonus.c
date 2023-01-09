/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:38:44 by oait-bad          #+#    #+#             */
/*   Updated: 2023/01/08 16:32:13 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_env(char **envp)
{
	int		i;
	char	**save;

	i = 0;
	save = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			save = ft_split(envp[i] + 5, ':');
			return (save);
		}
		i++;
	}
	return (NULL);
}

char	*path_join(char **path)
{
	char	*tmp;
	int		i;

	i = 0;
	while (path && path[i])
	{
		tmp = path[i];
		path[i] = ft_strjoin(tmp, "/");
		free(tmp);
		if (!path[i])
			perror("Error ");
		i++;
	}
	return (NULL);
}

char	*path_finder(char **envp, char *command)
{
	int		i;
	char	**path;
	char	*cmd;

	i = 0;
	path = get_env(envp);
	if (access(command, X_OK) != -1)
		return (ft_strdup(command));
	path_join(path);
	i = 0;
	while (path && path[i])
	{
		cmd = ft_strjoin(path[i++], command);
		if (!access(cmd, X_OK))
			return (cmd);
		free(cmd);
	}
	free_split(path);
	return (NULL);
}
