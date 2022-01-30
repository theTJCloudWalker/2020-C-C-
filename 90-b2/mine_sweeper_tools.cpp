/* 2053285 罗斌江 信21 */
//工具函数，如拓展区域，判断游戏是否成功等

int if_win(int amount, int X, int Y,char show_mine[][30])
{
	int i, j;
	for (i = 0; i < X; i++)
	{
		for (j = 0; j < Y; j++)
		{
			if (show_mine[i][j] == 'X')
			{
				amount++;
			}
		}
	}
	return amount;
}

void open_the_map(char input, char pattern, char real_mine[][30], char show_mine[][30], int m, int n, char sign_mine[][30])
{
	if (input != '8' && input != '9')
	{
		if (sign_mine[m][n] != 'x')
		{
			show_mine[m][n] = real_mine[m][n];
		}
		int X = 0, Y = 0;
		switch (pattern)
		{
			case '1':
				X = 9;
				Y = 9;
				break;
			case '2':
				X = 16;
				Y = 16;
				break;
			case '3':
				X = 16;
				Y = 30;
				break;
		}
		bool SWITCH = 1;
		if (real_mine[m][n] == '0' && sign_mine[m][n] != 'x')
		{
			if (m - 1 >= 0 && n - 1 >= 0 && real_mine[m - 1][n - 1] == '0' && show_mine[m - 1][n - 1] == 'X' && sign_mine[m - 1][n - 1] != 'x')
			{
				open_the_map(input, pattern, real_mine, show_mine, m - 1, n - 1, sign_mine);
			}
			else if (m - 1 >= 0 && n - 1 >= 0 && real_mine[m - 1][n - 1] != '*' && sign_mine[m - 1][n - 1] != 'x')
			{
				show_mine[m - 1][n - 1] = real_mine[m - 1][n - 1];
			}
			else
			{
				;
			}
			if (m - 1 >= 0 && real_mine[m - 1][n] == '0' && show_mine[m - 1][n] == 'X' && sign_mine[m - 1][n] != 'x')
			{
				open_the_map(input, pattern, real_mine, show_mine, m - 1, n, sign_mine);
			}
			else if (m - 1 >= 0 && real_mine[m - 1][n] != '*' && sign_mine[m - 1][n] != 'x')
			{
				show_mine[m - 1][n] = real_mine[m - 1][n];
			}
			else
			{
				;
			}
			if (real_mine[m - 1][n + 1] == '0' && m - 1 >= 0 && n + 1 < Y && show_mine[m - 1][n + 1] == 'X' && sign_mine[m - 1][n + 1] != 'x')
			{
				open_the_map(input, pattern, real_mine, show_mine, m - 1, n + 1, sign_mine);
			}
			else if (m - 1 >= 0 && n + 1 < Y && real_mine[m - 1][n + 1] != '*' && sign_mine[m - 1][n + 1] != 'x')
			{
				show_mine[m - 1][n + 1] = real_mine[m - 1][n + 1];
			}
			else
			{
				;
			}
			if (n - 1 >= 0 && real_mine[m][n - 1] == '0' && show_mine[m][n - 1] == 'X' && sign_mine[m][n - 1] != 'x')
			{
				open_the_map(input, pattern, real_mine, show_mine, m, n - 1, sign_mine);
			}
			else if (n - 1 >= 0 && real_mine[m][n - 1] != '*' && sign_mine[m][n - 1] != 'x')
			{
				show_mine[m][n - 1] = real_mine[m][n - 1];
			}
			else
			{
				;
			}
			if (real_mine[m][n + 1] == '0' && n + 1 < Y && show_mine[m][n + 1] == 'X' && sign_mine[m][n + 1] != 'x')
			{
				open_the_map(input, pattern, real_mine, show_mine, m, n + 1, sign_mine);
			}
			else if (n + 1 < Y && real_mine[m][n + 1] != '*' && sign_mine[m][n + 1] != 'x')
			{
				show_mine[m][n + 1] = real_mine[m][n + 1];
			}
			else
			{
				;
			}
			if (m + 1 <= 9 && n - 1 >= 0 && real_mine[m + 1][n - 1] == '0' && show_mine[m + 1][n - 1] == 'X' && sign_mine[m + 1][n - 1] != 'x')
			{
				open_the_map(input, pattern, real_mine, show_mine, m + 1, n - 1, sign_mine);
			}
			else if (m + 1 <= 9 && n - 1 >= 0 && real_mine[m + 1][n - 1] != '*' && sign_mine[m + 1][n - 1] != 'x')
			{
				show_mine[m + 1][n - 1] = real_mine[m + 1][n - 1];
			}
			else
			{
				;
			}
			if (real_mine[m + 1][n] == '0' && m + 1 < X && show_mine[m + 1][n] == 'X' && sign_mine[m + 1][n] != 'x')
			{
				open_the_map(input, pattern, real_mine, show_mine, m + 1, n, sign_mine);
			}
			else if (m + 1 < X && real_mine[m + 1][n] != '*' && sign_mine[m + 1][n] != 'x')
			{
				show_mine[m + 1][n] = real_mine[m + 1][n];
			}
			else
			{
				;
			}
			if (real_mine[m + 1][n + 1] == '0' && m + 1 < X && n + 1 < Y && show_mine[m + 1][n + 1] == 'X' && sign_mine[m + 1][n + 1] != 'x')
			{
				open_the_map(input, pattern, real_mine, show_mine, m + 1, n + 1, sign_mine);
			}
			else if (m + 1 < X && n + 1 < Y && real_mine[m + 1][n + 1] != '*' && sign_mine[m + 1][n + 1] != 'x')
			{
				show_mine[m + 1][n + 1] = real_mine[m + 1][n + 1];
			}
			else
			{
				;
			}
		}
		return;
	}
	else
	{
		if (sign_mine[m][n] != '#')
		{
			show_mine[m][n] = real_mine[m][n];
		}
		int X = 0, Y = 0;
		switch (pattern)
		{
			case '1':
				X = 9;
				Y = 9;
				break;
			case '2':
				X = 16;
				Y = 16;
				break;
			case '3':
				X = 16;
				Y = 30;
				break;
		}
		bool SWITCH = 1;
		if (real_mine[m][n] == '0' && sign_mine[m][n] != '#')
		{
			if (m - 1 >= 0 && n - 1 >= 0 && real_mine[m - 1][n - 1] == '0' && show_mine[m - 1][n - 1] == 'X' && sign_mine[m - 1][n - 1] != '#')
			{
				open_the_map(input, pattern, real_mine, show_mine, m - 1, n - 1, sign_mine);
			}
			else if (m - 1 >= 0 && n - 1 >= 0 && real_mine[m - 1][n - 1] != '*' && sign_mine[m - 1][n - 1] != '#')
			{
				show_mine[m - 1][n - 1] = real_mine[m - 1][n - 1];
			}
			else
			{
				;
			}
			if (m - 1 >= 0 && real_mine[m - 1][n] == '0' && show_mine[m - 1][n] == 'X' && sign_mine[m - 1][n] != '#')
			{
				open_the_map(input, pattern, real_mine, show_mine, m - 1, n, sign_mine);
			}
			else if (m - 1 >= 0 && real_mine[m - 1][n] != '*' && sign_mine[m - 1][n] != '#')
			{
				show_mine[m - 1][n] = real_mine[m - 1][n];
			}
			else
			{
				;
			}
			if (real_mine[m - 1][n + 1] == '0' && m - 1 >= 0 && n + 1 < Y && show_mine[m - 1][n + 1] == 'X' && sign_mine[m - 1][n + 1] != '#')
			{
				open_the_map(input, pattern, real_mine, show_mine, m - 1, n + 1, sign_mine);
			}
			else if (m - 1 >= 0 && n + 1 < Y && real_mine[m - 1][n + 1] != '*' && sign_mine[m - 1][n + 1] != '#')
			{
				show_mine[m - 1][n + 1] = real_mine[m - 1][n + 1];
			}
			else
			{
				;
			}
			if (n - 1 >= 0 && real_mine[m][n - 1] == '0' && show_mine[m][n - 1] == 'X' && sign_mine[m][n - 1] != '#')
			{
				open_the_map(input, pattern, real_mine, show_mine, m, n - 1, sign_mine);
			}
			else if (n - 1 >= 0 && real_mine[m][n - 1] != '*' && sign_mine[m][n - 1] != '#')
			{
				show_mine[m][n - 1] = real_mine[m][n - 1];
			}
			else
			{
				;
			}
			if (real_mine[m][n + 1] == '0' && n + 1 < Y && show_mine[m][n + 1] == 'X' && sign_mine[m][n + 1] != '#')
			{
				open_the_map(input, pattern, real_mine, show_mine, m, n + 1, sign_mine);
			}
			else if (n + 1 < Y && real_mine[m][n + 1] != '*' && sign_mine[m][n + 1] != '#')
			{
				show_mine[m][n + 1] = real_mine[m][n + 1];
			}
			else
			{
				;
			}
			if (m + 1 <= 9 && n - 1 >= 0 && real_mine[m + 1][n - 1] == '0' && show_mine[m + 1][n - 1] == 'X' && sign_mine[m + 1][n - 1] != '#')
			{
				open_the_map(input, pattern, real_mine, show_mine, m + 1, n - 1, sign_mine);
			}
			else if (m + 1 <= 9 && n - 1 >= 0 && real_mine[m + 1][n - 1] != '*' && sign_mine[m + 1][n - 1] != '#')
			{
				show_mine[m + 1][n - 1] = real_mine[m + 1][n - 1];
			}
			else
			{
				;
			}
			if (real_mine[m + 1][n] == '0' && m + 1 < X && show_mine[m + 1][n] == 'X' && sign_mine[m + 1][n] != '#')
			{
				open_the_map(input, pattern, real_mine, show_mine, m + 1, n, sign_mine);
			}
			else if (m + 1 < X && real_mine[m + 1][n] != '*' && sign_mine[m + 1][n] != '#')
			{
				show_mine[m + 1][n] = real_mine[m + 1][n];
			}
			else
			{
				;
			}
			if (real_mine[m + 1][n + 1] == '0' && m + 1 < X && n + 1 < Y && show_mine[m + 1][n + 1] == 'X' && sign_mine[m + 1][n + 1] != '#')
			{
				open_the_map(input, pattern, real_mine, show_mine, m + 1, n + 1, sign_mine);
			}
			else if (m + 1 < X && n + 1 < Y && real_mine[m + 1][n + 1] != '*' && sign_mine[m + 1][n + 1] != '#')
			{
				show_mine[m + 1][n + 1] = real_mine[m + 1][n + 1];
			}
			else
			{
				;
			}
		}
		return;

	}
}
