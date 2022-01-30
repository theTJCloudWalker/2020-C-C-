/* 2053285 ÂÞ±ó½­ ÐÅ21 */
#include<iostream>
#include"mine_sweeper.h"
#include <time.h>

using namespace std;

int main()
{
	srand((unsigned int)(time(0)));
	char real_mine[16][30] = {}, show_mine[16][30] = {}, sign_mine[16][30] = {};
	int i, j;
	for (i = 0; i < 16; i++)
	{
		for (j = 0; j < 30; j++)
		{
			show_mine[i][j] = 'X';
			sign_mine[i][j] = 'X';
		}
	}
	mine_sweeper_menu(real_mine,show_mine,sign_mine);
	cout << endl;
	return 0;
}