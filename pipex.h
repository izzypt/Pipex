/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:34:12 by simao             #+#    #+#             */
/*   Updated: 2023/05/31 20:51:07 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_list
{
	char			*path;
	char			*cmd;
	char			**full_cmd;
	int				fd[2];
	struct s_list	*nxt;
	struct s_list	*prv;
}				t_list;

typedef struct s_data
{
	int		pid;
	int		fd_input;
	int		fd_output;
	int		argc;
	t_list	*head;
	char	**paths;
}	t_data;

/* STRUCT UTILS */
t_list	*cmd_list(void);
t_data	*data(void);
/* COMMAND FUNCTIONS */
void	get_files_fd(int ac, char **av);
void	run_command(void);
void	parse_commands(char **argv);
/* PATH FUNCTIONS */
char	**get_path_list(char **env);
char	*valid_cmd_path(char *cmd);
/* MEMORY MANAGEMENT */
void	free_paths(char **paths);
/* UTIL FUNCTIONS */
char	**ft_split(const char *str, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *prefix, char const *suffix);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t elements, size_t bytes);
void	ft_bzero(void *s, size_t n);

#endif