#include "../includes/minishell.h"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_strcmp(av[1], "test") == 0)
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	return (0);
}