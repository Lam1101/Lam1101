//函数声明
#define ROW 3
#define COL 3

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void InitBoard(char board[ROW][COL],int row,int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void Playmove(char borad[ROW][COL], int row, int col);
void Computermove(char board[ROW][COL], int row,int col);
//四种状态（玩家赢，电脑赢，平局，继续游戏）——需要返回值
//玩家赢， *
// 电脑赢，#
// 平局，%
// 继续游戏, &
//
char IsWin(char board[ROW][COL],int row,int col);
int IsFull(char board[ROW][COL], int row, int col);