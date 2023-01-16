/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_execute_unit_content.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:49:32 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/16 17:01:46 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

void	push_arguments(t_queue *cmd_argv, t_token *token, int offset)
{
	char	*str;

	if (token[offset].str)
		str = ft_strdup(token[offset].str);
	else
		return ;
	queue_push_str(cmd_argv, str);
}

void	push_redirection(t_queue *redir_list, t_token *token, int offset)
{
	const int	type = token[offset].type;
	char		*str;

	if (type == TOKEN_REDIR_IN_HERE)
		str = process_heredoc(token[offset + 1].str);
	else if (token[offset + 1].str)
		str = ft_strdup(token[offset + 1].str);
	else
		return ;
	queue_push_intstr(redir_list, (int)type, (char *)str);
}
