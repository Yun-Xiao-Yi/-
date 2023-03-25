#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include"move.h"

//���а�����
typedef struct RankNode
{
	int data;//������Ϣ
	char nickname[20];//ƥ����û���Ϣ
	char telephone[20];//ƥ����û���Ϣ
	struct RankNode* next;
}Rank;



//�����û�
Rank* BuyRank(char telephone[20], char nickname[20], int data);//�����ռ�
void RankPushFront(Rank** pphead, char telephone[20], char nickname[20], int data);//ͷ�壬������û�

//ð������
void bubble_sort(Rank* phead);

//��������
void RankDestory(Rank** pphead);