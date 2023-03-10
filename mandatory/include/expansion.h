/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 23:59:05 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/24 22:51:29 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "s_expansion.h"
# include "tree.h"

/*-------------- FUNCTION PROTOTYPES -------------*/

void	do_expansion(t_execute_unit *exe_unit);
char	*get_variable_name(char *str, int *idx, int *qmark);
void	expand_redir_list(t_queue **q_redir_list, t_intstr **redir_list);

#endif