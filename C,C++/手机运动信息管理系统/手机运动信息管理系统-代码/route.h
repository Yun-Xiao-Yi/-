#define _CRT_SECURE_NO_WARNINGS 1

#ifndef _ROUTE_H 
#define _ROUTE_H//һ�����ļ����Ĵ�д


#include"move.h"
#include"rank.h"
#include"user.h"
#include"stdbool.h"

#define MAXSIZE 1000
#define NoEdge 1000
int n, m;
int G[MAXSIZE][MAXSIZE];  //Ȩ��
int dist[MAXSIZE];    //��Դ�����·�� 
bool collected[MAXSIZE];
int path[MAXSIZE];


/* ͼ���ڽӾ����ʾ�� */

#define MaxVertexNum 100    /* ��󶥵�����Ϊ100 */
#define INFINITY 65535        /* ����Ϊ˫�ֽ��޷������������ֵ65535*/
#define INF 65535        /* ����Ϊ˫�ֽ��޷������������ֵ65535*/
typedef int Vertex;         /* �ö����±��ʾ����,Ϊ���� */
typedef int WeightType;        /* �ߵ�Ȩֵ��Ϊ���� */
typedef char DataType;        /* ����洢������������Ϊ�ַ��� */

/* �ߵĶ��� */
typedef struct  Enode 
{
    Vertex V1, V2;      /* �����<V1, V2> */
    WeightType Weight;  /* Ȩ�� */
}ENode,*PtrToENode;
typedef PtrToENode Edge;

/* ͼ���Ķ��� */
typedef struct Gnode 
{
    int Nv;  /* ������ */
    int Ne;  /* ����   */
    WeightType G[MaxVertexNum][MaxVertexNum]; /* �ڽӾ��� */
    DataType Data[MaxVertexNum][MaxVertexNum];      /* �涥�㣨�ַ��������� */
    /* ע�⣺�ܶ�����£����������ݣ���ʱData[]���Բ��ó��� */
}GNode,*PtrToGNode;
typedef PtrToGNode MGraph; /* ���ڽӾ���洢��ͼ���� */



MGraph CreateGraph(int VertexNum);/* ��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ */

void InsertEdge(MGraph Graph, Edge E);//����ߣ��趨Ϊ����ͼ

MGraph BuildGraph();//����ͼ

void printf_MG(GNode G);//���ͼ


/* �ڽӾ���洢 - ��Ȩͼ�ĵ�Դ���·�㷨 */ 

void Dijkstra(MGraph Graph, Vertex u);

void printf_path(MGraph pG, int u, int x);


#endif 