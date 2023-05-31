/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:38:10 by simao             #+#    #+#             */
/*   Updated: 2023/05/31 14:58:41 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_command(void)
{
	int	fd[2];
	int	pid1;

	if (pipe(fd) == -1)
		printf("Error on pipe()");
	pid1 = fork();
	if (pid1 == 0)
	{
		/*dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);*/
		execve(cmds_lst()->path, cmds_lst()->full_cmd, NULL);
	}
	waitpid(pid1, NULL, 0);
}
