//��������
#define ROW 3
#define COL 3

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void InitBoard(char board[ROW][COL],int row,int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void Playmove(char borad[ROW][COL], int row, int col);
void Computermove(char board[ROW][COL], int row,int col);
//����״̬�����Ӯ������Ӯ��ƽ�֣�������Ϸ��������Ҫ����ֵ
//���Ӯ�� *
// ����Ӯ��#
// ƽ�֣�%
// ������Ϸ, &
//
char IsWin(char board[ROW][COL],int row,int col);
int IsFull(char board[ROW][COL], int row, int col);