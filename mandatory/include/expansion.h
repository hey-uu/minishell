/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:43:40 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/16 23:18:09 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "t_expansion.h"

/*-------------- FUNCTION PROTOTYPES -------------*/

t_expansion	*expand_word(char *word);
void		destroy_expansion(t_expansion *set);
char		**words_to_strings(t_expansion *set, int count);

#endif