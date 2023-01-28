/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:57:56 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/28 16:19:01 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_BONUS_H
# define TREE_BONUS_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "libadt.h"
# include "s_token_bonus.h"
# include "s_tree_node_bonus.h"

/*-------------- FUNCTION PROTOTYPES -------------*/

/* create tree(node) */
t_node			*create_tree_node(t_node **root);
t_execute_unit	*create_execute_unit(int node_type);

/* destroy tree(node) */
void			destroy_tree(t_node *node);

/* put data in a node */
void			push_arguments(t_queue *q_cmd_argv, t_token *token, int offset);
int				push_redirect(t_queue *q_redir_list, \
													t_token *token, int offset);

#endif
