/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:20:50 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 08:06:54 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_INTERNAL_H
# define PARSER_INTERNAL_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "tree.h"

/*-------------- FUNCTION PROTOTYPES -------------*/

int	is_redirection(int type);
int	parse_list(t_node **root, t_token *tokens, int *offset);
int	parse_pipeline(t_node *node, t_token *tokens, int *offset);
int	parse_simple_command(t_node *node, t_token *token, int *offset);
int	parse_subshell(t_node *node, t_token *tokens, int *offset);

#endif