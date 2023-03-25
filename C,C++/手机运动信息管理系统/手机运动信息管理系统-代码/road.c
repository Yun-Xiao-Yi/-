#define _CRT_SECURE_NO_WARNINGS 1
#include"move.h"
#include"rank.h"
#include"user.h"
#include"stdbool.h"
#include"road.h"
#include"Queue.h"
#include"route.h"

#define ERROR -1
#define MaxSize 100
#define INFINITY 65535        /* ����Ϊ˫�ֽ��޷������������ֵ65535*/
int Visited[MaxSize]; //�������




//�Ͻ�˹�����㷨��ص�a�������ص�����·�� 
Road* djstl(MGraph map, int id_a)
{
	//����·�� 
	Road r[MAXSIZE];
	//������飨0Ϊδ��ǣ�1Ϊ�ѱ�ǣ� 
	int flag[MAXSIZE] = { 0 };

	int i;
	//��ʼ������·�� 
	for (i = 1; i <= map->Nv; i++)
	{
		/*a�ص㵽���������ص�ľ���*/
		/*�����a���յ���i*/
		r[i].count = 2;
		r[i].path[0] = id_a;
		r[i].path[1] = i;
		r[i].minDistance = map->G[id_a][i];
	}

	//���a
	flag[id_a] = 1;

	//����δ��ǵص���ѭ��ִ�� 
	while (1)
	{
		//Ѱ��a��δ��ǵĵص�����·�ߵ��±� 
		int index = -1;
		for (i = 1; i <= map->Nv; i++)
		{
			//δ��� 
			if (flag[i] == 0)
			{
				if (index == -1)
				{
					index = i;
				}
				else if (r[i].minDistance < r[index].minDistance)
				{
					index = i;
				}
			}
		}
		//������δ����±��� 
		if (index == -1)
		{
			return r;
		}
		//���index
		flag[index] = 1;
		//�Ƚϲ��޸�����·�ߴ�ʱ�����·�� 
		for (i = 1; i <= map->Nv; i++)
		{
			//δ�ҵ����·���ĵص� 
			if (flag[i] == 0)
			{
				//a->...->i�̻���a->...->index->i�̣����߶̣���˵��a��i�и��õ�ѡ�� 
				if (r[i].minDistance > r[index].minDistance + map->G[index][i])
				{
					/*��r[index]��ֵ����r[i]�����޸�r[i]�����·��*/
					r[i].count = r[index].count + 1;
					int j;
					for (j = 0; j < r[i].count - 1; j++)
					{
						r[i].path[j] = r[index].path[j];
					}
					r[i].path[j] = i;
					r[i].minDistance = r[index].minDistance + map->G[index][i];
				}
			}
		}
	}
}


//��ӡa��b�����·�� 
void displayRoad(Road rab)
{
	printf("����:%d\n", rab.minDistance);
	int i;
	printf("·��:");
	for (i = 0; i < rab.count - 1; i++)
	{
		printf("%d-->", rab.path[i]);
	}
	printf("%d\n\n", rab.path[i]);
}


//Dijkstra

//Vertex FindMinDist(MGraph Graph, bool* collected)
//{ /* ����δ����¼������dist��С�� */
//    Vertex MinV, V;
//    float MinDist = INFINITY;
//
//
//    for (V = 0; V < Graph->Nv; V++) {
//        if (collected[V] == false)
//        {
//            if (dist[V] < MinDist)
//            {
//                /* ��Vδ����¼����dist[V]��С */
//                MinDist = dist[V]; /* ������С���� */
//                MinV = V; /* ���¶�Ӧ���� */
//            }
//        }
//    }
//    if (MinDist < INFINITY) /* ���ҵ���Сdist */
//        return MinV; /* ���ض�Ӧ�Ķ����±� */
//    else
//        return ERROR;  /* �������Ķ��㲻���ڣ����ش����� */
//}
//
//
//
//void Dijkstra(MGraph Graph, Vertex S)
//{
//    int collected[MaxVertexNum];
//    Vertex V = 0, W = 0;
//
//    /* ��ʼ�����˴�Ĭ���ڽӾ����в����ڵı���INFINITY��ʾ */
//    for (V = 0; V < Graph->Nv; V++)
//    {
//        dist[V] = Graph->G[S][V];
//        if (dist[V] < INFINITY)
//            path[V] = S;
//        else
//            path[V] = -1;
//        collected[V] = false;
//    }
//    /* �Ƚ�������뼯�� */
//    dist[S] = 0.0f;
//    collected[S] = true;
//
//    /* while (1)
//     {*/
//     /* V = δ����¼������dist��С�� */
//    V = FindMinDist(Graph, collected);
//
//    if (V == ERROR) /* ��������V������ */
//        //break;      /* �㷨���� */
//
//        collected[V] = true;  /* ��¼V */
//
//    for (W = 0; W < Graph->Nv; W++) /* ��ͼ�е�ÿ������W */
//    {
//        if (collected[W] == false && Graph->G[V][W] < INFINITY)
//        {
//            if (Graph->G[V][W] < 0) /* ���и��� */
//                return false; /* ������ȷ��������ش����� */
//            /* ����¼Vʹ��dist[W]��С */
//            if (dist[V] + Graph->G[V][W] < dist[W])
//            {
//                dist[W] = dist[V] + Graph->G[V][W]; /* ����dist[W] */
//                path[W] = V; /* ����S��W��·�� */
//            }
//        }
//    }
//    /*}*/ /* while����*/
//    //return true; /* �㷨ִ����ϣ�������ȷ��� */
//    for (int i = 1; i < Graph->Nv; i++)
//    {
//        if (dist[i] != 0)
//            if (dist[i] != INFINITY)
//                printf("��%s���·������:%f\n", Graph->Data[i], dist[i]);
//            else
//            {
//                printf("��%s���·������:�޷�����\n", Graph->Data[i]);
//            }
//    }
//}

/* �ڽӾ���洢 - ��Դ���·�㷨 */

bool Floyd(MGraph Graph, WeightType D[][MaxVertexNum], Vertex path[][MaxVertexNum])
{
    Vertex i, j, k;

    /* ��ʼ�� */
    for (i = 0; i < Graph->Nv; i++)
        for (j = 0; j < Graph->Nv; j++) {
            D[i][j] = Graph->G[i][j];
            path[i][j] = -1;
        }

    for (k = 0; k < Graph->Nv; k++)
        for (i = 0; i < Graph->Nv; i++)
            for (j = 0; j < Graph->Nv; j++)
                if (D[i][k] + D[k][j] < D[i][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                    if (i == j && D[i][j] < 0) /* �����ָ�ֵȦ */
                        return false; /* ������ȷ��������ش����� */
                    path[i][j] = k;
                }
    return true; /* �㷨ִ����ϣ�������ȷ��� */
}

