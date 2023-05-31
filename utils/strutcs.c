/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutcs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:25:38 by simao             #+#    #+#             */
/*   Updated: 2023/05/31 20:52:16 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

t_list	*cmd_list(void)
{
	static t_list	list;

	return (&list);
}

t_data	*data(void)
{
	static t_data	dados;

	dados.head = cmd_list();

	return (&dados);
}
