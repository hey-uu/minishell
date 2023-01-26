/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 08:46:06 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/26 20:08:24 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal_handle.h"
#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

static void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (signo == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

static void	signal_ignore(int signo)
{
	signo = 0;
	printf("\n");
}

void	set_signal(int sig_int, int sig_quit)
{
	{
		if (sig_int == DEFAULT)
			signal(SIGINT, SIG_DFL);
		else if (sig_int == IGNORE)
			signal(SIGINT, signal_ignore);
		else if (sig_int == CATCH)
			signal(SIGINT, signal_handler);
	}
	{
		if (sig_quit == DEFAULT)
			signal(SIGQUIT, SIG_DFL);
		else if (sig_quit == IGNORE)
			signal(SIGQUIT, SIG_IGN);
		else if (sig_quit == CATCH)
			signal(SIGQUIT, signal_handler);
	}
}
