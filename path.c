/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:54:20 by simao             #+#    #+#             */
/*   Updated: 2023/05/31 21:49:04 by simao            ###   ########.fr       */
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
			data()->paths = paths;
			return (paths);
		}
	}
	perror("PATH not found");
	exit(0);
}

char	*valid_cmd_path(char *cmd)
{
	char	*command_path;
	char	*temp;
	char	**splitted_cmd;
	char	**paths;

	paths = data()->paths;
	splitted_cmd = ft_split(cmd, ' ');
	while (paths++)
	{
		temp = ft_strjoin(*paths, "/");
		command_path = ft_strjoin(temp, splitted_cmd[0]);
		if (!access(command_path, X_OK))
		{
			free(temp);
			return (command_path);
		}
		free(command_path);
		free(temp);
	}
	perror("Command not found\n");
	free(splitted_cmd);
	exit(0);
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
