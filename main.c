/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:04:07 by simao             #+#    #+#             */
/*   Updated: 2023/05/31 20:54:31 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	get_path_list(env);
	parse_commands(argv);
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