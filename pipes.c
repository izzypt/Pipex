/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:38:10 by simao             #+#    #+#             */
/*   Updated: 2023/06/11 15:26:46 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_cmd(t_list *cmd, char *file, int in_or_out)
{
	int	pipe_fd[2];
	int	pid1;
	int	pid2;
	int	file_fd;

	if (file && in_or_out == 0)
		file_fd = open(file, O_RDONLY, 0644);
	if (file && in_or_out == 1)
		file_fd = open(file, O_WRONLY | O_CREAT, 0644);
	if (pipe(pipe_fd) == -1)
		printf("Error on pipe()");
	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(file_fd, STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		execve(cmd->path, cmd->full_cmd, NULL);
		close(file_fd);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);
	}
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
