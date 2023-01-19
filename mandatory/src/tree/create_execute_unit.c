/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_execute_unit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:30:31 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/19 19:25:52 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

t_execute_unit	*create_execute_unit(int node_type)
{
	t_execute_unit	*new;

	new = ft_malloc(sizeof(t_execute_unit));
	if (node_type == NODE_SUBSHELL)
	{
		new->cmd_name = NULL;
		new->q_cmd_argv = NULL;
		new->q_redir_list = create_queue(QUEUE_INITIAL_SIZE, QUEUE_INTSTR);
	}
	else if (node_type == NODE_SIMPLE_CMD)
	{
		new->cmd_name = NULL;
		new->q_cmd_argv = create_queue(QUEUE_INITIAL_SIZE, QUEUE_STR_ONLY);
		new->q_redir_list = create_queue(QUEUE_INITIAL_SIZE, QUEUE_INTSTR);
	}
	new->cmd_argv = NULL;
	new->redir_list = NULL;
	return (new);
}
