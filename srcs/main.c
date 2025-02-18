#include "../includes/minishell.h"

int	main(int ac, char **av)
{
	char	*line;

	(void)ac;
	(void)av;
	if (isatty(fileno(stdin))) //対話型シェル
		// ./minishell
		while ((line = readline("minishell> ")))
		{
			if (*line)
				add_history(line);
			//　入力された文字に対する処理をここに書く
			ft_putstr_fd("You entered: ", 1);
			ft_putstr_fd(line, 1);
			ft_putstr_fd("\n", 1);
			free(line);
		}
	else
	// echo "hello" | ./minishell
	{
		while ((line = get_next_line(0)) != NULL) //非対話型シェル
		{
			ft_putstr_fd("You entered: ", 1);
			ft_putstr_fd(line, 1);
			ft_putstr_fd("\n", 1);
			free(line);
		}
	}
	return (0);
}
