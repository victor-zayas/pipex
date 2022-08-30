# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 19:17:31 by vzayas-s          #+#    #+#              #
#    Updated: 2022/08/30 16:37:06 by vzayas-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME #
NAME = pipex

# COMPILATION #
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address
RM = /bin/rm -rf

# OBJS #
OBJS = $(SRCS:.c=.o)
B_OBJ = $(BONUS:.c=.o)

# INCLUDES #
INCLUDE = -I pipex.h

# SRCS #
SRCS = pipex.c 				\
	   utils.c				\
	   libft/ft_split.c		\
	   libft/ft_strncmp.c	\
	   libft/ft_substr.c 	\
	   libft/ft_strlen.c 	\
	   libft/ft_strjoin.c	\
	   libft/ft_putendl_fd.c\
	   libft/ft_putstr_fd.c \

BONUS = bonus.c					\
		utils.c					\
	    libft/ft_split.c		\
	    libft/ft_strncmp.c		\
	    libft/ft_substr.c 		\
	    libft/ft_strlen.c 		\
	    libft/ft_strjoin.c		\
	    libft/ft_putendl_fd.c	\
	    libft/ft_putstr_fd.c 	\


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

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDE)
	echo "$(BLUE)༺ library created༻$(END)"
	echo "$$PIPEX"

bonus: $(B_OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(B_OBJ) $(INCLUDE)
	   echo "$(GREEN)༺ Bonus compiled༻$(END)"
	   echo "$$PIPEX"

clean:
	$(RM) $(OBJ) $(B_OBJ) *.o a.out outfile
	echo "$(RED)༺ Objs deleted༻$(END)"

fclean: clean
	$(RM) $(NAME)
	echo "$(YELLOW)༺ Executable deleted༻$(END)"

re: fclean all

.PHONY: all clean fclean re