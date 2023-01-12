/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:52:43 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/13 04:52:22 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parse_list(t_node **root, t_token *tokens, int *offset)
{
	t_node	*node;

	node = *root;
	node->first_child = create_tree_node();
	if (parse_pipeline(node->first_child, tokens, offset) == SYNTAX_ERROR)
		return (SYNTAX_ERROR);
	if (tokens[*offset].type == TOKEN_AND_IF)
		node->type = NODE_AND_IF;
	else if (tokens[*offset].type == TOKEN_OR_IF)
		node->type = NODE_OR_IF;
	else
	{
		*root = node->first_child;
		free(node);
		return (SYNTAX_OK);
	}
	(*offset)++;
	node->first_child->next_sibling = create_tree_node();
	if (parse_list(&(node->first_child->next_sibling), tokens, offset) \
															== SYNTAX_ERROR)
		return (SYNTAX_ERROR);
	return (SYNTAX_OK);
}
