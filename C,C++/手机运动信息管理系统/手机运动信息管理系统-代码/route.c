#define _CRT_SECURE_NO_WARNINGS 1
#include"move.h"
#include"rank.h"
#include"route.h"
#include"user.h"
#include"Queue.h"

#define me(a,b) memset(a,b,sizeof(b))
#define MAX 100
#define ERROR -1
#define MaxSize 100
#define INFINITY 65535        /* ����Ϊ˫�ֽ��޷������������ֵ65535*/
int Visited[MaxSize]; //�������


MGraph CreateGraph(int VertexNum)
{ /* ��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ */
    Vertex V, W;
    MGraph Graph;

    Graph = (MGraph)malloc(sizeof(GNode)); /* ����ͼ */
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    /* ��ʼ���ڽӾ��� */
    /* ע�⣺����Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv - 1) */
    for (V = 0; V < Graph->Nv; V++)
        for (W = 0; W < Graph->Nv; W++)
            Graph->G[V][W] = INFINITY;

    return Graph;
}

void InsertEdge(MGraph Graph, Edge E)//����ߣ��趨Ϊ����ͼ
{
        /* ����� <V1, V2> */
        Graph->G[E->V1][E->V2] = E->Weight;
        /* ��������ͼ����Ҫ�����<V2, V1> */
        Graph->G[E->V2][E->V1] = E->Weight;
}








void printf_MG(GNode G)//���ͼ
{
    for (int i = 0; i < G.Nv; i++)
    {
        for (int j = 0; j < G.Nv; j++)
        {
            if (G.G[i][j] == INF)
                printf("�� ");
            else
                printf("%d ", G.G[i][j]);
        }
        printf("\n");
    }
}


void Dijkstra(MGraph Graph, Vertex u)
{
    GNode g = *Graph;
    int U[MAX], mmin;//�ֱ��ʾ�Ѿ��������ĵ㡢�൱ǰ��ʼ������ĵ�ľ���
    //�Ը�������г�ʼ��
    memset(U, 0, sizeof(U));
    memset(path, -1, sizeof(path));
    //me(dist,INF);
    for (int i = 0; i < g.Nv; i++)
    {
        dist[i] = g.G[u][i];
        if (g.G[u][i] < INF)
            path[i] = u;
    }
    dist[u] = 0;//������ľ���
    for (int i = 0; i < g.Nv; i++) //���Դ�㵽Nv�������̾���
    {
        mmin = INF;
        U[u] = 1;//��ѡ�����µ���ʼ�����U������
        for (int j = 0; j < g.Nv; j++)
            //���if�ж϶���u�ļ����Ƿ�����ͨ������j�ĸ��̵�·����������֣���ı�ԭ��·�����䳤�ȣ�����ʲô������
        {
            if (!U[j] && dist[u] + g.G[u][j] < dist[j])
            {
                dist[j] = dist[u] + g.G[u][j];//����·������
                path[j] = u;//���µ�����j��·��
            }
        }
        for (int j = 0; j < g.Nv; j++)
            //���ѭ��ÿ�δ�ʣ�ඥ����ѡ��һ�����㣬ͨ����������·����ͨ������ʣ�ඥ���·�����ǳ�����̵�
        {
            if (U[j] == 0 && dist[j] < mmin)
            {
                u = j;
                mmin = dist[j];
            }
        }
    }
}

void printf_path(MGraph pGraph, int u, int x)
{
    int a[MAX], cou = 0, ex = x;
    if (u == x)
        printf("%s-->%s=0ǧ��", pGraph->Data[u], pGraph->Data[x]);
    else if (path[x] == -1)
        printf("%d-->%d=��", u, x);//û��·��
    else
    {
        while (x != u)
        {
            a[cou++] = x;
            x = path[x];
        }
        a[cou] = x;
        for (int i = cou; i >0; i--)
            //printf("%d-->", a[i]);
            printf("%s-->", pGraph->Data[a[i]]);
        float ret = 0.0f;
        ret = dist[ex];
        ret /= 1000;
        printf("%s=%0.3fǧ��", pGraph->Data[a[0]], ret);
    }
    printf("\n");
}