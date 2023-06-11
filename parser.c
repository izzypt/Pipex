/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:30:31 by simao             #+#    #+#             */
/*   Updated: 2023/06/11 18:26:26 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_commands(char **argv)
{
	int		i;
	t_list	*curr;
	t_list	*tmp;
	char	**splitted_cmd;

	i = 1;
	curr = cmd_list();
	tmp = NULL;
	while (argv[i])
	{
		splitted_cmd = ft_split(argv[i], ' ');
		if (valid_cmd_path(splitted_cmd[0]))
		{
			curr->path = valid_cmd_path(splitted_cmd[0]);
			if (access(curr->path, X_OK) == 0)
			{
				curr->cmd = splitted_cmd[0];
				curr->full_cmd = splitted_cmd;
				if (argv[i + 1] && valid_cmd_path(argv[i + 1]))
					curr->nxt = malloc(sizeof(t_list));
				curr->prv = tmp;
				tmp = curr;
				curr = curr->nxt;
			}	
		}
		i++;
	}
}
