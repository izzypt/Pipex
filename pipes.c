/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:38:10 by simao             #+#    #+#             */
/*   Updated: 2023/06/12 18:02:29 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
- Will output cmd1 to the write end of the pipe.
- Input of cmd2 will come from the read end of the pipe.
*/
void	cmd_pipe(t_list *cmd1, t_list *cmd2)
{
	int	pipe_fd[2];
	int	pid1;
	int	pid2;

	pipe(pipe_fd);
	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		execve(cmd1->path, cmd1->full_cmd, NULL);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		execve(cmd2->path, cmd2->full_cmd, NULL);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

/*
- Will output the cmd to the file contents.
*/
void	cmd_output_to_file(t_list *cmd, char *file)
{
	int	pipe_fd[2];
	int	pid1;
	int	outfile;

	outfile = open(file, O_WRONLY | O_CREAT, 0644);
	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(outfile, STDOUT_FILENO);
		execve(cmd->path, cmd->full_cmd, NULL);
	}
	close(outfile);
	waitpid(pid1, NULL, 0);
}

/*
- Input for the cmd will be received from the file contents.
*/
void	cmd_input_from_file(t_list *cmd, char *file)
{
	int	pipe_fd[2];
	int	pid1;
	int	infile;

	pipe(pipe_fd);
	infile = open(file, O_RDONLY, 0644);
	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(infile, STDIN_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		execve(cmd->path, cmd->full_cmd, NULL);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(infile);
	waitpid(pid1, NULL, 0);
}
