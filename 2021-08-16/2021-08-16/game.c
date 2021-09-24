//游戏模块（函数声明）
#pragma warning(disable:4996)
#pragma warning(disable:6031)


#include "game.h"
#include <stdio.h>

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}


//void DisplayBoard(char board[ROW][COL], int row, int col)//打印棋盘(有缺陷）
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		//打印一行数据
//		//printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
//		//打印分割线
//		if (i < row - 1)//最后一行不要分割线
//		{
//			printf("---|---|---\n");
//		}
//	}
//}

//打印棋盘(改良）
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//打印一行数据
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			//最后一组无|
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		//打印分割线
		if (i < row - 1)//最后一行不要分割线
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}



//下棋步骤
void Playmove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走：>\n");

	do
	{
		printf("请输入要下的坐标：");
		scanf("%d%d", &x, &y);
		//判断xy坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//判断位置是否已经下过
			if (board[ x - 1][y - 1] == ' ')
			{
				board[ x - 1][y - 1] = '*';
				break;//落子成功，跳出循环
			}
			else
			{
				printf("已被占用，请重新输入\n");
			}
		}
		else
		{
			printf("输入错误，请重新输入\n");
		}
	} while (1);


}




//电脑下棋
void Computermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("\n");
	printf("电脑走>\n");
	while(1)
	{
		x = rand() % row;//用rand获取随机数，%row使得数在row范围里。
	    y = rand() % col;
	   //判断电脑下的位置没有棋子
	    if (board[x][y] == ' ')
	    {
		board[x][y] = '#';
		break;//落子成功，跳出循环
	    }
	}
	
}


//判断输赢
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//横行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}

	}
	//竖行
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	//交叉斜线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
	{
		return board[0][2];
	}
	//建立函数判断是否平局
	if (IsFull(board,ROW,COL) == 1)
	{
		return '%';
	}
	else
	{
		return '&';
	}
}


//判断平局函数：
//返回1为平局
//返回0为继续
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}