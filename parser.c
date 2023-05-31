/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:30:31 by simao             #+#    #+#             */
/*   Updated: 2023/05/31 20:53:36 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_commands(char **argv)
{
	int		i;
	t_list	*curr;
	char	**splitted_cmd;

	i = 2;
	curr = cmd_list();
	while (argv[i])
	{
		splitted_cmd = ft_split(argv[i], ' ');
		curr->cmd = splitted_cmd[0];
		curr->full_cmd = splitted_cmd;
		curr->path = valid_cmd_path(argv[i]);
		curr->nxt = malloc(sizeof(t_list));
		curr = curr->nxt;
		i++;
	}
}
