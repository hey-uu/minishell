/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:42:55 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 10:49:46 by hyeyukim         ###   ########.fr       */
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
# define PS_HEREDOC "goldsh heredoc > "


#endif