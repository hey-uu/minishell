/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:48:27 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/26 17:58:52 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*--------------- STANDARD HEADERS ---------------*/

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*-------------- USER DEFINED HEADERS ------------*/

# include "libft.h"
# include "libadt.h"
# include "libprintf.h"
# include "s_token.h"
# include "s_tree_node.h"
# include "error.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/

enum e_result_status
{
	FAILURE = -1,
	SUCCESS = 0
};

/*-------------- FUNCTION PROTOTYPES -------------*/

void	run_commands(char *input);
int		lexer(char *input, t_token **token_list);
int		parser(t_token *tokens, t_node **parse_tree);
int		executor(t_node *parse_tree);

// int	do_expansion(t_execute_unit *exe_unit);
void		do_expansion(t_execute_unit *exe_unit);

void	destroy_token_list(t_token *token_list);
void	destroy_tree(t_node *node);
int		parse_list(t_node **root, t_token *tokens, int *offset);
char	*process_heredoc(t_queue *q_redir_list, char *word);
void	exit_by_error(char *msg);

#endif
