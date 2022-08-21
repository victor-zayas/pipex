# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 19:17:31 by vzayas-s          #+#    #+#              #
#    Updated: 2022/08/21 20:40:58 by vzayas-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME #
NAME = pipex

# SRCS #
SRC = pipex.c 			\
	  libft/ft_split.c	\
	  libft/ft_strncmp.c\
	  libft/ft_substr.c \
	  libft/ft_strlen.c \
	  libft/ft_strjoin.c\

# INCLUDES #
INCLUDE = -I pipex.h

# OBJS #
OBJ = $(SRC:.c=.o)

# COMPILATION #
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
RM = /bin/rm -rf

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

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(INCLUDE)
	echo "$(BLUE)༺ library created༻$(END)"
	echo "$$PIPEX"

$(OBJ) : $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

all: $(NAME)

clean:
	$(RM) $(OBJ) $(BONUS_OBJS)
	echo "$(RED)༺ Objs deleted༻$(END)"

fclean: clean
	$(RM) $(NAME)
	echo "$(YELLOW)༺ Executable deleted༻$(END)"

re: fclean all

.PHONY: all clean fclean re bonus