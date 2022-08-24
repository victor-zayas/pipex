# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 19:17:31 by vzayas-s          #+#    #+#              #
#    Updated: 2022/08/24 15:19:28 by vzayas-s         ###   ########.fr        #
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

# OBJS #
DIR_OBJS = objs/
OBJS = $(SRCS:.c=.o)
PREFIXED = $(addprefix $(DIR_OBJS), $(OBJS))

# SRCS #
SRCS = pipex.c 					\
	  src/libft/ft_split.c		\
	  src/libft/ft_strncmp.c	\
	  src/libft/ft_substr.c 	\
	  src/libft/ft_strlen.c 	\
	  src/libft/ft_strjoin.c

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

$(NAME) : $(PREFIXED)
	$(CC) $(CFLAGS) -o $(NAME) $(PREFIXED)
	echo "$(BLUE)༺ library created༻$(END)"
	echo "$$PIPEX"

$(DIR_OBJS)%.o : %.c $(INCLUDE)
	mkdir -p $(DIR_OBJS)/srcs/libft
	$(CC) $(CFLAGS) -c $< -o $@
	echo "$(MAG)༺ OBJS folder created༻$(END)"

all: $(NAME)

clean:
	$(RM) $(OBJ) $(DIR_OBJS) *.o a.out
	echo "$(RED)༺ Objs deleted༻$(END)"

fclean: clean
	$(RM) $(NAME)
	echo "$(YELLOW)༺ Executable deleted༻$(END)"

re: fclean all

.PHONY: all clean fclean re