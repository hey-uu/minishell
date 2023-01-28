/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_welcome_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:24:36 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 16:19:32 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "style_bonus.h"
#include "prompt_bonus.h"
#include "libftprintf.h"

void	print_welcome(void)
{
	static char	*shell_name = \
" ██████╗  ██████╗ ██╗     ██████╗     ██████╗  █████╗ ██████╗ ██╗   ██╗\n\
██╔════╝ ██╔═══██╗██║     ██╔══██╗    ██╔══██╗██╔══██╗██╔══██╗╚██╗ ██╔╝\n\
██║  ███╗██║   ██║██║     ██║  ██║    ██████╔╝███████║██████╔╝ ╚████╔╝ \n\
██║   ██║██║   ██║██║     ██║  ██║    ██╔══██╗██╔══██║██╔══██╗  ╚██╔╝  \n\
╚██████╔╝╚██████╔╝███████╗██████╔╝    ██████╔╝██║  ██║██████╔╝   ██║   \n\
 ╚═════╝  ╚═════╝ ╚══════╝╚═════╝     ╚═════╝ ╚═╝  ╚═╝╚═════╝    ╚═╝   \n\n";
	static char	*shell_introduction = \
"\n /\\                                                                /\\\
\n    ==============================================================\
\n      welcome to yonazang and meyun's shell....\
\n      this is crazy...\
\n      let me introduce my baby... my gold baby.... GEUMJJOKI...\
\n    ==============================================================\
\n                                                         v 1.0.0";

	ft_printf(YELLO "\n%s" RESET, shell_name);
	ft_printf(ITAL "%s\n" RESET, shell_introduction);
}
