//��Ϸģ�飨����������
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


//void DisplayBoard(char board[ROW][COL], int row, int col)//��ӡ����(��ȱ�ݣ�
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		//��ӡһ������
//		//printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
//		//��ӡ�ָ���
//		if (i < row - 1)//���һ�в�Ҫ�ָ���
//		{
//			printf("---|---|---\n");
//		}
//	}
//}

//��ӡ����(������
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//��ӡһ������
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			//���һ����|
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		//��ӡ�ָ���
		if (i < row - 1)//���һ�в�Ҫ�ָ���
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



//���岽��
void Playmove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("����ߣ�>\n");

	do
	{
		printf("������Ҫ�µ����꣺");
		scanf("%d%d", &x, &y);
		//�ж�xy����ĺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//�ж�λ���Ƿ��Ѿ��¹�
			if (board[ x - 1][y - 1] == ' ')
			{
				board[ x - 1][y - 1] = '*';
				break;//���ӳɹ�������ѭ��
			}
			else
			{
				printf("�ѱ�ռ�ã�����������\n");
			}
		}
		else
		{
			printf("�����������������\n");
		}
	} while (1);


}




//��������
void Computermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("\n");
	printf("������>\n");
	while(1)
	{
		x = rand() % row;//��rand��ȡ�������%rowʹ������row��Χ�
	    y = rand() % col;
	   //�жϵ����µ�λ��û������
	    if (board[x][y] == ' ')
	    {
		board[x][y] = '#';
		break;//���ӳɹ�������ѭ��
	    }
	}
	
}


//�ж���Ӯ
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//����
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}

	}
	//����
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	//����б��
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
	{
		return board[0][2];
	}
	//���������ж��Ƿ�ƽ��
	if (IsFull(board,ROW,COL) == 1)
	{
		return '%';
	}
	else
	{
		return '&';
	}
}


//�ж�ƽ�ֺ�����
//����1Ϊƽ��
//����0Ϊ����
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