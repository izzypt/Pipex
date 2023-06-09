/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:58:55 by smagalha          #+#    #+#             */
/*   Updated: 2023/05/31 15:47:00 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strjoin(char const *prefix, char const *suffix)
{
	size_t	len_prefix;
	size_t	len_suffix;
	char	*buffer;

	len_prefix = ft_strlen(prefix);
	len_suffix = ft_strlen(suffix);
	buffer = (char *)malloc(len_prefix + len_suffix + 1);
	if (!buffer)
		return (NULL);
	ft_memcpy(buffer, (const void *)prefix, len_prefix);
	ft_memcpy(&buffer[len_prefix], (const void *)suffix, len_suffix);
	buffer[len_prefix + len_suffix] = '\0';
	return ((char *)buffer);
}
