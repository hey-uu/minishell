/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 03:45:50 by hyeyukim          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/01/18 03:50:16 by hyeyukim         ###   ########.fr       */
=======
/*   Updated: 2023/01/18 08:51:06 by hyeyukim         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "env_manager_internal.h"
<<<<<<< HEAD
=======
#include "libft.h"
>>>>>>> master

char	*env_get(char *variable)
{
	return (env_manager(ENV_GET, NULL, variable, NULL));
}

char	*env_dup_val(char *variable)
{
	char	*value;

	value = env_manager(ENV_GET, NULL, variable, NULL);
	if (!value)
		return (value);
	return (ft_strdup(value));
}

char	**env_tab_to_arr(void)
{
	return (env_manager(ENV_TAB_TO_ARR, NULL, NULL, NULL));
}