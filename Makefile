# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: simao <simao@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 17:27:36 by esali             #+#    #+#              #
#    Updated: 2023/06/11 19:42:32 by simao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =		pipex

SRCS =		main.c free.c parser.c path.c  pipes.c utils/*.c

all :		$(NAME)

$(NAME) :	$(SRCS)
			gcc  $(SRCS) -o $(NAME)

clean:
			rm $(NAME)

fclean:
			make clean && make

re: 		fclean all