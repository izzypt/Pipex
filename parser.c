/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:30:31 by simao             #+#    #+#             */
/*   Updated: 2023/06/11 13:21:52 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_commands(char **argv)
{
	int		i;
	t_list	*curr;
	t_list	*tmp;
	char	**splitted_cmd;

	i = 2;
	curr = cmd_list();
	tmp = NULL;
	while (argv[i])
	{
		splitted_cmd = ft_split(argv[i], ' ');
		curr->cmd = splitted_cmd[0];
		curr->full_cmd = splitted_cmd;
		curr->path = valid_cmd_path(argv[i]);
		if (argv[i + 2])
		{
			curr->nxt = malloc(sizeof(t_list));
			curr->prv = tmp;
			tmp = curr;
			curr = curr->nxt;
		}
		i++;
	}
}
