//����������

#pragma warning(disable:4996)
#pragma warning(disable:6031)


#include "game.h"//Ӧ���Լ���ͷ�ļ�
#include <stdio.h>

void menu()//�˵�
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
	//��������
	char board[ROW][COL] = {0};
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board,ROW,COL);
	//����
	while (1)
	{
		
		//�������
		Playmove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж���Ӯ
	    ret = IsWin(board,ROW,COL);
		if (ret != '&')//�Ƿ��ܼ�����Ϸ��
		{
			break;
	    }
		//��������
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
		printf("��һ�ʤ��\n");
	}
	else if (ret == '#') 
	{
		printf("���Ի�ʤ��\n"); 
	}
	else
		printf("ƽ��\n");
	

}



void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));//ʱ�������������
	do
	{
		menu();//���ò˵�
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("������\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}

	} while (input);//inputΪ�������ѭ��
}



int main()
{
	test();



	return 0;

}
