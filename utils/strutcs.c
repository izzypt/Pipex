/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutcs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:25:38 by simao             #+#    #+#             */
/*   Updated: 2023/05/31 15:22:20 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

t_list	*cmds_lst(void)
{
	static t_list	list;

	return (&list);
}

t_data	*data(void)
{
	static t_data	dados;

	dados.head = cmds_lst();

	return (&dados);
}
