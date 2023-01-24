/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_expansion.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:31:23 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/24 12:36:02 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_EXPANSION_H
# define S_EXPANSION_H

/*------------- STRUCT DECLARATIONS --------------*/

typedef char	*t_string;

typedef struct s_word_elem
{
	char			*data;
	int				len;
	int				type;
}	t_word_elem;

typedef struct s_word
{
	t_word_elem	*elem_arr;
	int			elem_cnt;
	int			mask; // existence of quote or wildcard
	int			alloc_size;
}	t_word;

typedef struct s_words
{
	t_word	*word_arr;
	int		word_cnt;
	int		alloc_size;
}	t_words;

#endif
