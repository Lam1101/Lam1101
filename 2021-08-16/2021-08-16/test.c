//测试三子棋

#pragma warning(disable:4996)
#pragma warning(disable:6031)


#include "game.h"//应用自己的头文件
#include <stdio.h>

void menu()//菜单
{

	printf("#####################\n");
	printf("#####################\n");
	printf("######1. play  ######\n");
	printf("######0. exit #######\n");
    printf("#####################\n");
	printf("#####################\n");
}

void game()
{
	char ret;
	//构造棋盘
	char board[ROW][COL] = {0};
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board,ROW,COL);
	//下棋
	while (1)
	{
		
		//玩家下棋
		Playmove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢
	    ret = IsWin(board,ROW,COL);
		if (ret != '&')//是否还能继续游戏。
		{
			break;
	    }
		//电脑下棋
		Computermove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board,ROW,COL);
		if (ret != '&')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家获胜！\n");
	}
	else if (ret == '#') 
	{
		printf("电脑获胜！\n"); 
	}
	else
		printf("平局\n");
	

}



void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));//时间随机数发生器
	do
	{
		menu();//调用菜单
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("三字棋\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}

	} while (input);//input为真则进入循环
}



int main()
{
	test();



	return 0;

}
