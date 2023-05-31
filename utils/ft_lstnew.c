/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:36:52 by simao             #+#    #+#             */
/*   Updated: 2023/05/31 15:38:06 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

t_list	*ft_lstnew(char *cmd, char *path)
{
	t_list	*new;

	new = (t_list *)ft_calloc(sizeof(t_list), 1);
	if (!new)
		return (NULL);
	new->full_cmd = ft_split(cmd, ' ');
	new->cmd = new->full_cmd[0];
	if (pipe(new->fd) == -1)
		perror("");
	new->path = path;
	return (new);
}