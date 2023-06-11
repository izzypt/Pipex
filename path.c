/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:54:20 by simao             #+#    #+#             */
/*   Updated: 2023/06/11 20:37:26 by simao            ###   ########.fr       */
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

void	get_files_fd(int ac, char **argv)
{
	int		fd[2];

	/*(data())->fd_input = open(argv[1], O_RDONLY);
	if (data()->fd_input == -1)
	{
		perror(argv[1]);
		pipe(fd);
		(data())->fd_input = fd[0];
		close(fd[1]);
	}
	(data())->fd_output = open(argv[ac - 1], O_WRONLY | \
	O_TRUNC | O_CREAT, 0644);
	if (data()->fd_output == -1)
	{
		perror("");
		exit(0);
	}*/
}
