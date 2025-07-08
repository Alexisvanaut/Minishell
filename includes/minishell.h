/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvanaut < alvanaut@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:50:21 by alvanaut          #+#    #+#             */
/*   Updated: 2025/07/05 13:59:30 by alvanaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// Fonctions readline
# include <readline/history.h>
# include <readline/readline.h>

// Fonctions standard d'entrée/sortie
# include <stdio.h>  // printf, perror
# include <stdlib.h> // malloc, free, exit, getenv
# include <string.h> // strerror
# include <unistd.h> // write, access, read, close, fork, execve, dup, dup2,

// Gestion des processus
# include <sys/types.h> // wait, waitpid, wait3, wait4, opendir
# include <sys/wait.h>  // wait, waitpid, wait3, wait4

// Gestion des signaux
# include <signal.h> // signal, sigaction, sigemptyset, sigaddset, kill

// Fonctions liées au répertoire et fichiers
# include <dirent.h>   // opendir, readdir, closedir
# include <errno.h>    // errno,
# include <fcntl.h>    // open, O_* flags
# include <sys/stat.h> // stat, lstat, fstat

// Terminal et gestion des attributs
# include <curses.h>  // tgetent
# include <term.h>    // tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
# include <termios.h> // tcsetattr, tcgetattr

// libft
# include "../libft/libft.h"

typedef struct s_command
{
	char				**args;
	char				*infile;
	char				*outfile;
	int					append;
	int					heredoc;
	struct s_command	*next;
}						t_command;

typedef struct s_token
{
	char				**av;
}						t_tokens;

#endif
