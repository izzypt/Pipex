/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:34:12 by simao             #+#    #+#             */
/*   Updated: 2023/05/30 13:48:54 by simao            ###   ########.fr       */
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

typedef struct s_list
{
	char			*cmd;
	int				fd[2];
	char			*path;
	char			**av;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

typedef struct s_data
{
	int		pid;
	int		fd_in;
	int		fd_out;
	t_list	*head;
}	t_data;

/* PATH FUNCTIONS */
char	**get_path_list(char **env);
char	*access_path(char *cmd, char **paths);
/* MEMORY MANAGEMENT */
void	free_paths(char **paths);
/* UTIL FUNCTIONS */
char	**ft_split(const char *str, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *prefix, char const *suffix);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif