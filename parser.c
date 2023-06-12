/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:30:31 by simao             #+#    #+#             */
/*   Updated: 2023/06/12 01:36:02 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	commands_left(int index, int argc, char **argv)
{
	char	**splitted_cmd;

	while (index < argc)
	{
		splitted_cmd = ft_split(argv[index], ' ');
		if (valid_cmd_path(splitted_cmd[0]))
		{
			free(splitted_cmd);
			return (1);
		}
		free(splitted_cmd);
		index++;
	}
	return (0);
}

void	parse_commands(int argc, char **argv)
{
	int		i;
	t_list	*curr;
	char	**splitted_cmd;

	i = 1;
	curr = cmd_list();
	while (argv[i])
	{
		splitted_cmd = ft_split(argv[i], ' ');
		if (valid_cmd_path(splitted_cmd[0]))
		{
			curr->path = valid_cmd_path(splitted_cmd[0]);
			if (access(curr->path, X_OK) == 0)
			{
				if (commands_left(i + 1, argc, argv))
					curr->nxt = malloc(sizeof(t_list));
				curr->cmd = splitted_cmd[0];
				curr->full_cmd = splitted_cmd;
				curr = curr->nxt;
			}	
		}
		else
			free(splitted_cmd);
		i++;
	}
}
