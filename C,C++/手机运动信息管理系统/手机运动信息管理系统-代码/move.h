#pragma once
#include"move.h"
#include"user.h"
#include<stdio.h>
#include<assert.h>
#include <stdlib.h>
#include<string.h>

//�˶���Ϣ
//typedef struct MoveNode
//{
//	int StepNum;//�˶�����
//	int MoveDay;
//	int Con_Day;//��������
//	struct MoveNode* next;
//}Move;

void MoveInt(int move[7]);//��ʼ���û��˶�����
int AvgStep(int move[7]);//ƽ���˶�����
int Con_Day(int move[7]);//��������
int IsDay(int move[7]);//�жϵ�ǰ�ǵڼ���
void OrderDay(int move[7],int day,int step);//����˳���Ƿ�������
void MovePrint(User* phead);
int DayNum(int move[7]);//�жϵ�ǰ�ǵڼ���