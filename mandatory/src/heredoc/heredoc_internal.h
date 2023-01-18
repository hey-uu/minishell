/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:42:55 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 17:21:54 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_INTERNAL_H
# define HEREDOC_INTERNAL_H

/*--------------- STANDARD HEADERS ---------------*/

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <readline/readline.h>

/*-------------- USER DEFINED HEADERS ------------*/

# include "libft.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/

# define CHARSET "abcdefghijklmnopqrstuvwxyz\
ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"
# define INITIAL_TEMP_FILENAME "/tmp/goldsh_"
# define PS_HEREDOC "> "

/*-------------- FUNCTION PROTOTYPES -------------*/

int		get_delimiter_len(char *word);
void	store_delimiter(char *delimiter, char *word);
void	make_heredoc_with_expansion(char *line, int fd);

#endif