/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:04:07 by simao             #+#    #+#             */
/*   Updated: 2023/06/11 18:37:10 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_list	*curr;

	curr = cmd_list();
	get_path_list(env);
	if (argc > 2)
		valid_cmd_path(argv[1]);
	parse_commands(argv);
	while (curr != NULL)
	{
		printf("curr command: %s\n", curr->cmd);
		run_cmd(curr, argv[2], 0);
		curr = curr->nxt;
	}
	
	free_paths(data()->paths);
	return (0);
}