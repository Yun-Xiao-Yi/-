#define _CRT_SECURE_NO_WARNINGS 1
#include"move.h"
#include"rank.h"
#include"user.h"
#include"stdbool.h"
#include"Queue.h"
#include"route.h"




//·�߽ṹ 
typedef struct road
{
	//�����ص�id 
	int path[MAXSIZE];
	//����
	int minDistance;
	//�����ĵص���
	int count;
}Road;



//�Ͻ�˹�����㷨��ص�a�������ص�����·��
Road* djstl(MGraph map, int id_a);

//��ӡa��b�����·�� 
void displayRoad(Road rab);

/* �ڽӾ���洢 - ��Ȩͼ�ĵ�Դ���·�㷨 */
Vertex FindMinDist(MGraph Graph, bool* collected);

void Dijkstra(MGraph Graph, Vertex S);

/* �ڽӾ���洢 - ��Դ���·�㷨 */

bool Floyd(MGraph Graph, WeightType D[][MaxVertexNum], Vertex path[][MaxVertexNum]);