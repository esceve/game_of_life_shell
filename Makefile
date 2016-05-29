##
## Makefile for Generic Makefile in /home/esceve/Documents/C/informations
## 
## Made by Clement Scherpereel
## Login esceve <clement.scherpereel@outlook.fr>
## 
## Started on  Thu May 12 23:11:11 2016 Clement Scherpereel
## Last update Sat May 28 11:01:58 2016 Clement Scherpereel
##

# Variable de Debug pour ajouter des flags (pour debugger)
DEBUG			= 0

# Programme de compilation
CC			= gcc

# Programme de suppression
RM			= rm -f

# Flags de compilation
CFLAGS			+= -W -Wall -Wextra
CFLAGS			+= -I./includes/

# Condition pour ajouter des flags de compilation pour le debug
ifeq ($(DEBUG), 1)
	CFLAGS		+= -g3 -D _DEBUG
endif

# Flags de linkage
LDFLAGS			+= -L./libraries/

# Binary name
NAME			=game_of_life.x86_64

# Chemin des fichiers source
SRCS			= ./srcs/game_of_life.c					\

# Compilation des sources en assembleur non linked
OBJS			= $(SRCS:.c=.o)

# Regle principale (appellée en tapant `Make`)
all:			$(NAME)

# Regle de compilation du binaire:
# 1. Passage de C à Assembleur
# 2. Linking de l'Assembleur avec les libs
$(NAME):		$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

# Regle pour supprimer les .o (Assembleur)
clean:
			$(RM) $(OBJS)

# Regle pour supprimer le binaire et les .o (Assembleur)
fclean:			clean
			$(RM) $(NAME)

# Regle pour refaire le binaire
# 1. Suppression de la derniere compilation
# 2. Compilation du binaire
re:			fclean all

# Declaration des regles pour qu'elles soient reconnues
.PHONY:			all clean fclean re
