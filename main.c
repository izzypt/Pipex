/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:04:07 by simao             #+#    #+#             */
/*   Updated: 2023/05/31 16:28:50 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_files(int ac, char **av)
{
	int		fd[2];

	(data())->fd_input = open(av[1], O_RDONLY);
	if (data()->fd_input == -1)
	{
		perror(av[1]);
		pipe(fd);
		(data())->fd_input = fd[0];
		close(fd[1]);
	}
	(data())->fd_output = open(av[ac - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (data()->fd_output == -1)
	{
		perror("");
		exit(0);
	}
}

int	main(int argc, char **argv, char **env)
{

	data()->paths = get_path_list(env);
	if (path_acessible(argv[2], data()->paths))
		run_command();
	free_paths(data()->paths);
	return (0);
}

/*

1 - Get all the paths from **env (PATH variable) and save it to data()->paths.
2 - After that we will check if the path and the given command exist and if we have permission.

*/

//printf("Valor de acesso: %d\n", access("/usr/bin/ls", X_OK));

	/*init_pipex();
	check_args();
	parse_cmds();
	ft_parse_args();
	while (cmds)
		ft_exec();
	ft_cleanup();*/