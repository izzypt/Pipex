/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:54:20 by simao             #+#    #+#             */
/*   Updated: 2023/05/30 13:48:59 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path_list(char **env)
{
	int		i;
	char	**paths;

	i = -1;
	paths = NULL;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			paths = ft_split(env[i] + 5, ':');
			return (paths);
		}
	}
	perror("PATH not found");
	i = -1;
	if (paths)
	{
		while (paths[++i])
			free(paths[i]);
	}
	free(paths);
	exit(0);
}

char	*access_path(char *cmd, char **paths)
{
	int		i;
	char	**splitted_cmd;
	char	*path_command;
	char	*temp;

	i = -1;
	splitted_cmd = ft_split(cmd, ' ');
	while (paths[++i])
	{
		temp = ft_strjoin(paths[i], "/");
		path_command = ft_strjoin(temp, splitted_cmd[0]);
		if (!access(path_command, X_OK))
		{
			free(temp);
			return (path_command);
		}
		free(path_command);
		free(temp);
	}
	free(splitted_cmd);
	return (NULL);
}
