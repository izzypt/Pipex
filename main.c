/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:04:07 by simao             #+#    #+#             */
/*   Updated: 2023/06/11 20:29:00 by simao            ###   ########.fr       */
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
		if (!ft_strncmp(argv[2], ">", 1))
			cmd_output_to_file(curr, argv[3], 1);
		if (!ft_strncmp(argv[2], "<", 1))
			cmd_input_from_file(curr, argv[1], 1);
		curr = curr->nxt;
	}
	free_paths(data()->paths);
	return (0);
}
