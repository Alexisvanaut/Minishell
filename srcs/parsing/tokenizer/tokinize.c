/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvanaut <alvanaut@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 12:00:00 by alvanaut          #+#    #+#             */
/*   Updated: 2025/07/19 12:00:00 by alvanaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Fonction utilitaire pour vérifier les métacaractères */
int	is_metachar(char c)
{
	return (c == '|' || c == '<' || c == '>' || c == ' ' || c == '\t');
}

/* Fonction utilitaire pour vérifier les quotes */
int	is_quote(char c)
{
	return (c == '\'' || c == '"');
}

/* Fonction utilitaire pour ignorer les espaces */
static void	skip_whitespace(char **input)
{
	while (**input && (**input == ' ' || **input == '\t'))
		(*input)++;
}

/* Créer un nouveau token */
t_token	*create_token(t_token_type type, char *value)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = type;
	token->value = value;
	token->next = NULL;
	return (token);
}

/* Ajouter un token à la fin de la liste */
static void	add_token_to_list(t_token **head, t_token *new_token)
{
	t_token	*current;

	if (!*head)
	{
		*head = new_token;
		return ;
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = new_token;
}

/* Extraire un mot (jusqu'à un métacaractère ou quote) */
static char	*extract_word(char **input)
{
	char	*start;
	char	*word;
	int		len;
	int		i;

	start = *input;
	len = 0;
	
	// Calculer la longueur du mot
	while (start[len] && !is_metachar(start[len]) && !is_quote(start[len]))
		len++;
	
	if (len == 0)
		return (NULL);
	
	// Allouer et copier
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	
	*input += len;
	return (word);
}

/* Extraire une chaîne entre quotes */
static char	*extract_quoted_string(char **input)
{
	char	quote_char;
	char	*start;
	char	*quoted_str;
	int		len;
	int		i;

	quote_char = **input;
	(*input)++; // Passer la première quote
	start = *input;
	len = 0;
	
	// Chercher la quote fermante
	while (start[len] && start[len] != quote_char)
		len++;
	
	// Si pas de quote fermante, erreur de syntaxe
	if (start[len] != quote_char)
		return (NULL); // Gestion d'erreur à améliorer
	
	// Allouer et copier (sans les quotes)
	quoted_str = malloc(len + 1);
	if (!quoted_str)
		return (NULL);
	
	i = 0;
	while (i < len)
	{
		quoted_str[i] = start[i];
		i++;
	}
	quoted_str[i] = '\0';
	
	*input += len + 1; // +1 pour passer la quote fermante
	return (quoted_str);
}

/* Extraire un opérateur (|, <, >, >>, <<) */
static t_token	*extract_operator(char **input)
{
	t_token_type	type;
	char			*value;

	if (**input == '|')
	{
		type = TOKEN_PIPE;
		value = ft_strdup("|");
		(*input)++;
	}
	else if (**input == '<')
	{
		if (*(*input + 1) == '<')
		{
			type = TOKEN_REDIR_HEREDOC;
			value = ft_strdup("<<");
			(*input) += 2;
		}
		else
		{
			type = TOKEN_REDIR_IN;
			value = ft_strdup("<");
			(*input)++;
		}
	}
	else if (**input == '>')
	{
		if (*(*input + 1) == '>')
		{
			type = TOKEN_REDIR_APPEND;
			value = ft_strdup(">>");
			(*input) += 2;
		}
		else
		{
			type = TOKEN_REDIR_OUT;
			value = ft_strdup(">");
			(*input)++;
		}
	}
	else
		return (NULL);

	if (!value)
		return (NULL);
	return (create_token(type, value));
}

/* Vérifier que toutes les quotes sont fermées */
int	check_quotes(char *input)
{
	int	in_single_quote;
	int	in_double_quote;
	int	i;

	in_single_quote = 0;
	in_double_quote = 0;
	i = 0;
	
	while (input[i])
	{
		if (input[i] == '\'' && !in_double_quote)
			in_single_quote = !in_single_quote;
		else if (input[i] == '"' && !in_single_quote)
			in_double_quote = !in_double_quote;
		i++;
	}
	
	// Retourne 1 si toutes les quotes sont fermées
	return (!in_single_quote && !in_double_quote);
}

/* Fonction principale de tokenisation */
t_token	*tokenize(char *input)
{
	t_token	*head;
	t_token	*new_token;
	char	*word;

	if (!input || !*input)
		return (NULL);
	
	// Vérifier que toutes les quotes sont fermées
	if (!check_quotes(input))
	{
		printf("minishell: syntax error: unterminated quoted string\n");
		return (NULL);
	}

	head = NULL;
	
	while (*input)
	{
		skip_whitespace(&input);
		
		if (!*input)
			break;
		
		// Traiter les opérateurs
		if (*input == '|' || *input == '<' || *input == '>')
		{
			new_token = extract_operator(&input);
			if (!new_token)
			{
				free_tokens(head);
				return (NULL);
			}
			add_token_to_list(&head, new_token);
		}
		// Traiter les chaînes entre quotes
		else if (is_quote(*input))
		{
			word = extract_quoted_string(&input);
			if (!word)
			{
				printf("minishell: syntax error: unterminated quoted string\n");
				free_tokens(head);
				return (NULL);
			}
			new_token = create_token(TOKEN_WORD, word);
			if (!new_token)
			{
				free(word);
				free_tokens(head);
				return (NULL);
			}
			add_token_to_list(&head, new_token);
		}
		// Traiter les mots normaux
		else
		{
			word = extract_word(&input);
			if (word)
			{
				new_token = create_token(TOKEN_WORD, word);
				if (!new_token)
				{
					free(word);
					free_tokens(head);
					return (NULL);
				}
				add_token_to_list(&head, new_token);
			}
		}
	}
	
	return (head);
}

/* Libérer la mémoire des tokens */
void	free_tokens(t_token *tokens)
{
	t_token	*current;
	t_token	*next;

	current = tokens;
	while (current)
	{
		next = current->next;
		if (current->value)
			free(current->value);
		free(current);
		current = next;
	}
}

/* Fonction de debug pour afficher les tokens */
void	print_tokens(t_token *tokens)
{
	t_token	*current;
	char	*type_names[] = {
		"WORD", "PIPE", "REDIR_IN", "REDIR_OUT", 
		"REDIR_APPEND", "REDIR_HEREDOC", "EOF"
	};

	current = tokens;
	printf("=== TOKENS ===\n");
	while (current)
	{
		printf("Type: %-15s Value: '%s'\n", 
			type_names[current->type], current->value);
		current = current->next;
	}
	printf("==============\n");
}