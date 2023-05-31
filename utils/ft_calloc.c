/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:21:01 by smagalha          #+#    #+#             */
/*   Updated: 2023/05/31 15:39:58 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	*ft_calloc(size_t elements, size_t bytes)
{
	void	*ptr;

	ptr = malloc(elements * bytes);
	if (!ptr)
		return (NULL);
	else
		ft_bzero(ptr, (elements * bytes));
	return (ptr);
}
