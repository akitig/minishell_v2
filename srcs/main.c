#include "../includes/minishell.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	while (1)
	{
		if (isatty(fileno(stdin)))
			// ./minishell
			ft_putstr_fd("minishell> ", 1);
		else
			// echo "hello" | ./minishell
			ft_putstr_fd("FDがstdinではない", 1);
		break ;
	}
}