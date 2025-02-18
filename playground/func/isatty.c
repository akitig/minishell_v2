#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int			fds[] = {STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO};
	const char	*names[] = {"stdin", "stdout", "stderr"};
	char		*endptr;
	long		user_fd_long;
	int			user_fd;

	/* 標準入出力用のファイルディスクリプタと名前の配列 */
	/* 標準のファイルディスクリプタが端末かどうかを確認 */
	for (int i = 0; i < 3; i++)
	{
		errno = 0; // errno をリセット
		if (isatty(fds[i]))
		{
			printf("%s (fd = %d) は端末デバイスです。\n", names[i], fds[i]);
		}
		else
		{
			if (errno != 0)
			{
				fprintf(stderr, "%s (fd = %d) のチェック中にエラー発生: %s\n", names[i],
					fds[i], strerror(errno));
			}
			else
			{
				printf("%s (fd = %d) は端末デバイスではありません。\n", names[i], fds[i]);
			}
		}
	}
	/* コマンドライン引数が渡されているか確認 */
	if (argc < 2)
	{
		fprintf(stderr, "使い方: %s <ファイルディスクリプタの数値>\n", argv[0]);
		return (1);
	}
	/* 渡された引数を整数に変換 */
	user_fd_long = strtol(argv[1], &endptr, 10);
	if (*endptr != '\0' || user_fd_long < 0 || user_fd_long > INT_MAX)
	{
		fprintf(stderr, "無効なファイルディスクリプタの数値: %s\n", argv[1]);
		return (1);
	}
	user_fd = (int)user_fd_long;
	/* 入力されたFDに対して isatty のチェック */
	errno = 0; // errno をリセット
	if (isatty(user_fd))
	{
		printf("引数として渡された fd (%d) は端末デバイスです。\n", user_fd);
	}
	else
	{
		if (errno != 0)
		{
			fprintf(stderr, "引数として渡された fd (%d) のチェック中にエラー発生: %s\n", user_fd,
				strerror(errno));
		}
		else
		{
			printf("引数として渡された fd (%d) は端末デバイスではありません。\n", user_fd);
		}
	}
	return (0);
}
