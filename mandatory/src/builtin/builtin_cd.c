/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:55:14 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/20 19:22:13 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtin_internal.h"
#include "env_manager.h"
#include "libft.h"

static int	print_builtin_error_message(int error_number, int builtin_cmd, char *var)
{
	const char	*cmds[6] = {"cd", "echo", "env", "exit", "export", "pwd"};

	if (error_number == ERROR_ENV_UNSET)
		printf("goldsh: %s: %s not set\n", cmds[builtin_cmd], var);
}

static int	__cd_check_access__(char *dir)
{
printf("| >>>> __cd_check_acess__\n");
printf("| >>>>>> check permission of directory [%s]\n", dir);
	if (access(dir, F_OK) == -1)
	{
		print_builtin_error_message(ERROR_NOT_EXIST, BUILTIN_CD, VAR_HOME);
		return (ACCESS_FAIL);
	}
	if (access(dir, X_OK) == -1)
	{
		print_builtin_error_message(ERROR_NO_PERMIT, BUILTIN_CD, VAR_HOME);
		return (ACCESS_FAIL);
	}
printf("| >>>>>> you have the permission!\n");
	return (ACCESS_SUCCESS);
}

static int	__cd_set_pwd_variables__(char *oldpwd_dir)
{
	char	*pwd_dir;

	pwd_dir = getcwd(NULL, 0);
	if (!pwd_dir)
	{
		free(oldpwd_dir);
		exit_stat_update(1);
		return (BUILTIN_FAIL);
	}
	env_set(ft_strdup(VAR_PWD), pwd_dir);
	env_set(ft_strdup(VAR_OLDPWD), oldpwd_dir);
	return (BUILTIN_SUCCESS);
}

static int	__cd_directory_argument__(char *cur_dir, char *new_dir)
{
	if (__cd_check_access__(new_dir) == ACCESS_FAIL)
	{
		free(cur_dir);
		free(new_dir);
		return (BUILTIN_FAIL);
	}
	if (chdir(new_dir) == -1)
	{
		free(cur_dir);
		free(new_dir);
		return (BUILTIN_FAIL);
	}
	free(new_dir);
	return (__cd_set_pwd_variables__(cur_dir));	
}

static int	__cd_no_argument__(char *cur_dir)
{
	char	*new_dir;

	new_dir = env_dup_val(VAR_HOME);
	if (!new_dir)
	{
		free(cur_dir);
		print_builtin_error_message(ERROR_ENV_UNSET, BUILTIN_CD, VAR_HOME);
		return (BUILTIN_FAIL);
	}
	else if (new_dir[0] == '\0')
	{
		free(new_dir);
		env_set(ft_strdup(VAR_OLDPWD), cur_dir);
		return (BUILTIN_SUCCESS);
	}
	else
		return (__cd_directory_argument__(cur_dir, new_dir));
}

static int	__cd_hyphen_minus__(char *cur_dir)
{
	char	*new_dir;

	new_dir = env_dup_val(VAR_OLDPWD);
	if (!new_dir)
	{
		free(cur_dir);
		print_builtin_error_message(ERROR_ENV_UNSET, BUILTIN_CD, VAR_OLDPWD);
		return (BUILTIN_FAIL);
	}
	return (__cd_directory_argument__(cur_dir, new_dir));
}

int	builtin_cd(char	*argv[])
{
	char	*cur_dir;
	int		res;

	cur_dir = getcwd(NULL, 0);
	if (!cur_dir)
	{
		free_double_char_array(&argv);
		exit_stat_update(1);
		return (BUILTIN_FAIL);
	}
	if (!argv[1])
		res = __cd_no_argument__(cur_dir);
	else if (!ft_strncmp(argv[1], "-", 2))
		res = __cd_hyphen_minus__(cur_dir);
	else
		res = __cd_directory_argument__(cur_dir, ft_strdup(argv[1]));
	if (res == BUILTIN_FAIL)
		exit_stat_update(1);
	free_double_char_array(&argv);
	exit_stat_update(0);
	return (res);	
}