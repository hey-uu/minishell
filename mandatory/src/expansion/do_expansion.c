/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_expansion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:55:51 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/16 23:22:05 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "expansion_internal.h"
#include "t_tree_node.h"

char	*expand_cmd(char *cmd)
{
	t_expansion	*set;
	char		**strings;
	char		*expanded_cmd;

	set = expand_word(cmd);
	strings = words_to_strings(set, 1);
	expanded_cmd = strings[0];
	free(strings);
	destroy_expansion(set);
	return (expand_cmd);
}

void	expand_cmd_argv(t_queue **cmd_argv)
{
	t_expansion	*set;
	char		**strings;
	int			i;
	t_queue		*new;

	new = create_queue(QUEUE_INITIAL_SIZE, QUEUE_STR_ONLY);
	i = -1;
	while (++i < (*cmd_argv)->used_size)
	{
		set = expand_word(queue_get_str(*cmd_argv, i));
		strings = words_to_strings(set, 0);
		queue_push_strs(new, strings);
		free(strings);
	}
	destroy_queue(*cmd_argv);
	destroy_expansion(set);
	*cmd_argv = new;
}

void	expand_redir_list(t_queue **redir_list)
{
	t_expansion	*set;
	char		**strings;
	int			i;
	t_queue		*new;
	t_intstr	qdata;

	new = create_queue(QUEUE_INITIAL_SIZE, QUEUE_INTSTR);
	i = -1;
	while (++i < (*redir_list)->used_size)
	{
		qdata = queue_get_intstr(*redir_list, i);
		set = expand_word(qdata.str);
		strings = words_to_strings(set, 0);
		if (strings[0] && strings[1])
		{
			queue_push_intstr(new, AMBIGUOUS_REDIRECT, NULL);
			free_double_array(&strings);
		}
		else
			queue_push_intstr(new, qdata.num, strings[0]);
		free(strings);
	}
	destroy_queue(*redir_list);
	destroy_expansion(set);
	*redir_list = new;
}

void	do_expansion(t_execute_unit *exe_unit)
{
	exe_unit->cmd_name = expand_cmd(exe_unit->cmd_name);
	expand_cmd_argv(&exe_unit->cmd_argv);
	expand_redir_list(&exe_unit->redir_list);
}
