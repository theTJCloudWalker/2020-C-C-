/* 2053285 罗斌江 信21 */
//伪图形界面的相关函数的实现
#include<iostream>
#include"cmd_console_tools.h"
#include"mine_sweeper.h"

using namespace std;

void output2(char input, char pattern, char real_mine[][30], char show_mine[][30], char sign_mine[][30])
{
	//初始化
	int i, j, X = 0, Y = 0, x = 0, y = 0;
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
	//输出

	if (input == '1')
	{
		//line1
		cout << endl;
		//line2
		cout << "  |";
		for (i = 1; i <= Y; i++)
		{
			if (i <= 9)
			{
				cout << i << " ";
			}
			else if (i > 9)
			{
				cout << char(i + 'W') << " ";
			}
		}
		cout << endl;
		//line3
		cout << "--+";
		for (i = 0; i < 2 * Y + 2; i++)
		{
			cout << "-";
		}
		cout << endl;
		//line4
		for (i = 0; i < X; i++)
		{
			cout << char(i + 'A') << " |";
			for (j = 0; j < Y; j++)
			{
				if (sign_mine[i][j] == 'x')
				{
					cct_setcolor(4, 7);
					cout << real_mine[i][j];
					cct_setcolor(0, 7);
					cout << " ";
				}
				else
				{
					if (real_mine[i][j] != 'X')
					{
						cct_setcolor(14, 8);
						cout << real_mine[i][j];
						cct_setcolor(0, 7);
						cout << " ";
					}
					else
					{
						cout << real_mine[i][j] << " ";
					}
				}
			}
			cout << endl;
		}
	}
	else
	{
		//line1
		cout << endl;
		//line2
		for (i = 0; i < Y; i++)
		{
			if (i <= 9)
			{
				cout << "     " << i;
			}
			else
			{
				cout << "    " << i;
			}
		}
		cout << endl;
		//line3
		//cct_showch(i, j, '╔', 15, 9, 1);
		for (i = 0; i <= 3 * X; i++)
		{
			//字母
			if (i % 3 == 2)
			{
				cout << char(i / 3 + 'A') << " ";
			}
			else
			{
				cout << "  ";
			}
			for (j = 0; j <= 6 * Y; j++)
			{
				if (i % 3 == 0)
				{
					//框架
					if (i == 0)//图形第一行
					{
						if (j == 0)
						{
							cct_setcolor(15, 9);
							cout << "╔";
							cct_setcolor(0, 7);
							//cct_showch(i, j, '╔', 15, 9, 1);
							j++;
						}
						else if (j == 6 * Y)
						{
							cct_setcolor(15, 9);
							cout << "╗";
							cct_setcolor(0, 7);
							//cct_showch(i, j, '╗', 15, 9, 1);
							j++;
						}
						else if (j % 6 == 0)
						{
							cct_setcolor(15, 9);
							cout << "╦";
							cct_setcolor(0, 7);
							//cct_showch(i, j, '╦', 15, 9, 1);
							j++;
						}
						else
						{
							cct_setcolor(15, 9);
							cout << "═";
							cct_setcolor(0, 7);
							//cct_showch(i, j, '═', 15, 9, 1);
							j++;
						}
					}
					else if (i == 3 * X)//图形最后一行
					{
						if (j == 0)
						{
							cct_setcolor(15, 9);
							cout << "╚";
							cct_setcolor(0, 7);
							//cct_showch(i, j, '╚', 15, 9, 1);
							j++;
						}
						else if (j == 6 * Y)
						{
							cct_setcolor(15, 9);
							cout << "╝";
							cct_setcolor(0, 7);
							//cct_showch(i, j, '╝', 15, 9, 1);
							j++;
						}
						else if (j % 6 == 0)
						{
							cct_setcolor(15, 9);
							cout << "╩";
							cct_setcolor(0, 7);
							//cct_showch(i, j, '╩', 15, 9, 1);
							j++;
						}
						else
						{
							cct_setcolor(15, 9);
							cout << "═";
							cct_setcolor(0, 7);
							//cct_showch(i, j, '═', 15, 9, 1);
							j++;
						}
					}
					else
					{
						if (j == 0)
						{
							cct_setcolor(15, 9);
							cout << "╠";
							cct_setcolor(0, 7);
							//cct_showch(i, j, '╠', 15, 9, 1);
							j++;
						}
						else if (j == 6 * Y)
						{
							cct_setcolor(15, 9);
							cout << "╣";
							cct_setcolor(0, 7);
							//cct_showch(i, j, '╣', 15, 9, 1);
							j++;
						}
						else if (j % 6 == 0)
						{
							cct_setcolor(15, 9);
							cout << "╬";
							cct_setcolor(0, 7);
							//cct_showch(i, j, '╬', 15, 9, 1);
							j++;
						}
						else
						{
							cct_setcolor(15, 9);
							cout << "═";
							cct_setcolor(0, 7);
							//cct_showch(i, j, '═', 15, 9, 1);
							j++;
						}
					}
				}
				else
				{
				    //框架
					if (j % 6 == 0)
					{
						cct_setcolor(15, 9);
						cout << "║";
						cct_setcolor(0, 7);
						//cct_showch(i, j, '║', 15, 9, 1);
						j++;
					}
					else
					{  
						if (i % 3 == 2 && j % 3 == 0)
						{   //输出字符处
							if (real_mine[i / 3][j / 6] != '0' && show_mine[i / 3][j / 6] != 'X')
							{
								if (real_mine[i / 3][j / 6] != '*')
								{
									cct_setcolor(11, real_mine[i / 3][j / 6] - '0');
									cout << real_mine[i / 3][j / 6];
									cct_setcolor(0, 7);
								}
								else
								{
									cct_setcolor(11, 9);
									cout << real_mine[i / 3][j / 6];
									cct_setcolor(0, 7);
								}
							}
							else
							{
								if (input == '6' || input == '5')
								{
									if (real_mine[i / 3][j / 6] != '0')
									{
										if (real_mine[i / 3][j / 6] != '*')
										{
											cct_setcolor(11, real_mine[i / 3][j / 6] - '0');
											cout << real_mine[i / 3][j / 6];
											cct_setcolor(0, 7);
										}
										else
										{
											cct_setcolor(11, 9);
											cout << real_mine[i / 3][j / 6];
											cct_setcolor(0, 7);
										}
									}
									else
									{
										cct_setcolor(11, 9);
										cout << " ";
										cct_setcolor(0, 7);
									}
								}
								else if (input == '7')
								{
									if (show_mine[i / 3][j / 6] != 'X' && real_mine[i / 3][j / 6] != '0')
									{
										if (real_mine[i / 3][j / 6] != '*')
										{
											cct_setcolor(11, real_mine[i / 3][j / 6] - '0');
											cout << real_mine[i / 3][j / 6];
											cct_setcolor(0, 7);
										}
										else
										{
											cct_setcolor(11, 9);
											cout << real_mine[i / 3][j / 6];
											cct_setcolor(0, 7);
										}
									}
									else
									{
										if (show_mine[i / 3][j / 6] != 'X' && real_mine[i / 3][j / 6] == '0')
										{
											cct_setcolor(11, 9);
											cout << " ";
											cct_setcolor(0, 7);
										}
										else
										{
											cct_setcolor(6, 9);
											cout << " ";
											cct_setcolor(0, 7);
										}
									}
								}
								else if (input == '8' || input == '9')
								{
									if (show_mine[i / 3][j / 6] != 'X' && real_mine[i / 3][j / 6] != '0')
									{
										if (real_mine[i / 3][j / 6] != '*')
										{
											cct_setcolor(11, real_mine[i / 3][j / 6] - '0');
											cout << real_mine[i / 3][j / 6];
											cct_setcolor(0, 7);
										}
										else
										{
											cct_setcolor(11, 9);
											cout << real_mine[i / 3][j / 6];
											cct_setcolor(0, 7);
										}
									}
									else
									{
										if (show_mine[i / 3][j / 6] != 'X' && real_mine[i / 3][j / 6] == '0')
										{
											cct_setcolor(11, 9);
											cout << " ";
											cct_setcolor(0, 7);
										}
										else if(show_mine[i / 3][j / 6] == 'X' && real_mine[i / 3][j / 6] == '0'&&sign_mine[i/3][j/6]!='#')
										{
											cct_setcolor(6, 9);
											cout << " ";
											cct_setcolor(0, 7);
										}
										else if (sign_mine[i / 3][j / 6] == '#')
										{
											cct_setcolor(4, 7);
											cout <<sign_mine[i/3][j/6];
											cct_setcolor(0, 7);
										}
										else
										{
											cct_setcolor(6, 9);
											cout << " ";
											cct_setcolor(0, 7);
										}
									}
								}
							}
							//cct_showch(i, j, real_mine[i/ 3][j/ 6], 7, 9, 1);
						}
						else
						{
							if (input == '7'||input=='5'||input=='6')
							{
								if (show_mine[i / 3][j / 6] == 'X' && input == '7')
								{
									cct_setcolor(6, 9);
									cout << " ";
									cct_setcolor(0, 7);
								}
								else if (show_mine[i / 3][j / 6] == 'X')
								{
									cct_setcolor(11, 9);
									cout << " ";
									cct_setcolor(0, 7);
								}
								else
								{
									cct_setcolor(11, 9);
									cout << " ";
									cct_setcolor(0, 7);
								}
							}
							else if (input == '8' || input == '9')
							{
								if (show_mine[i / 3][j / 6] == 'X'&&sign_mine[i/3][j/6]=='#')
								{
									cct_setcolor(4, 9);
									cout << " ";
									cct_setcolor(0, 7);
								}
								else if (show_mine[i / 3][j / 6] == 'X')
								{
									cct_setcolor(6, 9);
									cout << " ";
									cct_setcolor(0, 7);
								}
								else
								{
									cct_setcolor(11, 9);
									cout << " ";
									cct_setcolor(0, 7);
								}
							}
						}
						//cct_showch(i, j, ' ', 7, 9, 1);
					}
				}
			}
			cout << endl;
		}
	}
	cout << endl;


}

void title_page(char input,char pattern, int M, int N, int count)
{
	int i, j,Q;
	cct_cls();
	switch (pattern)
	{
		case '1':
			M = 9;
			N = 9;
			count = 10;
			break;
		case '2':
			M = 16;
			N = 16;
			count = 40;
			break;
		case '3':
			M = 16;
			N = 30;
			count = 99;
			break;
	}
	Q = count;
	//line1
	if (input != '7')
	{
		if (input == '9')
		{
			cout << "剩余雷数：" << Q << "，";
		}
		cout << "ESC退出";
		if (input == '8')
		{
			cout << endl;
		}
		if (input == '9')
		{
			cout << "，空格显示时间"<<endl;
		}
	}
	else
	{
		cout << endl;
	}
	//line2
	for (i = 0; i < N; i++)
	{
		if (i <= 9)
		{
			cout << "     " << i;
		}
		else
		{
			cout << "    " << i;
		}
	}
	cout << endl;
	//line3
	//cct_showch(i, j, '╔', 15, 9, 1);
	for (i = 0; i <= 3 * M; i++)
	{
		if (i % 3 == 2)
		{
			cout << char(i / 3 + 'A') << " ";
		}
		else
		{
			cout << "  ";
		}
		for (j = 0; j <= 6 * N; j++)
		{
			if (i % 3 == 0)
			{
				if (i == 0)//图形第一行
				{
					if (j == 0)
					{
						cct_setcolor(15, 9);
						cout << "╔";
						cct_setcolor(0, 7);
						//cct_showch(i, j, '╔', 15, 9, 1);
						j++;
					}
					else if (j == 6 * N)
					{
						cct_setcolor(15, 9);
						cout << "╗";
						cct_setcolor(0, 7);
						//cct_showch(i, j, '╗', 15, 9, 1);
						j++;
					}
					else if (j % 6 == 0)
					{
						cct_setcolor(15, 9);
						cout << "╦";
						cct_setcolor(0, 7);
						//cct_showch(i, j, '╦', 15, 9, 1);
						j++;
					}
					else
					{
						cct_setcolor(15, 9);
						cout << "═";
						cct_setcolor(0, 7);
						//cct_showch(i, j, '═', 15, 9, 1);
						j++;
					}
				}
				else if (i == 3 * M)//图形最后一行
				{
					if (j == 0)
					{
						cct_setcolor(15, 9);
						cout << "╚";
						cct_setcolor(0, 7);
						//cct_showch(i, j, '╚', 15, 9, 1);
						j++;
					}
					else if (j == 6 * N)
					{
						cct_setcolor(15, 9);
						cout << "╝";
						cct_setcolor(0, 7);
						//cct_showch(i, j, '╝', 15, 9, 1);
						j++;
					}
					else if (j % 6 == 0)
					{
						cct_setcolor(15, 9);
						cout << "╩";
						cct_setcolor(0, 7);
						//cct_showch(i, j, '╩', 15, 9, 1);
						j++;
					}
					else
					{
						cct_setcolor(15, 9);
						cout << "═";
						cct_setcolor(0, 7);
						//cct_showch(i, j, '═', 15, 9, 1);
						j++;
					}
				}
				else
				{
					if (j == 0)
					{
						cct_setcolor(15, 9);
						cout << "╠";
						cct_setcolor(0, 7);
						//cct_showch(i, j, '╠', 15, 9, 1);
						j++;
					}
					else if (j == 6 * N)
					{
						cct_setcolor(15, 9);
						cout << "╣";
						cct_setcolor(0, 7);
						//cct_showch(i, j, '╣', 15, 9, 1);
						j++;
					}
					else if (j % 6 == 0)
					{
						cct_setcolor(15, 9);
						cout << "╬";
						cct_setcolor(0, 7);
						//cct_showch(i, j, '╬', 15, 9, 1);
						j++;
					}
					else
					{
						cct_setcolor(15, 9);
						cout << "═";
						cct_setcolor(0, 7);
						//cct_showch(i, j, '═', 15, 9, 1);
						j++;
					}
				}
			}
			else
			{
				if (j % 6 == 0)
				{
					cct_setcolor(15, 9);
					cout << "║";
					cct_setcolor(0, 7);
					//cct_showch(i, j, '║', 15, 9, 1);
					j++;
				}
				else
				{
					cct_setcolor(6, 9);
					cout << " ";
					cct_setcolor(0, 7);

					//cct_showch(i, j, ' ', 7, 9, 1);
				}
			}
		}
		cout << endl;
	}
}

void sign(int x, int y, char real_mine[][30], char show_mine[][30], char sign_mine[][30])
{
	int i, j;
	i = 4 + 6 * x;
	j = 3 + 3 * y;
	cct_gotoxy(i, j);
	cct_setcolor(4, 7);
	cout << "    ";
	cct_gotoxy(i, j+1);
	cout << " #  ";
	cct_setcolor(0,7);
}

void clean(int x, int y, char real_mine[][30], char show_mine[][30], char sign_mine[][30])
{
	int i, j;
	i = 4 + 6 * x;
	j = 3 + 3 * y;
	cct_gotoxy(i, j);
	cct_setcolor(6, 7);
	cout << "    ";
	cct_gotoxy(i, j + 1);
	cout << "    ";
	cct_setcolor(0, 7);
}

void show(int x, int y, char real_mine[][30], char show_mine[][30], char sign_mine[][30])
{

	int i, j;
	i = 4 + 6 * x;
	j = 3 + 3 * y;
	cct_gotoxy(i, j);
	cct_setcolor(11, real_mine[y][x] - '0');
	cout << "    ";
	cct_gotoxy(i, j + 1);
	cout << " ";
	cout << real_mine[y][x] << "  ";
	cct_setcolor(0, 7);
}