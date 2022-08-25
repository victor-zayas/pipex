# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 19:17:31 by vzayas-s          #+#    #+#              #
#    Updated: 2022/08/25 12:31:19 by vzayas-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME #
NAME = pipex

# COMPILATION #
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address
RM = /bin/rm -rf

# INCLUDES #
INCLUDE = -I pipex.h

# SRCS #
SRCS = src/pipex.c 				\
	   src/utils.c				\
	   src/libft/ft_split.c		\
	   src/libft/ft_strncmp.c	\
	   src/libft/ft_substr.c 	\
	   src/libft/ft_strlen.c 	\
	   src/libft/ft_strjoin.c	\
	   src/libft/ft_putendl_fd.c\
	   src/libft/ft_putstr_fd.c \

# OBJS #
OBJS = *.o #$(SRCS:.c=.o)

# MAKEFILE ART #
# COLORS #
BLACK=\033[0;30m
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
MAG=\033[0;35m
CYAN=\033[0;36m
WHITE=\033[0;37m
END=\033[0m

define PIPEX

$(WHITE)╔╦╗$(RED)╦ ╦ $(YELLOW)╔═╗ $(GREEN)╔═╗ $(CYAN)╦ $(BLUE)╔═╗ $(MAG)╔═╗ $(WHITE)╔═╗
$(WHITE) ║ $(RED)╠═╣ $(YELLOW)║╣  $(GREEN)╠═╝ $(CYAN)║ $(BLUE)╠═╝ $(MAG)║╣  $(WHITE)╚═╗
$(WHITE) ╩ $(RED)╩ ╩ $(YELLOW)╚═╝ $(GREEN)╩   $(CYAN)╩ $(BLUE)╩   $(MAG)╚═╝ $(WHITE)╚═╝$(END)

endef
export PIPEX

# RULES #

.SILENT:

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDE)
	echo "$(BLUE)༺ library created༻$(END)"
	echo "$$PIPEX"

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

all: $(NAME)

clean:
	$(RM) $(OBJ) $(DIR_OBJS) *.o a.out outfile
	echo "$(RED)༺ Objs deleted༻$(END)"

fclean: clean
	$(RM) $(NAME)
	echo "$(YELLOW)༺ Executable deleted༻$(END)"

re: fclean all

.PHONY: all clean fclean re