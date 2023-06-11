/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:38:10 by simao             #+#    #+#             */
/*   Updated: 2023/06/11 20:25:44 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_output_to_file(t_list *cmd, char *file, int in_or_out)
{
	int	pipe_fd[2];
	int	pid1;
	int	pid2;
	int	file_fd;
	int	outfile;

	outfile = open(file, O_WRONLY | O_CREAT, 0644);
	if (pipe(pipe_fd) == -1)
		printf("Error on pipe()");
	pid1 = fork();
	if (pid1 == 0)
	{
		//dup2(file_fd, STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		execve(cmd->path, cmd->full_cmd, NULL);
		//close(file_fd);
	}
	/*pid2 = fork();
	if (pid2 == 0)
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		close(outfile);
	}*/
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(outfile);
	waitpid(pid1, NULL, 0);
}

void	cmd_input_from_file(t_list *cmd, char *file, int in_or_out)
{
	int	pipe_fd[2];
	int	pid1;
	int	pid2;
	int	file_fd;
	int	infile;

	infile = open(file, O_RDONLY, 0644);
	if (pipe(pipe_fd) == -1)
		printf("Error on pipe()");
	pid1 = fork();
	if (pid1 == 0)
	{
		//dup2(file_fd, STDIN_FILENO);
		dup2(infile, STDIN_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		execve(cmd->path, cmd->full_cmd, NULL);
		//close(file_fd);
	}
	/*pid2 = fork();
	if (pid2 == 0)
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		close(outfile);
	}*/
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(infile);
	waitpid(pid1, NULL, 0);
}
