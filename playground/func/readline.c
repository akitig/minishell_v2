#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*input;

	while (1)
	{
		// プロンプトを表示し、ユーザーの入力を取得
		input = readline("minishell> ");
		// EOF（Ctrl+D）またはエラーが発生した場合
		if (input == NULL)
		{
			printf("\nExiting minishell...\n");
			break ;
		}
		// 空の入力でなければ履歴に追加
		if (*input)
		{
			add_history(input);
		}
		// 入力を表示（デバッグ用）
		printf("You entered: %s\n", input);
		// メモリ解放（readline は動的に確保するため）
		free(input);
	}
	return (0);
}
