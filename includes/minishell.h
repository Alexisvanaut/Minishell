/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvanaut <alvanaut@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:19:58 by alvanaut          #+#    #+#             */
/*   Updated: 2025/07/19 19:20:09 by alvanaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>
# include <dirent.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

/* Variable globale pour les signaux/
extern int	g_signal_received;

/* Types de tokens */
typedef enum e_token_type
{
	TOKEN_WORD,			// Mot/commande/argument
	TOKEN_PIPE,			// |
	TOKEN_REDIR_IN,		// <
	TOKEN_REDIR_OUT,	// >
	TOKEN_REDIR_APPEND,	// >>
	TOKEN_REDIR_HEREDOC,// <<
	TOKEN_EOF			// Fin de ligne
}	t_token_type;

/* Types de redirections */
typedef enum e_redirect_type
{
	REDIR_IN,			// <
	REDIR_OUT,			// >
	REDIR_APPEND,		// >>
	REDIR_HEREDOC		// <<
}	t_redirect_type;

/* Structure pour un token */
typedef struct s_token
{
	t_token_type		type;		// Type du token
	char				*value;		// Contenu du token
	struct s_token		*next;		// Token suivant
}	t_token;

/* Structure pour une redirection */
typedef struct s_redirect
{
	t_redirect_type		type;		// Type de redirection
	char				*filename;	// Nom du fichier (pour <, >, >>)
	char				*delimiter;	// Délimiteur (pour <<)
	struct s_redirect	*next;		// Redirection suivante
}	t_redirect;

/* Structure pour une commande */
typedef struct s_command
{
	char				**args;		// Tableau d'arguments (args[0] = commande)
	t_redirect			*redirects;	// Liste des redirections
	struct s_command	*next;		// Commande suivante (pour les pipes)
}	t_command;

/* Structure principale pour le shell */
typedef struct s_minishell
{
	char				**env;		// Copie de l'environnement
	t_command			*commands;	// Liste des commandes parsées
	int					exit_status;// Code de retour de la dernière commande
	int					stdin_backup;	// Sauvegarde stdin
	int					stdout_backup;	// Sauvegarde stdout
}	t_minishell;

/* ************************************************************************** */
/*                              FONCTIONS PARSING                            */
/* ************************************************************************** */

/* Lexer/Tokenizer */
t_token		*tokenize(char *input);
t_token		*create_token(t_token_type type, char *value);
void		free_tokens(t_token *tokens);
int			is_metachar(char c);
int			is_quote(char c);

/* Parser */
t_command	*parse_tokens(t_token *tokens);
t_command	*create_command(void);
t_redirect	*create_redirect(t_redirect_type type, char *filename, char *delimiter);
void		free_commands(t_command *commands);
void		free_redirects(t_redirect *redirects);

/* Expansions */
char		*expand_variables(char *str, t_minishell *shell);
char		*expand_exit_status(char *str, int exit_status);
char		*get_env_var(char *var_name, char **env);

/* Validation syntaxique */
int			validate_syntax(t_token *tokens);
int			check_quotes(char *input);
int			check_pipes(t_token *tokens);
int			check_redirections(t_token *tokens);

/* Gestion des quotes */
char		*handle_quotes(char *str);
char		*remove_quotes(char *str, char quote_type);
int			count_quotes(char *str, char quote);

/* ************************************************************************** */
/*                              FONCTIONS EXECUTION                          */
/* ************************************************************************** */

/* Exécution principale */
int			execute_commands(t_command *commands, t_minishell *shell);
int			execute_single_command(t_command *cmd, t_minishell *shell);
int			execute_pipeline(t_command *commands, t_minishell *shell);

/* Redirections */
int			setup_redirections(t_redirect *redirects);
int			handle_heredoc(char *delimiter);
void		restore_std_fds(t_minishell *shell);

/* Builtins */
int			is_builtin(char *cmd);
int			execute_builtin(char **args, t_minishell *shell);
int			builtin_echo(char **args);
int			builtin_cd(char **args, t_minishell *shell);
int			builtin_pwd(void);
int			builtin_export(char **args, t_minishell *shell);
int			builtin_unset(char **args, t_minishell *shell);
int			builtin_env(char **env);
int			builtin_exit(char **args, t_minishell *shell);

/* Environnement */
char		**copy_env(char **env);
char		**add_env_var(char **env, char *var, char *value);
char		**remove_env_var(char **env, char *var);
void		free_env(char **env);

/* Signaux */
void		setup_signals(void);
void		signal_handler(int sig);
void		signal_handler_heredoc(int sig);

/* ************************************************************************** */
/*                              FONCTIONS UTILITAIRES                        */
/* ************************************************************************** */

/* Utils générales */
void		print_error(char *msg);
void		*safe_malloc(size_t size);
char		*safe_strdup(char *str);
int			array_len(char **array);
void		free_array(char **array);

/* Debug (à supprimer en production) */
void		print_tokens(t_token *tokens);
void		print_commands(t_command *commands);

/* ************************************************************************** */
/*                                  MACROS                                   */
/* ************************************************************************** */

# define PROMPT "minishell$ "
# define MAX_PATH 4096
# define MAX_ARGS 1024

/* Codes d'erreur */
# define SUCCESS 0
# define ERROR 1
# define SYNTAX_ERROR 2
# define COMMAND_NOT_FOUND 127
# define PERMISSION_DENIED 126

/* Messages d'erreur */
# define ERR_SYNTAX "minishell: syntax error near unexpected token"
# define ERR_QUOTE "minishell: syntax error: unterminated quoted string"
# define ERR_PIPE "minishell: syntax error near unexpected token `|'"
# define ERR_REDIR "minishell: syntax error near unexpected token"
# define ERR_MALLOC "minishell: malloc failed"
# define ERR_FORK "minishell: fork failed"
# define ERR_EXEC "minishell: command not found"

#endif