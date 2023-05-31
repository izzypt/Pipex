/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:38:10 by simao             #+#    #+#             */
/*   Updated: 2023/05/31 21:47:52 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_command(void)
{
	int	fd[2];
	int	pid1;
	int	infile;

	infile = open("teste.txt", O_RDONLY | O_CREAT, 0644);
	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(infile, STDIN_FILENO);
		//close(fd[0]);
		//close(fd[1]);
		execve(cmd_list()->path, cmd_list()->full_cmd, NULL);
	}
	close(infile);
	waitpid(pid1, NULL, 0);
}
