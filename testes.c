/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:15:09 by simao             #+#    #+#             */
/*   Updated: 2023/06/11 17:06:22 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <stdlib.h>
#include  <stdio.h>

/* This file holds small programs to test small units of code.*/

/* Just uncomment the main that holds the test you want to run */

/*

- The program below get the environment variable path and prints it
- Example of getenv() function:

int	main(void)
{
   char	*pathvar;

	pathvar = getenv("PATH");
	printf("%s", pathvar);
}

*/

/*
int	main(int argc, char **argv, char **env)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		printf("%s\n", argv[i]);
		i++;
	}
}
*/

/*

- Test redirecting input

int main(int argc, char **argv, char **env)
{
	
}

*/

#include <stdio.h>
#include <stdlib.h>

int main () {
   printf("PATH : %s\n", getenv("PATH"));
   printf("HOME : %s\n", getenv("HOME"));
   printf("ROOT : %s\n", getenv("ROOT"));

   return(0);
}