#include "env_manager_internal.h"
#include "libft.h"

static void	__get_exit_stat_str__(char exit_stat_str[4], int exit_stat)
{
	int	i;
	int	tem;

	i = (exit_stat == 0);
	tem = exit_stat;
	while (tem > 0)
	{
		tem /= 10;
		i++;
	}
	exit_stat_str[i] = '\0';
	tem = exit_stat;
	while (--i >= 0)
	{
		exit_stat_str[i] = '0' + tem % 10;
		tem /= 10;
	}
}

int	exit_stat_get(void)
{
	return (exit_stat_manager(EXIT_STAT_GET, 0));
}

char	*exit_stat_get_str(void)
{
	static char	exit_stat_str[4];
	int			exit_stat;

	exit_stat = exit_stat_manager(EXIT_STAT_GET, 0);
	__get_exit_stat_str__(exit_stat_str, exit_stat);
	return (exit_stat_str);
}

char	*exit_stat_get_dup_str(void)
{
	return (ft_strdup(exit_stat_get_str()));
}