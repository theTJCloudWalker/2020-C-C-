/* 2053285 罗斌江 信21 */
//menu及相关函数的实现
#include<iostream>
#include<conio.h>
#include<iomanip>
#include"mine_sweeper.h"
#include"cmd_console_tools.h"
using namespace std;

void degree_of_difficulty(char input, char real_mine[][30], char show_mine[][30], char sign_mine[][30])//难度选择
{
	cct_cls();
	cout << "请选择难度：" << endl;
	cout << "1.初级(9 * 9 - 10颗雷)"<<endl;
	cout << "2.中级(16 * 16 - 40颗雷)" << endl;
	cout << "3.高级(16 * 30 - 99颗雷)" << endl;
	cout << "请输入[1..3]：";
	char pattern,r='a';
	int M=0,N=0,c=0;
	int i = 0, j = 0, x = 0,y=0,count=0,m=0,n=0;
	int X = 0, Y = 0;
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int sum;
	while (1)
	{
		pattern = _getch();
		if (pattern < '1' || pattern> '3')
		{
			cct_gotoxy(14, 4);
			cout << " ";
			cct_gotoxy(14, 4);
			continue;
		}
		else
		{
			cct_gotoxy(14, 4);
		
				switch (pattern)
				{
					case '1':
						cct_setconsoleborder(59, 35);
						break;
					case '2':
						cct_setconsoleborder(102, 56);
						break;
					case '3':
						cct_setconsoleborder(185, 56);
						break;
				}

			cout << pattern;
			break;
		}
	}
	if (input == '1')
	{
		Real_mine(pattern, real_mine, show_mine);
		//Show_mine(input, pattern, real_mine, show_mine);
		output(input, pattern, real_mine, show_mine,sign_mine);
	}
	else if (input == '2' || input == '3' || input == '4')
	{
		choose_to_start(input,pattern, real_mine, show_mine,sign_mine);
	}
	else if (input == '5'||input=='6')
	{
		cct_cls();
		Real_mine(pattern, real_mine, show_mine);
		output2(input, pattern, real_mine, show_mine, sign_mine);
		if (input == '6')
		{
			switch (pattern)
			{
				case '1':
					M = 9;
					N = 9;
					break;
				case '2':
					M = 16;
					N = 16;
					break;
				case '3':
					M = 16;
					N = 30;
					break;
			}
			while (loop)
			{
				cct_enable_mouse();
				ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
				cct_gotoxy(0, 3 * M + 3);
				if (ret == CCT_MOUSE_EVENT)
				{
					//cct_gotoxy(0, M * 3 + 3);
					cout << "[当前光标] ";
					if (X % 6 == 3 || X % 6 == 2 || Y % 3 == 2 || X <= 2 || X >= N * 6 + 2 || Y <= 2 || Y >= M * 3 + 2)
					{
						cout << "位置非法  ";
					}
					else
					{
						if (maction == MOUSE_LEFT_BUTTON_CLICK)
						{
							cout << endl;
							break;
						}
						if (Y % 3 == 1)
						{
							switch (Y / 3)
							{
								case 1:
									r = 'A';
									break;
								case 2:
									r = 'B';
									break;
								case 3:
									r = 'C';
									break;
								case 4:
									r = 'D';
									break;
								case 5:
									r = 'E';
									break;
								case 6:
									r = 'F';
									break;
								case 7:
									r = 'G';
									break;
								case 8:
									r = 'H';
									break;
								case 9:
									r = 'I';
									break;
								case 10:
									r = 'J';
									break;
								case 11:
									r = 'K';
									break;
								case 12:
									r = 'L';
									break;
								case 13:
									r = 'M';
									break;
								case 14:
									r = 'N';
									break;
								case 15:
									r = 'O';
									break;
								case 16:
									r = 'P';
									break;

							}
						}
						else if ((Y + 1) % 3 == 1)
						{
							switch (Y / 3)
							{
								case 1:
									r = 'A';
									break;
								case 2:
									r = 'B';
									break;
								case 3:
									r = 'C';
									break;
								case 4:
									r = 'D';
									break;
								case 5:
									r = 'E';
									break;
								case 6:
									r = 'F';
									break;
								case 7:
									r = 'G';
									break;
								case 8:
									r = 'H';
									break;
								case 9:
									r = 'I';
									break;
								case 10:
									r = 'J';
									break;
								case 11:
									r = 'K';
									break;
								case 12:
									r = 'L';
									break;
								case 13:
									r = 'M';
									break;
								case 14:
									r = 'N';
									break;
								case 15:
									r = 'O';
									break;
								case 16:
									r = 'P';
									break;

							}
						}
						X -= 2;
						c = X / 6;
						cout << r << "行" << c << "列  ";
					}
				//cout << endl << "[当前光标] " << "行:" << X << " 列:" << setw(2) << Y;
				}
				else if (ret == CCT_KEYBOARD_EVENT)
				{
					continue;
				}
			}
		}
		pause(0);
	}
	else if (input == '7')
	{

	    title_page(input,pattern, M, N, count);
		//
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
		while (loop)
		{
			cct_enable_mouse();
			/* 读鼠标/键盘，返回值为下述操作中的某一种, 当前鼠标位置在<X,Y>处 */
			ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
			cct_gotoxy(0, 3 * M + 3);
			if (ret == CCT_MOUSE_EVENT)
			{
				/* 转到第7行进行打印 */
				//cct_gotoxy(0, M * 3 + 3);
				cout << "[当前光标] ";
				if (X % 6 == 3 || X % 6 == 2 || Y % 3 == 2 || X <= 2 || X >= N * 6 + 2 || Y <= 2 || Y >= M * 3 + 2)
				{
					cout << "位置非法  ";
				}
				else
				{
					if (maction == MOUSE_LEFT_BUTTON_CLICK)
					{
						if (Y % 3 == 1)
						{
							switch (Y / 3)
							{
								case 1:
									r = 'A';
									x = 0;
									break;
								case 2:
									r = 'B';
									x = 1;
									break;
								case 3:
									r = 'C';
									x = 2;
									break;
								case 4:
									r = 'D';
									x = 3;
									break;
								case 5:
									r = 'E';
									x = 4;
									break;
								case 6:
									r = 'F';
									x = 5;
									break;
								case 7:
									r = 'G';
									x = 6;
									break;
								case 8:
									r = 'H';
									x = 7;
									break;
								case 9:
									r = 'I';
									x = 8;
									break;
								case 10:
									r = 'J';
									x = 9;
									break;
								case 11:
									r = 'K';
									x = 10;
									break;
								case 12:
									r = 'L';
									x = 11;
									break;
								case 13:
									r = 'M';
									x = 12;
									break;
								case 14:
									r = 'N';
									x = 13;
									break;
								case 15:
									r = 'O';
									x = 14;
									break;
								case 16:
									r = 'P';
									x = 15;
									break;

							}
						}
						else if ((Y + 1) % 3 == 1)
						{
							switch (Y / 3)
							{
								case 1:
									r = 'A';
									x = 0;
									break;
								case 2:
									r = 'B';
									x = 1;
									break;
								case 3:
									r = 'C';
									x = 2;
									break;
								case 4:
									r = 'D';
									x = 3;
									break;
								case 5:
									r = 'E';
									x = 4;
									break;
								case 6:
									r = 'F';
									x = 5;
									break;
								case 7:
									r = 'G';
									x = 6;
									break;
								case 8:
									r = 'H';
									x = 7;
									break;
								case 9:
									r = 'I';
									x = 8;
									break;
								case 10:
									r = 'J';
									x = 9;
									break;
								case 11:
									r = 'K';
									x = 10;
									break;
								case 12:
									r = 'L';
									x = 11;
									break;
								case 13:
									r = 'M';
									x = 12;
									break;
								case 14:
									r = 'N';
									x = 13;
									break;
								case 15:
									r = 'O';
									x = 14;
									break;
								case 16:
									r = 'P';
									x = 15;
									break;

							}
						}
						X -= 2;
						c = X / 6;
						X += 2;
						switch (r)
						{
							case 'A':
								x = 0;
								break;
							case  'B':
								x = 1;
								break;
							case 'C':
								x = 2;
								break;
							case 'D':
								x = 3;
								break;
							case 'E':
								x = 4;
								break;
							case 'F':
								x = 5;
								break;
							case 'G':
								x = 6;
								break;
							case 'H':
								x = 7;
								break;
							case 'I':
								x = 8;
								break;
							case 'J':
								x = 9;
								break;
							case 'K':
								x = 10;
								break;
							case 'L':
								x = 11;
								break;
							case 'M':
								x = 12;
								break;
							case 'N':
								x = 13;
								break;
							case 'O':
								x = 14;
								break;
							case 'P':
								x = 15;
								break;
						}
						y = c;
						m = x;
						n = c;
						real_mine[m][n] = '0';
						//cout << i << "*" << j;
						//getchar();
						//埋雷
						//cout << X << "$" << Y << endl;
						while (count)
						{
							cout << count << "*";
							x = rand() % (M - 1);
							y = rand() % (N - 1);
							if (real_mine[x][y] == '0')
								continue;
							if (x - 1 >= 0 && y - 1 >= 0 && real_mine[x - 1][y - 1] == '0')
								continue;
							if (x - 1 >= 0 && real_mine[x - 1][y] == '0')
								continue;
							if (real_mine[x - 1][y + 1] == '0' && x - 1 >= 0 && y + 1 < Y)
								continue;
							if (y - 1 >= 0 && real_mine[x][y - 1] == '0')
								continue;
							if (real_mine[x][y + 1] == '0' && y + 1 < Y)
								continue;
							if (x + 1 < X && y - 1 >= 0 && real_mine[x + 1][y - 1] == '0')
								continue;
							if (real_mine[x + 1][y] == '0' && x + 1 < X)
								continue;
							if (real_mine[x + 1][y + 1] == '0' && x + 1 < X && y + 1 < Y)
								continue;
							real_mine[x][y] = '*';
							count--;
						}
						//count mine
						for (i = 0; i < M; i++)
						{
							for (j = 0; j < N; j++)
							{
								if (real_mine[i][j] != '*')
								{
									count = 0;
									if (i - 1 >= 0 && j - 1 >= 0 && real_mine[i - 1][j - 1] == '*')
									{
										count++;
									}
									if (i - 1 >= 0 && real_mine[i - 1][j] == '*')
									{
										count++;
									}
									if (real_mine[i - 1][j + 1] == '*' && i - 1 >= 0 && j + 1 <= Y)
									{
										count++;
									}
									if (j - 1 >= 0 && real_mine[i][j - 1] == '*')
									{
										count++;
									}
									if (real_mine[i][j + 1] == '*' && j + 1 <= Y)
									{
										count++;
									}
									if (i + 1 <= 9 && j - 1 >= 0 && real_mine[i + 1][j - 1] == '*')
									{
										count++;
									}
									if (real_mine[i + 1][j] == '*' && i + 1 <= X)
									{
										count++;
									}
									if (real_mine[i + 1][j + 1] == '*' && i + 1 <= X && j + 1 <= Y)
									{
										count++;
									}
									real_mine[i][j] = count + '0';
								}
							}
						}
						open_the_map(input, pattern, real_mine, show_mine, m, n, sign_mine);
						
						cct_cls();
						output2(input, pattern, real_mine, show_mine, sign_mine);
						cout << "[当前光标] " << r << "行" << c << "列  " << endl << endl;
						pause(0);
						return;
					}
					else
					{
					    if (Y % 3 == 1)
					    {
							switch (Y / 3)
							{
								case 1:
									r = 'A';
									break;
								case 2:
									r = 'B';
									break;
								case 3:
									r = 'C';
									break;
								case 4:
									r = 'D';
									break;
								case 5:
									r = 'E';
									break;
								case 6:
									r = 'F';
									break;
								case 7:
									r = 'G';
									break;
								case 8:
									r = 'H';
									break;
								case 9:
									r = 'I';
									break;
								case 10:
									r = 'J';
									break;
								case 11:
									r = 'K';
									break;
								case 12:
									r = 'L';
									break;
								case 13:
									r = 'M';
									break;
								case 14:
									r = 'N';
									break;
								case 15:
									r = 'O';
									break;
								case 16:
									r = 'P';
									break;

							}
					    }
						else if ((Y + 1) % 3 == 1)
						{
							switch (Y / 3)
							{
								case 1:
									r = 'A';
									break;
								case 2:
									r = 'B';
									break;
								case 3:
									r = 'C';
									break;
								case 4:
									r = 'D';
									break;
								case 5:
									r = 'E';
									break;
								case 6:
									r = 'F';
									break;
								case 7:
									r = 'G';
									break;
								case 8:
									r = 'H';
									break;
								case 9:
									r = 'I';
									break;
								case 10:
									r = 'J';
									break;
								case 11:
									r = 'K';
									break;
								case 12:
									r = 'L';
									break;
								case 13:
									r = 'M';
									break;
								case 14:
									r = 'N';
									break;
								case 15:
									r = 'O';
									break;
								case 16:
									r = 'P';
									break;

							}
						}
					    X -= 2;
				    	c = X / 6;
					}
					cout << r << "行" << c << "列  ";
					
				}

				//cout <<endl<< "[当前光标] "<<"行:" << X<< " 列:" << setw(2) << Y ;
			}
		}
		//pause(0);
	}
	else if (input == '8' || input == '9')
	{
	title_page(input, pattern, M, N, count);
	//
	int Q;
	clock_t start;
	start = clock();
	switch (pattern)
	{
		case '1':
			M = 9;
			N = 9;
			count = 10;
			Q = 10;
			break;
		case '2':
			M = 16;
			N = 16;
			count = 40;
			Q = 40;
			break;
		case '3':
			M = 16;
			N = 30;
			count = 99;
			Q = 99;
			break;
	}
	while (loop)
	{
		cct_enable_mouse();
		/* 读鼠标/键盘，返回值为下述操作中的某一种, 当前鼠标位置在<X,Y>处 */
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
		cct_gotoxy(0, 3 * M + 3);
		if (ret == CCT_MOUSE_EVENT)
		{
			cout << "[当前光标] ";
			if (X % 6 == 3 || X % 6 == 2 || Y % 3 == 2 || X <= 2 || X >= N * 6 + 2 || Y <= 2 || Y >= M * 3 + 2)
			{
				cout << "位置非法  ";
			}
			else
			{
				if (Y % 3 == 1)
				{
					switch (Y / 3)
					{
						case 1:
							r = 'A';
							x = 0;
							break;
						case 2:
							r = 'B';
							x = 1;
							break;
						case 3:
							r = 'C';
							x = 2;
							break;
						case 4:
							r = 'D';
							x = 3;
							break;
						case 5:
							r = 'E';
							x = 4;
							break;
						case 6:
							r = 'F';
							x = 5;
							break;
						case 7:
							r = 'G';
							x = 6;
							break;
						case 8:
							r = 'H';
							x = 7;
							break;
						case 9:
							r = 'I';
							x = 8;
							break;
						case 10:
							r = 'J';
							x = 9;
							break;
						case 11:
							r = 'K';
							x = 10;
							break;
						case 12:
							r = 'L';
							x = 11;
							break;
						case 13:
							r = 'M';
							x = 12;
							break;
						case 14:
							r = 'N';
							x = 13;
							break;
						case 15:
							r = 'O';
							x = 14;
							break;
						case 16:
							r = 'P';
							x = 15;
							break;

					}
				}
				else if ((Y + 1) % 3 == 1)
				{
					switch (Y / 3)
					{
						case 1:
							r = 'A';
							x = 0;
							break;
						case 2:
							r = 'B';
							x = 1;
							break;
						case 3:
							r = 'C';
							x = 2;
							break;
						case 4:
							r = 'D';
							x = 3;
							break;
						case 5:
							r = 'E';
							x = 4;
							break;
						case 6:
							r = 'F';
							x = 5;
							break;
						case 7:
							r = 'G';
							x = 6;
							break;
						case 8:
							r = 'H';
							x = 7;
							break;
						case 9:
							r = 'I';
							x = 8;
							break;
						case 10:
							r = 'J';
							x = 9;
							break;
						case 11:
							r = 'K';
							x = 10;
							break;
						case 12:
							r = 'L';
							x = 11;
							break;
						case 13:
							r = 'M';
							x = 12;
							break;
						case 14:
							r = 'N';
							x = 13;
							break;
						case 15:
							r = 'O';
							x = 14;
							break;
						case 16:
							r = 'P';
							x = 15;
							break;

					}
				}
				X -= 2;
				c = X / 6;
				X += 2;
				switch (r)
				{
					case 'A':
						x = 0;
						break;
					case  'B':
						x = 1;
						break;
					case 'C':
						x = 2;
						break;
					case 'D':
						x = 3;
						break;
					case 'E':
						x = 4;
						break;
					case 'F':
						x = 5;
						break;
					case 'G':
						x = 6;
						break;
					case 'H':
						x = 7;
						break;
					case 'I':
						x = 8;
						break;
					case 'J':
						x = 9;
						break;
					case 'K':
						x = 10;
						break;
					case 'L':
						x = 11;
						break;
					case 'M':
						x = 12;
						break;
					case 'N':
						x = 13;
						break;
					case 'O':
						x = 14;
						break;
					case 'P':
						x = 15;
						break;
				}
				y = c;
				m = x;
				n = c;
				if (maction == MOUSE_LEFT_BUTTON_CLICK&&sign_mine[x][c]!='#')
				{
					real_mine[m][n] = '0';
					//cout << i << "*" << j;
					//getchar();
					//埋雷
					//cout << X << "$" << Y << endl;
					while (count)
					{
						//cout << count << "*";
						x = rand() % (M - 1);
						y = rand() % (N - 1);
						if (real_mine[x][y] == '0')
						{
							continue;
						}
						else if (x - 1 >= 0 && y - 1 >= 0 && real_mine[x - 1][y - 1] == '0')
						{
							continue;
						}
						else if (x - 1 >= 0 && real_mine[x - 1][y] == '0')
						{
							continue;
						}
						else if (real_mine[x - 1][y + 1] == '0' && x - 1 >= 0 && y + 1 <= Y)
						{
							continue;
						}
						else if (y - 1 >= 0 && real_mine[x][y - 1] == '0')
						{
							continue;
						}
						else if (real_mine[x][y + 1] == '0' && y + 1 <= Y)
						{
							continue;
						}
						else if (x + 1 <= 9 && y - 1 >= 0 && real_mine[x + 1][y - 1] == '0')
						{
							continue;
						}
						else if (real_mine[x + 1][y] == '0' && x + 1 <= X)
						{
							continue;
						}
						else if (real_mine[x + 1][y + 1] == '0' && x + 1 <= X && y + 1 <= Y)
						{
							continue;
						}
						else
						{
							real_mine[x][y] = '*';
							count--;
						}
					}
					//count mine
					for (i = 0; i < M; i++)
					{
						for (j = 0; j < N; j++)
						{
							if (real_mine[i][j] != '*')
							{
								count = 0;
								if (i - 1 >= 0 && j - 1 >= 0 && real_mine[i - 1][j - 1] == '*')
									count++;
								if (i - 1 >= 0 && real_mine[i - 1][j] == '*')
									count++;
								if (real_mine[i - 1][j + 1] == '*' && i - 1 >= 0 && j + 1 < N)
									count++;
								if (j - 1 >= 0 && real_mine[i][j - 1] == '*')
									count++;
								if (real_mine[i][j + 1] == '*' && j + 1 < N)
									count++;
								if (i + 1 < M && j - 1 >= 0 && real_mine[i + 1][j - 1] == '*')
									count++;
								if (real_mine[i + 1][j] == '*' && i + 1 < M)
									count++;
								if (real_mine[i + 1][j + 1] == '*' && i + 1 < M && j + 1 < N)
									count++;
								real_mine[i][j] = count + '0';
							}
						}
					}
					open_the_map(input, pattern, real_mine, show_mine, m, n, sign_mine);
					
					cct_cls();
					cct_gotoxy(0, 0);
					if (input == '9')
					{
						cout << "剩余雷数：" << Q << "，";
					}
					cout << "ESC退出";
					if (input == '9')
					{
						cout << "，空格显示时间";
					}
					output2(input, pattern, real_mine, show_mine, sign_mine);
					//cout << "[当前光标] " << r << "行" << c << "列  " << endl << endl;
					while (loop)
					{
						sum = 0;
						for (i = 0; i < M; i++)
						{
							for (j = 0; j < N; j++)
							{
								if (show_mine[i][j] == 'X')
								{
									sum++;
								}
							}
						}
						if (sum == 10)
						{
							clock_t finish;
							finish = clock();
							cct_gotoxy(0, 3 * M + 3);
							cct_setcolor(0, 6);
							cout << "共用时：" << setiosflags(ios::fixed) << setprecision(6) << ((double)finish - (double)start) / CLOCKS_PER_SEC << "秒，";
							cct_setcolor(0, 7);
							cout<< "恭喜你，游戏结束" << endl;
							pause(0);
							return;
						}
						/* 读鼠标/键盘，返回值为下述操作中的某一种, 当前鼠标位置在<X,Y>处 */
						ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
						if (ret == CCT_MOUSE_EVENT)
						{
							cct_gotoxy(0, 3 * M + 3);
							cout << "[当前光标] ";
							if (X % 6 == 3 || X % 6 == 2 || Y % 3 == 2 || X <= 2 || X >= N * 6 + 2 || Y <= 2 || Y >= M * 3 + 2)
							{
								cout << "位置非法  ";
							}
							else
							{
								if (Y % 3 == 1)
								{
									switch (Y / 3)
									{
										case 1:
											r = 'A';
											x = 0;
											break;
										case 2:
											r = 'B';
											x = 1;
											break;
										case 3:
											r = 'C';
											x = 2;
											break;
										case 4:
											r = 'D';
											x = 3;
											break;
										case 5:
											r = 'E';
											x = 4;
											break;
										case 6:
											r = 'F';
											x = 5;
											break;
										case 7:
											r = 'G';
											x = 6;
											break;
										case 8:
											r = 'H';
											x = 7;
											break;
										case 9:
											r = 'I';
											x = 8;
											break;
										case 10:
											r = 'J';
											x = 9;
											break;
										case 11:
											r = 'K';
											x = 10;
											break;
										case 12:
											r = 'L';
											x = 11;
											break;
										case 13:
											r = 'M';
											x = 12;
											break;
										case 14:
											r = 'N';
											x = 13;
											break;
										case 15:
											r = 'O';
											x = 14;
											break;
										case 16:
											r = 'P';
											x = 15;
											break;

									}
								}
								else if ((Y + 1) % 3 == 1)
								{
									switch (Y / 3)
									{
										case 1:
											r = 'A';
											x = 0;
											break;
										case 2:
											r = 'B';
											x = 1;
											break;
										case 3:
											r = 'C';
											x = 2;
											break;
										case 4:
											r = 'D';
											x = 3;
											break;
										case 5:
											r = 'E';
											x = 4;
											break;
										case 6:
											r = 'F';
											x = 5;
											break;
										case 7:
											r = 'G';
											x = 6;
											break;
										case 8:
											r = 'H';
											x = 7;
											break;
										case 9:
											r = 'I';
											x = 8;
											break;
										case 10:
											r = 'J';
											x = 9;
											break;
										case 11:
											r = 'K';
											x = 10;
											break;
										case 12:
											r = 'L';
											x = 11;
											break;
										case 13:
											r = 'M';
											x = 12;
											break;
										case 14:
											r = 'N';
											x = 13;
											break;
										case 15:
											r = 'O';
											x = 14;
											break;
										case 16:
											r = 'P';
											x = 15;
											break;

									}
								}
								X -= 2;
								c = X / 6;
								if (maction == MOUSE_LEFT_BUTTON_CLICK&&sign_mine[x][c]!='#')
								{
									if (show_mine[x][c] == 'X' && sign_mine[x][c] != '#'&& real_mine[x][c] != '*')
									{
										if (real_mine[x][c] == '0')
										{
											open_the_map(input, pattern, real_mine, show_mine, x, c, sign_mine);
											cct_cls();
											cct_gotoxy(0, 0);
											if (input == '9')
											{
												cout << "剩余雷数：" << Q << "，";
											}
											cout << "ESC退出";
											if (input == '9')
											{
												cout << "，空格显示时间";
											}
											output2(input, pattern, real_mine, show_mine, sign_mine);
										}
										else
										{
											show_mine[x][c] = real_mine[x][c];
											
											cct_gotoxy(0, 0);
											if (input == '9')
											{
												cout << "剩余雷数：" << Q << "，";
											}
											cout << "ESC退出";
											if (input == '9')
											{
												cout << "，空格显示时间";
											}
											show(c, x, real_mine, show_mine, sign_mine);
										}
									}
									else if (real_mine[x][c] == '*')
									{
										open_the_map(input, pattern, real_mine, show_mine, x, c, sign_mine);
										cct_cls();
										cct_gotoxy(0, 0);
										if (input == '9')
										{
											cout << "剩余雷数：" << Q << "，";
										}
										cout << "ESC退出";
										if (input == '9')
										{
											cout << "，空格显示时间";
										}
										output2(input, pattern, real_mine, show_mine, sign_mine);
										clock_t finish;
										finish = clock();
										cct_setcolor(0, 6);
										cout << "共用时：" << setiosflags(ios::fixed) << setprecision(6) << ((double)finish - (double)start) / CLOCKS_PER_SEC << "秒，";
										cct_setcolor(0, 7);
										cout<< "你输了，游戏结束" << endl;
										pause(0);
										return;
									}  
								}
								else if (maction == MOUSE_RIGHT_BUTTON_CLICK)
								{
									if (show_mine[x][c] == 'X' && sign_mine[x][c] != '#')
									{

										if (Q > 0)
										{
											Q--;
										}
										sign_mine[x][c] = '#';
										cct_gotoxy(0, 0);
										if (input == '9')
										{
											cout << "剩余雷数：" << Q << "，";
										}
										cout << "ESC退出";
										if (input == '9')
										{
											cout << "，空格显示时间";
										}
										sign(c, x, real_mine, show_mine, sign_mine);
									}
									else if (show_mine[x][c] == 'X' && sign_mine[x][c] == '#')
									{
										Q++;
										sign_mine[x][c] = 'X';
										cct_gotoxy(0, 0);
										if (input == '9')
										{
											cout << "剩余雷数：" << Q << "，";
										}
										cout << "ESC退出";
										if (input == '9')
										{
											cout << "，空格显示时间" ;
										}
										clean(c, x, real_mine, show_mine, sign_mine);
									}
								}
								else
								{
									cout << r << "行" << c << "列  " << endl << endl;
								}
							}
						}
						else if (ret == CCT_KEYBOARD_EVENT)
						{
							switch (keycode1) {
								case 27:	//ESC键
									cout << endl;
									pause(0);
									return;
								case 32:	//SPACE键
									if (input == '9')
									{
										clock_t finish;
										finish = clock();
										cct_gotoxy(0, 0);
										cct_setcolor(0, 6);
										cout << "当前时间：" << setiosflags(ios::fixed) << setprecision(6) << ((double)finish - (double)start) / CLOCKS_PER_SEC << "秒，";
										cct_setcolor(0, 7);
										cout<< "ESC退出，空格显示时间";
									}
									//time
									break;
							}
						}

					}
				}
				else if (maction == MOUSE_RIGHT_BUTTON_CLICK)
				{
					if (Y % 3 == 1)
					{
						switch (Y / 3)
						{
							case 1:
								r = 'A';
								x = 0;
								break;
							case 2:
								r = 'B';
								x = 1;
								break;
							case 3:
								r = 'C';
								x = 2;
								break;
							case 4:
								r = 'D';
								x = 3;
								break;
							case 5:
								r = 'E';
								x = 4;
								break;
							case 6:
								r = 'F';
								x = 5;
								break;
							case 7:
								r = 'G';
								x = 6;
								break;
							case 8:
								r = 'H';
								x = 7;
								break;
							case 9:
								r = 'I';
								x = 8;
								break;
							case 10:
								r = 'J';
								x = 9;
								break;
							case 11:
								r = 'K';
								x = 10;
								break;
							case 12:
								r = 'L';
								x = 11;
								break;
							case 13:
								r = 'M';
								x = 12;
								break;
							case 14:
								r = 'N';
								x = 13;
								break;
							case 15:
								r = 'O';
								x = 14;
								break;
							case 16:
								r = 'P';
								x = 15;
								break;

						}
					}
					else if ((Y + 1) % 3 == 1)
					{
						switch (Y / 3)
						{
							case 1:
								r = 'A';
								x = 0;
								break;
							case 2:
								r = 'B';
								x = 1;
								break;
							case 3:
								r = 'C';
								x = 2;
								break;
							case 4:
								r = 'D';
								x = 3;
								break;
							case 5:
								r = 'E';
								x = 4;
								break;
							case 6:
								r = 'F';
								x = 5;
								break;
							case 7:
								r = 'G';
								x = 6;
								break;
							case 8:
								r = 'H';
								x = 7;
								break;
							case 9:
								r = 'I';
								x = 8;
								break;
							case 10:
								r = 'J';
								x = 9;
								break;
							case 11:
								r = 'K';
								x = 10;
								break;
							case 12:
								r = 'L';
								x = 11;
								break;
							case 13:
								r = 'M';
								x = 12;
								break;
							case 14:
								r = 'N';
								x = 13;
								break;
							case 15:
								r = 'O';
								x = 14;
								break;
							case 16:
								r = 'P';
								x = 15;
								break;

						}
					}
					X -= 2;
					c = X / 6;
					X += 2;
					if (show_mine[x][c] == 'X' && sign_mine[x][c] != '#')
					{

						sign_mine[x][c] = '#';
						cct_gotoxy(0, 0);
						if (input == '9')
						{
							cout << "剩余雷数：" << Q << "，";
						}
						cout << "ESC退出";
						if (input == '9')
						{
							cout << "，空格显示时间";
						}
						sign(c, x, real_mine, show_mine, sign_mine);
					}
					else if (show_mine[x][c] == 'X' && sign_mine[x][c] == '#')
					{
						sign_mine[x][c] = 'X';
						cct_gotoxy(0, 0);
						if (input == '9')
						{
							cout << "剩余雷数：" << Q << "，";
						}
						cout << "ESC退出";
						if (input == '9')
						{
							cout << "，空格显示时间";
						}
						clean(c, x, real_mine, show_mine, sign_mine);
					}
					cct_gotoxy(11, 3 * M + 3);
					cout << r << "行" << c << "列  ";
				}
				else
				{
					if (Y % 3 == 1)
					{
						switch (Y / 3)
						{
							case 1:
								r = 'A';
								break;
							case 2:
								r = 'B';
								break;
							case 3:
								r = 'C';
								break;
							case 4:
								r = 'D';
								break;
							case 5:
								r = 'E';
								break;
							case 6:
								r = 'F';
								break;
							case 7:
								r = 'G';
								break;
							case 8:
								r = 'H';
								break;
							case 9:
								r = 'I';
								break;
							case 10:
								r = 'J';
								break;
							case 11:
								r = 'K';
								break;
							case 12:
								r = 'L';
								break;
							case 13:
								r = 'M';
								break;
							case 14:
								r = 'N';
								break;
							case 15:
								r = 'O';
								break;
							case 16:
								r = 'P';
								break;

						}
					}
					else if ((Y + 1) % 3 == 1)
					{
						switch (Y / 3)
						{
							case 1:
								r = 'A';
								break;
							case 2:
								r = 'B';
								break;
							case 3:
								r = 'C';
								break;
							case 4:
								r = 'D';
								break;
							case 5:
								r = 'E';
								break;
							case 6:
								r = 'F';
								break;
							case 7:
								r = 'G';
								break;
							case 8:
								r = 'H';
								break;
							case 9:
								r = 'I';
								break;
							case 10:
								r = 'J';
								break;
							case 11:
								r = 'K';
								break;
							case 12:
								r = 'L';
								break;
							case 13:
								r = 'M';
								break;
							case 14:
								r = 'N';
								break;
							case 15:
								r = 'O';
								break;
							case 16:
								r = 'P';
								break;

						}
					}
					X -= 2;
					c = X / 6;
					cout << r << "行" << c << "列  ";
				}
				

			}

			//cout <<endl<< "[当前光标] "<<"行:" << X<< " 列:" << setw(2) << Y ;
		}
		else if (ret == CCT_KEYBOARD_EVENT)
		{
			switch (keycode1) {
				case 27:	//ESC键
					cout << endl;
					pause(0);
					return;
				case 32:	//SPACE键
					if (input == '9')
					{
						clock_t finish;
						finish = clock();
						cct_gotoxy(0, 0);
						cct_setcolor(0, 6);
						cout << "当前时间：" << setiosflags(ios::fixed) << setprecision(6) << ((double)finish - (double)start) / CLOCKS_PER_SEC << "秒，";
						cct_setcolor(0, 7);
						cout << "ESC退出，空格显示时间";
					}
					//time
					break;
			}
		}
	}
	}
}

void mine_sweeper_menu(char real_mine[][30], char show_mine[][30], char sign_mine[][30])//菜单
{
	cout << "------------------------------------------" << endl;
	cout << "1.选择难度并显示内部数组" << endl;
	cout << "2.输入初始位置并显示被打开的初始区域" << endl;
	cout << "3.内部数组基础版" << endl;
	cout << "4.内部数组完整版（标记、运行时间）" << endl;
	cout << "5.画出伪图形化框架并显示内部数据" << endl;
	cout << "6.检测鼠标位置和合法性（左键单击退出）" << endl;
	cout << "7.鼠标选择初始位置并显示被打开的初始区域" << endl;
	cout << "8.伪图形界面基础版" << endl;
	cout << "9.伪图形界面完整版" << endl;
	cout << "0.退出游戏" << endl;
	cout << "------------------------------------------" << endl;
	cout << "[请选择] : ";
	char input;
	int i, j;
	while (1)
	{
		input = _getch();
		if (input < '0' || input> '9')
		{
			cct_gotoxy(11, 12);
			cout << " ";
			cct_gotoxy(11, 12);
			continue;
		}
		else
		{
			cct_gotoxy(11, 12);
			cout << input;
			break;
		}
	}
	if (input != '0')
	{
		degree_of_difficulty(input, real_mine, show_mine, sign_mine);
		cct_cls();
		for (i = 0; i < 16; i++)
		{
			for (j = 0; j < 30; j++)
			{
				real_mine[i][j] = ' ';
				show_mine[i][j] = 'X';
				sign_mine[i][j] = 'X';
			}
		}
		mine_sweeper_menu(real_mine, show_mine, sign_mine);
	}
	else
	{
		return;
	}
}