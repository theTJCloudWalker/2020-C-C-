/* 2053285 罗斌江 信21 */
//内部数组版的相关函数的实现
#include<iostream>
#include<conio.h>
#include <time.h>
#include<iomanip>
#include"mine_sweeper.h"
#include"cmd_console_tools.h"


using namespace std;

//按回车键继续
void pause(int speed)
{
	switch (speed)
	{
		case 0:
			cout << "按回车键继续...";
			while (_getch() != '\r')
				;
			break;
	}
}

int input_judge1(char input,char pattern, char real_mine[][30], char show_mine[][30],long start, char sign_mine[][30])
{
	int x=0,y=0, count,temp, X = 0, Y = 0;
	clock_t finish;
	char row, c,r;
	switch (pattern)
	{
		case '1':
			X = 9;
			Y = 9;
			count = 10;
			break;
		case '2':
			X = 16;
			Y = 16;
			count = 40;
			break;
		case '3':
			X = 16;
			Y = 30;
			count = 99;
			break;
	}
	temp = 1;
	if (input == '4')
	{
		cout << "特殊输入说明：& - 游戏已运行时间(单字符即可，不需要加坐标)" << endl;
		cout << "              !- 标记该坐标为雷(例：!E3)" << endl;
		cout << "              # - 取消标记      (例：#E3)" << endl;
	}
	cout << "输入非雷位置的行列坐标（先行后列，严格区分大小写，例：G1/Af，按Q/q退出）：";
	while (temp)
	{
		row = _getch();
		if ((row >= 'A' && row <= 'A' + X)||row=='!'||row=='#')
		{
			temp = 0;
			cout << row;
		}
		else if (row == 'q' || row == 'Q')
		{
			cout << endl;
			pause(0);
			break;
		}
		else if (row == '&'&&input=='4')
		{
			cout << row;
			finish = clock();
			cout << endl << "已运行时间：" <<setiosflags(ios::fixed)<<setprecision(2)<<((double)finish - (double)start) / CLOCKS_PER_SEC << "秒" << endl;
			//input_judge1(input,pattern,real_mine, show_mine, start);
			return 3;
		}
	}
	temp = 1;
	if (row != 'q' && row != 'Q')
	{
		if (row != '!' && row != '#')
		{
			while (temp)
			{
				c = _getch();
				if (c >= '1' && c <= '9')
				{
					temp = 0;
					cout << c;
				}
				else if (X > 9)
				{
					if (c >= 'a' && c <= 'a' + Y)
					{
						temp = 0;
						cout << c;
					}
				}
			}
			x = row - 65;
			if (c >= '1' && c <= '9')
			{
				y = c - '1';
			}
			else
			{
				y = c - 'a' + 9;
			}
			//cout << x << " " << y << endl;
			open_the_map(input, pattern, real_mine, show_mine, x, y, sign_mine);
			if (x>=0&&y>=0&&real_mine[x][y] == '*'&&sign_mine[x][y]!='x')
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		else
		{
			if (row == '!')
			{
				while (temp)
				{
					r = _getch();
					if (r >= 'A' && r <= 'A' + X)
					{
						temp = 0;
						cout << r;
					}
				}
				temp = 1;
				while (temp)
				{
					c = _getch();
					if (c >= '1' && c <= '9')
					{
						temp = 0;
						cout << c;
					}
					else if (X > 9)
					{
						if (c >= 'a' && c <= 'a' + Y)
						{
							temp = 0;
							cout << c;
						}
					}
				}
				x = r - 65;
				if (c >= '1' && c <= '9')
				{
					y = c - '1';
				}
				else
				{
					y = c - 'a' + 9;
				}
				if (x >= 0 && y >= 0 && show_mine[x][y] == 'X')
				{
					sign_mine[x][y] = 'x';
				}//OPEN\OUTPUT
				return 1;
			}
			else if(row=='#')
			{
				while (temp)
				{
					r = _getch();
					if (r >= 'A' && r <= 'A' + X)
					{
						temp = 0;
						cout << r;
					}
				}
				temp = 1;
				while (temp)
				{
					c = _getch();
					if (c >= '1' && c <= '9')
					{
						temp = 0;
						cout << c;
					}
					else if (X > 9)
					{
						if (c >= 'a' && c <= 'a' + Y)
						{
							temp = 0;
							cout << c;
						}
					}
				}
				x = r - 65;
				if (c >= '1' && c <= '9')
				{
					y = c - '1';
				}
				else
				{
					y = c - 'a' + 9;
				}
				if (x >= 0 && y >= 0 && sign_mine[x][y] == 'x')
				{
					sign_mine[x][y] = 'X';
				}//OPEN\OUTPUT
				return 1;
			}
		}
	}
	return 2;
}

int input_judge(char input,char pattern, char real_mine[][30], char show_mine[][30],long start, char sign_mine[][30])
{
	//初始化
	int temp,i, j,m,n,count,x=0,y=0, X = 0, Y = 0;
	clock_t finish;
	char row,c,r;
	temp = 1;
	switch (pattern)
	{
		case '1':
			X = 9;
			Y = 9;
			count = 10;
			break;
		case '2':
			X = 16;
			Y = 16;
			count = 40;
			break;
		case '3':
			X = 16;
			Y = 30;
			count = 99;
			break;
	}
	if (input == '4')
	{
		cout << "特殊输入说明：& - 游戏已运行时间(单字符即可，不需要加坐标)" << endl;
		cout << "              !- 标记该坐标为雷(例：!E3)" << endl;
		cout << "              # - 取消标记      (例：#E3)" << endl;
	}
	cout << "输入非雷位置的行列坐标（先行后列，严格区分大小写，例：G1/Af，按Q/q退出）：";
	while (temp)
	{
		row = _getch();
		if (row >= 'A' && row <= 'A' + X)
		{
			temp = 0;
			cout << row;
		}
		else if (row == 'q' || row == 'Q')
		{
			cout << endl;
			pause(0);
			break;
		}
		else if (row == '&' && input == '4')
		{
			finish = clock();
			cout << endl << "已运行时间：" << setiosflags(ios::fixed) << setprecision(2) << ((double)finish - (double)start) / CLOCKS_PER_SEC << "秒" << endl;
			//input_judge1(input,pattern,real_mine, show_mine, start);
			return 3;
		}
		else if (row == '!' || row == '#')
		{
			temp = 0;
			cout << row;
		}
	}
	temp = 1;
	if (row != 'q' && row != 'Q')
	{
		if (row != '!' && row != '#')
		{
			while (temp)
			{
				c = _getch();
				if (c >= '1' && c <= '9')
				{
					temp = 0;
					cout << c;
				}
				else if (X > 9)
				{
					if (c >= 'a' && c <= 'a' + Y)
					{
						temp = 0;
						cout << c;
					}
				}
			}

			x = row - 65;
			i = x;
			m = x;
			if (c >= '1' && c <= '9')
			{
				y = c - '1';
			}
			else
			{
				y = c - 'a' + 9;
			}
			j = y;
			n = y;
			real_mine[x][y] = '0';
			//cout << i << "*" << j;
			//getchar();
			//埋雷
			while (count)
			{
				x = rand() % (X - 1);
				y = rand() % (Y - 1);
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
			for (i = 0; i < X; i++)
			{
				for (j = 0; j < Y; j++)
				{
					if (real_mine[i][j] != '*')
					{
						count = 0;
						if (i - 1 >= 0 && j - 1 >= 0 && real_mine[i - 1][j - 1] == '*')
							count++;
						if (i - 1 >= 0 && real_mine[i - 1][j] == '*')
							count++;
						if (real_mine[i - 1][j + 1] == '*' && i - 1 >= 0 && j + 1 <= Y)
							count++;
						if (j - 1 >= 0 && real_mine[i][j - 1] == '*')
							count++;
						if (real_mine[i][j + 1] == '*' && j + 1 <= Y)
							count++;
						if (i + 1 <= 9 && j - 1 >= 0 && real_mine[i + 1][j - 1] == '*')
							count++;
						if (real_mine[i + 1][j] == '*' && i + 1 <= X)
							count++;
						if (real_mine[i + 1][j + 1] == '*' && i + 1 <= X && j + 1 <= Y)
							count++;
						real_mine[i][j] = count + '0';
					}
				}
			}

			//output('1', pattern, real_mine, show_mine);
			//getchar();
			open_the_map(input, pattern, real_mine, show_mine, m, n, sign_mine);
			return 1;
		}
		else
		{
			while (count)
			{
				x = rand() % (X - 1);
				y = rand() % (Y - 1);
				if (real_mine[x][y] == '0')
					continue;
				if (x - 1 >= 0 && y - 1 >= 0 && real_mine[x - 1][y - 1] == '0')
					continue;
				if (x - 1 >= 0 && real_mine[x - 1][y] == '0')
					continue;
				if (real_mine[x - 1][y + 1] == '0' && x - 1 >= 0 && y + 1 <= Y)
					continue;
				if (y - 1 >= 0 && real_mine[x][y - 1] == '0')
					continue;
				if (real_mine[x][y + 1] == '0' && y + 1 <= Y)
					continue;
				if (x + 1 <= 9 && y - 1 >= 0 && real_mine[x + 1][y - 1] == '0')
					continue;
				if (real_mine[x + 1][y] == '0' && x + 1 <= X)
					continue;
				if (real_mine[x + 1][y + 1] == '0' && x + 1 <= X && y + 1 <= Y)
					continue;
				real_mine[x][y] = '*';
				count--;
			}
			//count mine
			for (i = 0; i < X; i++)
			{
				for (j = 0; j < Y; j++)
				{
					if (real_mine[i][j] != '*')
					{
						count = 0;
						if (i - 1 >= 0 && j - 1 >= 0 && real_mine[i - 1][j - 1] == '*')
							count++;
						if (i - 1 >= 0 && real_mine[i - 1][j] == '*')
							count++;
						if (real_mine[i - 1][j + 1] == '*' && i - 1 >= 0 && j + 1 <= Y)
							count++;
						if (j - 1 >= 0 && real_mine[i][j - 1] == '*')
							count++;
						if (real_mine[i][j + 1] == '*' && j + 1 <= Y)
							count++;
						if (i + 1 <= 9 && j - 1 >= 0 && real_mine[i + 1][j - 1] == '*')
							count++;
						if (real_mine[i + 1][j] == '*' && i + 1 <= X)
							count++;
						if (real_mine[i + 1][j + 1] == '*' && i + 1 <= X && j + 1 <= Y)
							count++;
						real_mine[i][j] = count + '0';
					}
				}
			}
			if (row == '!')
			{
				while (temp)
				{
					r = _getch();
					if (r >= 'A' && r <= 'A' + X)
					{
						temp = 0;
						cout << r;
					}
				}
				temp = 1;
				while (temp)
				{
					c = _getch();
					if (c >= '1' && c <= '9')
					{
						temp = 0;
						cout << c;
					}
					else if (X > 9)
					{
						if (c >= 'a' && c <= 'a' + Y)
						{
							temp = 0;
							cout << c;
						}
					}
				}
				x = r - 65;
				if (c >= '1' && c <= '9')
				{
					y = c - '1';
				}
				else
				{
					y = c - 'a' + 9;
				}
				if (show_mine[x][y] == 'X')
				{
					sign_mine[x][y] = 'x';
				}//OPEN\OUTPUT
				return 1;
			}
			else if (row == '#')
			{
				while (temp)
				{
					r = _getch();
					if (r >= 'A' && r <= 'A' + X)
					{
						temp = 0;
						cout << r;
					}
				}
				temp = 1;
				while (temp)
				{
					c = _getch();
					if (c >= '1' && c <= '9')
					{
						temp = 0;
						cout << c;
					}
					else if (X > 9)
					{
						if (c >= 'a' && c <= 'a' + Y)
						{
							temp = 0;
							cout << c;
						}
					}
				}
				x = r - 65;
				if (c >= '1' && c <= '9')
				{
					y = c - '1';
				}
				else
				{
					y = c - 'a' + 9;
				}
				if (sign_mine[x][y] == 'x')
				{
					sign_mine[x][y] = 'X';
				}//OPEN\OUTPUT
				return 1;
			}
		}
	}
	return 0;
}

void choose_to_start(char input,char pattern, char real_mine[][30], char show_mine[][30], char sign_mine[][30])
{
	//初始化
	int i, j,count=0,temp,temp1, X = 0, Y = 0,amount=0;
	switch (pattern)
	{
		case '1':
			X = 9;
			Y = 9;
			count = 10;
			break;
		case '2':
			X = 16;
			Y = 16;
			count = 40;
			break;
		case '3':
			X = 16;
			Y = 30;
			count = 99;
			break;
	}
	cct_cls();
	//line1
	cout << "内部数组：" << endl;
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
			cout << show_mine[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
	//getchar();
	if (input == '2')
	{
		input_judge(input,pattern, real_mine, show_mine,0,sign_mine);
		cout << endl << endl << "点开后的数组：";
		output2('1', pattern, show_mine, show_mine,sign_mine);
		pause(0);
	}
	else
	{
		if (input == '3' || input == '4')
		{
			clock_t start;
			start = clock();
		    //finish = clock();
			while (1)
			{
				temp1 = input_judge(input, pattern, real_mine, show_mine, start,sign_mine);
				if (temp1 == 1)
				{
					/*clock_t start, finish;
					start = clock();
					finish = clock();*/
					cout << endl << endl << "当前数组：";
					output2('1', pattern, show_mine, show_mine,sign_mine);
					amount = 0;
					while (amount != count)
					{
						temp = input_judge1(input, pattern, real_mine, show_mine, start,sign_mine);
						/*cout << endl << endl << "当前数组：";
						output2('1', pattern, show_mine, show_mine);*/
						if (temp == 0)
						{
							cout << endl << endl << "当前数组：";
							output2('1', pattern, show_mine, show_mine,sign_mine);
							cout << "你输了，游戏结束" << endl;
							pause(0);
							return;
						}
						else if (temp == 2)
						{
							break;
						}
						else if (temp == 1)
						{
							cout << endl << endl << "当前数组：";
							output2('1', pattern, show_mine, show_mine,sign_mine);
							amount = 0;
							amount = if_win(amount, X, Y, show_mine);
						}
						else if (temp == 3)
						{
							continue;
						}
					}
					if (amount == count)
					{
						cout << endl << "恭喜胜利，游戏结束" << endl;
						pause(0);
						return;
					}
					else if (temp = 0||temp==2)
					{
						break;
					}
				}
				else if (temp1 == 3)
				{
					continue;
				}
				else if (temp1 ==0)
				{
					break;
				}
			}
		}
		
	}
}

void Real_mine(char pattern, char real_mine[][30], char show_mine[][30])
{
	//1--9*9--10
	//2--16*16--40
	//3--16*30--99
	int i, j, x, y, X = 0, Y = 0, amount = 0, count = 0;
	//难度
	switch (pattern)
	{
		case '1':
			X = 9;
			Y = 9;
			amount = 10;
			break;
		case '2':
			X = 16;
			Y = 16;
			amount = 40;
			break;
		case '3':
			X = 16;
			Y = 30;
			amount = 99;
			break;
	}
	//埋雷
	while (amount)
	{
		x = rand() % (X - 1);
		y = rand() % (Y - 1);
		if (real_mine[x][y] != '*')
		{
			real_mine[x][y] = '*';
			amount--;
		}
		else
		{
			continue;
		}
	}
	//count mine
	for (i = 0; i < X; i++)
	{
		for (j = 0; j < Y; j++)
		{
			if (real_mine[i][j] != '*')
			{
				count = 0;
				if (i - 1 >= 0 && j - 1 >= 0 && real_mine[i - 1][j - 1] == '*')
					count++;
				if (i - 1 >= 0 && real_mine[i - 1][j] == '*')
					count++;
				if (real_mine[i - 1][j + 1] == '*' && i - 1 >= 0 && j + 1 < Y)
					count++;
				if (j - 1 >= 0 && real_mine[i][j - 1] == '*')
					count++;
				if (real_mine[i][j + 1] == '*' && j + 1 < Y)
					count++;
				if (i + 1 < X && j - 1 >= 0 && real_mine[i + 1][j - 1] == '*')
					count++;
				if (real_mine[i + 1][j] == '*' && i + 1 < X)
					count++;
				if (real_mine[i + 1][j + 1] == '*' && i + 1 < X && j + 1 < Y)
					count++;
				real_mine[i][j] = count + '0';
			}
		}
	}
}

void Show_mine(char input, char pattern,char real_mine[][30], char show_mine[][30])
{
	//1--9*9--10
	//2--16*16--40
	//3--16*30--99
	//初始化
	/*int i, j, X = 0, Y = 0;
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
	}*/

}

void output(char input,char pattern, char real_mine[][30], char show_mine[][30], char sign_mine[][30])
{
	//初始化
	int i, j, X=0, Y=0;
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
	cct_cls();
	if (input == '1')
	{
		//line1
		cout << "内部数组：" << endl;
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
					if (input != '1')
					{
						cct_setcolor(4, 7);
						cout << real_mine[i][j];
						cct_setcolor(0, 7);
					}
					else
					{
						cout << real_mine[i][j];
					}
					cout << " ";
				}
				else
				{
					if (real_mine[i][j] != 'X')
					{
						if (input != '1')
						{
							cct_setcolor(14, 8);
							cout << real_mine[i][j];
							cct_setcolor(0, 7);
						}
						else
						{
							cout << real_mine[i][j];
						}
						cout << " ";
					}
					else
					{
						cout << real_mine[i][j] << " ";
					}
				}
				//cout << real_mine[i][j] << " ";
			}
			cout << endl;
		}
	}
	cout << endl;
	cout << endl;
	pause(0);
}