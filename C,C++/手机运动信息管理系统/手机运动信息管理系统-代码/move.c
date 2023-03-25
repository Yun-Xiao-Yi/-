#include"move.h"
#include"user.h"


void MoveInt(int move[7])//��ʼ���û��˶�����
{
		for (int i = 0; i < 7; i++)
		{
			move[i] = 0;
		}

}


int AvgStep(int move[7])//ƽ���˶�����
{
	int Move = 0;
	for (int i = 0; i < 7; i++)
		Move += move[i];
	Move /= 7;
	return Move;
}

int Con_Day(int move[7])//��������
{
	int i = 0;
	int conday = 0;
	int n = IsDay(move);
	while (i < n)
	{
		if (move[i] == 0)
		{
			conday = 0;
		}
		else
			conday++;
		i++;
	}
	return conday;
}

int IsDay(int move[7])//�жϵ�ǰ�ǵڼ���
{
	int i = 7;
	int m = 0;
	int n = 7;
	int q = 0;
	while (i--)
	{
		if (q == 1)
			break;
		//if ((move[i] == 0) || (move[i] < 0))
		if (move[i] == 0) 
			m++;
		else
			q = 1;
	}
	n -= m;
	//if (n == 0)
	//	return 0;
	//else
		return n;
}

int DayNum(int move[7])//�жϵ�ǰ�ǵڼ���
{
	int i = 7;
	int m = 0;
	int n = 7;
	int q = 0;
	while (i--)
	{
		/*if (q == 1)
			break;*/
		//if ((move[i] == 0) || (move[i] < 0))
		if (move[i] == 0)
			m++;
		/*else
			q = 1;*/
	}
	n -= m;
	//if (n == 0)
	//	return 0;
	//else
	return n;
}

void OrderDay(int move[7], int day, int step)//����˳���Ƿ�������

{
	if (day < 7)
	{
		move[day] = step;
	}
	else
	{
		for (int i = 0; i < 6; i++)
			move[i] = move[i + 1];
		move[6] = step;
	}
}


void MovePrint(User* phead)
{
	int i = 0;
	User* cur = phead;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("   �û���         �û��ǳ�     �û��Ա�     �û�����    ��һ��  �ڶ���  ������  ������  ������  ������  ������ ƽ������  �����˶�����\n");
	while (cur != NULL)
	{
		int move = 0;
		printf("%-12s      %-12s  %4d       %4d          ", cur->telephone, cur->nickname, cur->sex, cur->age);
		for (i = 0; i < 7; i++)
		{
			printf("%4d    ", cur->move[i]);
			move += cur->move[i];
		}
		cur->ConDay = Con_Day(cur->move);
		if (IsDay(cur->move) == 0)
			cur->AvgStep = 0;
		else
			cur->AvgStep=move/DayNum(cur->move);
		printf("%4.0f    %4d", cur->AvgStep, cur->ConDay);
		cur = cur->next;
		printf("\n");
	}	
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}