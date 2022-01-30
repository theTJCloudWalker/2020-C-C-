#pragma once

void mine_sweeper_menu(char real_mine[][30], char show_mine[][30], char sign_mine[][30]);
void Real_mine(char pattern,char real_mine[][30], char show_mine[][30]);
void degree_of_difficulty(char input, char real_mine[][30], char show_mine[][30], char sign_mine[][30]);
void Show_mine(char input, char pattern, char real_mine[][30], char show_mine[][30]);
void output(char input, char pattern, char real_mine[][30], char show_mine[][30], char sign_mine[][30]);
void choose_to_start(char input,char pattern, char real_mine[][30], char show_mine[][30], char sign_mine[][30]);
void open_the_map(char input, char pattern, char real_mine[][30], char show_mine[][30],int x,int y,char sign_mine[][30]);
int input_judge(char input,char pattern, char real_mine[][30], char show_mine[][30], long start, char sign_mine[][30]);
void output2(char input, char pattern, char real_mine[][30], char show_mine[][30], char sign_mine[][30]);
int input_judge1(char input,char pattern, char real_mine[][30], char show_mine[][30], long start, char sign_mine[][30]);
void pause(int speed);
void title_page(char input,char pattern, int M, int N, int count);
void sign(int x, int y, char real_mine[][30], char show_mine[][30], char sign_mine[][30]);
void clean(int x, int y, char real_mine[][30], char show_mine[][30], char sign_mine[][30]);
void show(int x, int y, char real_mine[][30], char show_mine[][30], char sign_mine[][30]);
int if_win(int count, int X, int Y,char show_mine[][30]);