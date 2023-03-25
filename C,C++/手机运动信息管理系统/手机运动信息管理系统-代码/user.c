#include "user.h"
#include"move.h"
#include<stdbool.h>
#define _CRT_SECURE_NO_WARNINGS 1

UserWeekPrint(User* cur,int move[7])//��ӡ���ҵ����û���Ϣ
{
	int i = 0,j=0;
	int m = 0;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("�ڼ��� �˶�����  \n");
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 7; j++)
		{
			if (move[j] == cur->move[i])
			{
				m = j;
				break;
			}
		}
		printf("��%d��:%4d\n",m,cur->move[i]);
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

bool UserName(User* phead, char telephone[20])//�ж��ֻ����Ƿ�Ψһ��
{
	User* cur = phead;
	while (cur != NULL)
	{
		if (strcmp(cur->telephone, telephone) == 0)
			return false;
		cur = cur->next;
	}
	return true;
}

void UserPerPrint(User* cur)
{
	int i = 0;
	int move = 0;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("   �û���         �û��ǳ�     �û��Ա�     �û�����    ��һ��  �ڶ���  ������  ������  ������  ������  ������ ƽ������  �����˶�����\n");
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
			cur->AvgStep = move / DayNum(cur->move);
		printf("%4.0f    %4d", cur->AvgStep, cur->ConDay);
		printf("\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}


//�����û�
User* BuyUser( char telephone[20], char nickname[20], int sex, int age,int move[7])//�����ռ�
{
	int i = 0;
	User* newnode = (User*)malloc(sizeof(User));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	for (int i = 0; i < 12; i++)
	{
		newnode->telephone[i] = telephone[i];
	}
	for (int i = 0; i < 20; i++)
	{
		newnode->nickname[i] = nickname[i];
	}
	newnode->sex = sex;
	newnode->age = age;
	if(IsDay(move)==0)
		MoveInt(newnode->move);//��ʼ���˶�����
	else
	{
		for (i = 0; i < 7; i++)
		{
			newnode->move[i] = move[i];
		}
	}
	newnode->next = NULL;
	return newnode;
}

void UserPushFront(User** pphead, char telephone[20], char nickname[20], int sex, int age,int move[7])//ͷ�壬������û���
{
	assert(pphead);

	User* newnode = BuyUser(telephone, nickname,sex,age,move);
	newnode->next = *pphead;
	*pphead = newnode;
}





//ɾ���û�
User* UserNumFind(User* phead, char telephone[12])//���û�����ѯ
{
	User* cur = phead;
	while (cur)
	{
		if (strcmp(cur->telephone, telephone) == 0)
			return cur;

		cur = cur->next;
	}

	return NULL;
 }

User* UserNameFind(User* phead, char nickname[20])//���û��ǳƲ�ѯ
{
	User* cur = phead;
	while (cur)
	{
		if (strcmp(cur->nickname, nickname) == 0)
			return cur;

		cur = cur->next;
	}
	return NULL;
}

void UserPopFront(User** pphead)//ͷɾ
{
	assert(pphead);

	// ����ļ��
	if (*pphead == NULL)
	{
		return;
	}

	User* del = *pphead;
	*pphead = (*pphead)->next;
	free(del);
	del = NULL;
}

void UserErase(User** pphead, User* pos)// ɾ��posλ��
{
	assert(pphead);//���ԣ���ֹppheadΪ��
	assert(pos);//���ԣ���ֹposΪ��

	if (*pphead == pos)
	{
		UserPopFront(pphead);
	}
	else
	{
		User* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;

			// ���pos���������нڵ㣬����������
			assert(prev);
		}

		prev->next = pos->next;
		free(pos);
		//pos = NULL;
	}
}

//��ѯ�û����ɸ����û��š��Ա������˶������Ƚ��в�ѯ��Ҫ����ʾ���з�����������Ϣ��
User* UserSexFind(User* phead, int sex)//0ΪŮ��1Ϊ��
{
	User* cur = phead;
	while (cur)
	{
		if (sex == cur->sex)
			return cur;

		cur = cur->next;
	}
	return NULL;
}
User* UserConDayFind(User* phead, int day)//��������
{
	User* cur = phead;
	while (cur)
	{
		if (day == Con_Day(cur->move))
			return cur;
		cur = cur->next;
	}
	return NULL;
}