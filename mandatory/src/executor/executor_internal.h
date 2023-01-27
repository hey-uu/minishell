/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_internal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 00:51:31 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 19:34:37 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_INTERNAL_H
# define EXECUTOR_INTERNAL_H

/*--------------- STANDARD HEADERS ---------------*/

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "tree.h"
# include "constants.h"
# include "handle_error.h"
# include "handle_signal.h"
# include "env_manager.h"
# include "exit_stat_manager.h"


/*------------ DEFINE MACRO CONSTANTS ------------*/

# define P_READ 0
# define P_WRITE 1
# define IN 0
# define OUT 1

enum e_redirect_type {
	REDIR_NONE = TOKEN_NONE,
	REDIR_IN = TOKEN_REDIR_IN,
	REDIR_HEREDOC = TOKEN_REDIR_IN_HERE,
	REDIR_OUT = TOKEN_REDIR_OUT,
	REDIR_APPEND = TOKEN_REDIR_OUT_APP,
};

typedef struct s_pipeline {
	int	pipe_exist;
	int	child_cnt;
	int	old_pipe_fd[2];
	int	new_pipe_fd[2];
	int	last_child_pid;
	int	exit_status;
}	t_pipeline;

/*------------- STRUCT DECLARATIONS --------------*/

typedef int		(*t_redirect)(char *, int);
typedef void	(*t_builtin)(char **argv);

/*-------------- FUNCTION PROTOTYPES -------------*/

int		executor(t_node *parse_tree);

void	builtin_echo(char *argv[]);
void	builtin_cd(char *argv[]);
void	builtin_pwd(char *argv[]);
void	builtin_export(char *argv[]);
void	builtin_env(char *argv[]);
void	builtin_exit(char *argv[]);
void	builtin_unset(char *argv[]);

int		access_command(char **cmd_name);

int		execute_list(t_node *node);
int		execute_pipeline(t_node *node);
int		execute_single_builtin(t_execute_unit *exe_unit);
int		execute_subshell(t_node *node, t_pipeline *pl, int nth);
int		execute_simple_command(\
		t_execute_unit *exe_unit, t_pipeline *pl, int nth);
int		get_builtin_cmd_idx(char *cmd_name);

int		do_redirecting(t_redir *redir_list);
void	set_standard_stream(t_pipeline *pl, t_redir *redir_list, int nth);
void	open_new_pipe(int new_pipe_fd[2]);
void	close_pipe_in_parent(\
		int old_pipe_fd[2], int new_pipe_fd[2], int first, int last);
void	execute_builtin(t_execute_unit *exe_unit);

#endif