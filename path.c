/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:54:20 by simao             #+#    #+#             */
/*   Updated: 2023/06/12 11:58:44 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
- Finds the PATH environment variable and splits all the paths by ":".
- Saves those paths in the data struct.
*/
char	**get_path_list(char **env)
{
	char	**paths;
	int		i;

	i = 0;
	paths = ft_split(getenv("PATH"), ':');
	data()->paths = paths;
	return (paths);
}

/*
- Creates the path of a command by appending the "/" and the command name.
- Checks if we have permissions to execte the command accessing the command path.
- It returns the valid command path.
*/
char	*valid_cmd_path(char *cmd)
{
	char	*command_path;
	char	*temp;
	char	**splitted_cmd;
	char	**paths;
	int		i;

	i = 0;
	while (data()->paths[i] != NULL)
	{
		temp = ft_strjoin(data()->paths[i], "/");
		command_path = ft_strjoin(temp, cmd);
		if (!access(command_path, X_OK))
		{
			free(temp);
			return (command_path);
		}
		free(command_path);
		free(temp);
		i++;
	}
	return (NULL);
}
