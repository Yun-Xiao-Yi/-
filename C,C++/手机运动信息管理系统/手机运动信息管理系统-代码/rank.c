#define _CRT_SECURE_NO_WARNINGS 1
#include"move.h"
#include"rank.h"
#include"Rank.h"

//��������
void RankDestory(Rank** pphead)
{
	assert(pphead);

	Rank* cur = *pphead;
	while (cur)
	{
		Rank* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}

//��ӡ���а�
void RankPrint(Rank* plist)//��ӡȫ���û���Ϣ
{
	int i = 0;
	Rank* pre = plist;
	while (pre != NULL)
	{
		printf(" %s         %s      %d   ",pre->telephone, pre->nickname,pre->data);
		pre = pre->next;
		printf("\n");
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}


//�����û�
Rank* BuyRank(char telephone[20], char nickname[20], int data)//�����ռ�
{
	int i = 0;
	Rank* newnode = (Rank*)malloc(sizeof(Rank));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	for (i = 0; i < 12; i++)
	{
		newnode->telephone[i] = telephone[i];
	}
	for (int i = 0; i < 20; i++)
	{
		newnode->nickname[i] = nickname[i];
	}
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}

void RankPushFront(Rank** pphead, char telephone[20], char nickname[20], int data)//ͷ�壬������û���
{
	assert(pphead);

	Rank* newnode = BuyRank(telephone,nickname, data);
	newnode->next = *pphead;
	*pphead = newnode;
}

//ð������
void bubble_sort(Rank* phead)
{
	//int i = 0;//�����߷�����
	//int j = 0;//��������Ԫ���±�
	//int temp = 0;//����һ����ʱ�Ŀռ䣨����Ԫ�ؽ���ʱ��Ҫһ����ʱ�ռ䣩
	int n = 0;
	Rank* cur = phead;
	while (cur != NULL)
	{
		n++;
		cur = cur->next;
	}
	for (Rank* i = phead; i!=NULL; i=i->next)//����߷�N-1��
	{
		for (Rank* j = phead; j !=NULL; j=j->next)//ÿһ������Ԫ��ֻ��Ƚ�N-1-i�μ���
		{
			if (j->next != NULL)
			{
				if (j->data < j->next->data)
				{
					int  temp = j->data;
					j->data = j->next->data;
					j->next->data = temp;
					char t1[20] = { 0 };
					char t2[20] = { 0 };
					strcpy(t1, j->nickname);//a���Ƹ�t
					strcpy(j->nickname, j->next->nickname);//b���Ƹ�a
					strcpy(j->next->nickname, t1);//t���Ƹ�b
					strcpy(t2, j->telephone);//a���Ƹ�t
					strcpy(j->telephone, j->next->telephone);//b���Ƹ�a
					strcpy(j->next->telephone, t2);//t���Ƹ�b
				}

			}			
		}
	}
}