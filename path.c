/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:54:20 by simao             #+#    #+#             */
/*   Updated: 2023/05/31 15:46:35 by simao            ###   ########.fr       */
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

int	path_acessible(char *cmd, char **paths)
{
	int		i;
	char	**splitted_cmd;
	char	*command_path;
	char	*temp;

	i = -1;
	splitted_cmd = ft_split(cmd, ' ');
	while (paths[++i])
	{
		temp = ft_strjoin(paths[i], "/");
		command_path = ft_strjoin(temp, splitted_cmd[0]);
		if (!access(command_path, X_OK))
		{
			free(temp);
			return (1);
		}
		free(command_path);
		free(temp);
	}
	perror("Command not found\n");
	free(splitted_cmd);
	exit(0);
}
