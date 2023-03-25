#define _CRT_SECURE_NO_WARNINGS 1
#include"move.h"
#include"rank.h"
#include"user.h"
#include"Data.h"
#include"route.h"
#include <string.h>
#include <errno.h>

void ReadUserFile(User** pphead)//�����û���,���봫�����ָ�룬�����˳��ú�������Ϣ������
{
	//��ʼ������
	char telephone[20] = { 0 };
	char nickname[20] = { 0 };
	int sex = 0;//0ΪŮ��1λ�С�
	int age = 18;
	int move[7] = { 0 };
	float AvgStep = 0.00f;
	int ConDay = 0;//��������
	int i = 0;


	char buf[1024];
	FILE* pf = fopen("user.txt", "r");
	if (pf == NULL)
	{
		//printf("%s\n", strerror(errno));
		perror("fopen");
	}

	else
	{
		//��һ������
		fgets(buf, sizeof(buf), pf);//������һ��
		while (!feof(pf))
		{
			//ԭtxt�ĵ�������֮�����Կո������
			fscanf(pf, "%s %s %d %d %d %d %d %d %d %d %d %f %d",
				telephone, nickname, &sex, &age,
				&move[0], &move[1], &move[2], &move[3], &move[4], &move[5], &move[6],
				&AvgStep, &ConDay
			);
			UserPushFront(pphead, telephone, nickname, sex, age, move);//ͷ�壬������û���
		}

		printf("succes!\n");

	}

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	//MovePrint(*pphead);//��ӡ�����û���Ϣ
}

void ReadEdge(GNode* Graph)
{
	Vertex V;
	char buf[1024];

	FILE* pf = fopen("edge.txt", "r");
	if (pf == NULL)
	{
		//printf("%s\n", strerror(errno));
		perror("fopen");
	}

	else
	{
		//��һ������
		fgets(buf, sizeof(buf), pf);//������һ��
		while (!feof(pf))
		{
			/* ������������ݵĻ����������� */
			for (V = 0; V < Graph->Nv; V++)
			{
				char s[MaxVertexNum][MaxVertexNum];
				fscanf(pf, "%s", &(s[V]));
				strcpy(Graph->Data[V], s[V]);
			}
		}

		printf("succes!\n");

	}

	//�ر��ļ�
	fclose(pf);
	pf = NULL;

}




void ReadBuildGraph(GNode** ppGraph,Edge* ppE)//�����˶�ͼ
{
	GNode* pGraph;
	Edge E=NULL;
	Vertex V;
	int Nv, i;
	char buf[1024];

	Nv = 20;//�趨�������
	pGraph = CreateGraph(Nv); /* ��ʼ����Nv�����㵫û�бߵ�ͼ */

	pGraph->Ne = 33;//�趨����

	FILE* pf = fopen("route.txt", "r");
	if (pf == NULL)
	{
		//printf("%s\n", strerror(errno));
		perror("fopen");
	}

	else
	{
		//��һ������
		fgets(buf, sizeof(buf), pf);//������һ��
		while (!feof(pf))
		{
			if (pGraph->Ne != 0) { /* ����б� */
				E = (Edge)malloc(sizeof(ENode)); /* �����߽�� */
				/* ����ߣ���ʽΪ"��� �յ� Ȩ��"�������ڽӾ��� */
				for (i = 0; i < pGraph->Ne; i++)
				{
					int V1 = 0; int V2 = 0; int Weight = 0.0;
					fscanf(pf, "%d %d %d", &V1, &V2, &Weight);
					E->V1 = V1; E->V2 = V2; E->Weight = Weight;
					/* ע�⣺���Ȩ�ز������ͣ�Weight�Ķ����ʽҪ�� */
					InsertEdge(pGraph, E);
				}
			}
		}
		printf("succes!\n");
	}

	//�ر��ļ�
	fclose(pf);
	pf = NULL;

	ReadEdge(pGraph);
	*ppGraph = pGraph;
	*ppE = E;
}



void WriteUserFile(User** pphead)
{
	//��ʼ������
	char telephone[20] = { 0 };
	char nickname[20] = { 0 };
	int sex = 0;//0ΪŮ��1λ�С�
	int age = 18;
	int move[7] = { 0 };
	float AvgStep = 0.00f;
	int ConDay = 0;//��������
	int i = 0;
	int n = 0;

	User* cur = *pphead;

	char buf[1024];
	FILE* pf = fopen("user2.txt", "w");
	if (pf == NULL)
	{
		perror("fopen");
	}

	else
	{
		fprintf(pf, "   �û���           �û��ǳ�       �û��Ա�       �û�����      ��һ��  �ڶ���  ������  ������  ������  ������  ������ ƽ������  �����˶�����\n");
		while (cur != NULL)
		{
			int move = 0;
			fprintf(pf, "%-12s      %-12s  %4d       %4d          ", cur->telephone, cur->nickname, cur->sex, cur->age);
			for (i = 0; i < 7; i++)
			{
				fprintf(pf, "%4d    ", cur->move[i]);
				move += cur->move[i];
			}
			cur->ConDay = Con_Day(cur->move);
			if (IsDay(cur->move) == 0)
				cur->AvgStep = 0;
			else
				cur->AvgStep = move / DayNum(cur->move);
			fprintf(pf, "%4.0f    %4d\n", cur->AvgStep, cur->ConDay);
			cur = cur->next;



		}

		printf("succes!\n");

	}

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}