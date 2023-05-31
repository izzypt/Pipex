/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:04:07 by simao             #+#    #+#             */
/*   Updated: 2023/05/31 11:07:06 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, const char **argv, char **env)
{
	int		i;
	int		j;
	char	**paths;
	char *args[] = {"ls", "-l", NULL};
	char *envs[] = {NULL};

	i = 0;
	j = 0;
	paths = get_path_list(env);
	printf("Valor de acesso: %d\n", access("/usr/bin/pwdd", X_OK));
	//execve("/usr/bin/ls", args, envs);
	free_paths(paths);
	return (0);
}
