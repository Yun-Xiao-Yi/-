#define _CRT_SECURE_NO_WARNINGS 1
#include"user.h"
#include"move.h"
#include"rank.h"
#include"route.h"
#include"road.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int main()
{
	int x;
	//��ʼ������
	char telephone[20] = { 0 };
	char nickname[20] = { 0 };
	int sex = 0;//0ΪŮ��1λ�С�
	int age = 18;
	int move[7] = { 0 };
	int StepNum;//�˶�����
	int MoveDay;
	int ConDay;//��������
	User* phead = NULL;
	Rank* plist = NULL;
	GNode* pGraph = NULL;//ͼ
	ENode* pE = NULL;//��
	Vertex V = 0;
	int Nv = 0;


	while (1)
	{
		printf("*****************�ֻ��˶���Ϣ����ϵͳ*****************\n");
		printf("--------------------�û���Ϣ����----------------------\n");
		printf("1�������û�  2��ɾ���û�  3����ѯ�û�  4���޸��û�\n");
		printf("--------------------�˶���Ϣ����--------------------\n");
		printf("5������û��˶���Ϣ 6���޸��û��˶���Ϣ 7����ʾ�����û���Ϣ\n");
		printf("--------------------�˶����а�--------------------\n");
		printf("8���������а� 9�������˶����а� 10��һ�����а�\n");
		printf("-------------------�����˶�·��-------------------\n");
		printf("        11.������������ÿ���ص�����·�� \n");
		printf("-------------------�����ļ�����-------------------\n");
		printf("     12�����ݵ���              13�����ݱ���\n");
		printf("                   0���˳�\n");
		printf("*****************************************************\n");
		printf("��ѡ�����������0-14��\n");
		scanf("%d", &x);
		switch (x)
		{
		case 0:
			printf("лл��ʹ�ñ�ϵͳ���ټ�����\n");
			return 1;
		case 1://�����û�
		{
			char temp[20];
			printf("������Ҫ�����û��ĸ�����Ϣ��\n");
			printf("Ҫ�����û����ֻ��š��ǳơ��Ա�(0ΪŮ��1Ϊ��)������ֱ�Ϊ��\n");
			while (1)
			{
				printf("Ҫ�����û����ֻ���:��Ҫ����11λ����λ��0,�������룩");
				scanf("%s", temp);

				bool ret = UserName(phead, temp);
				if (ret == false)
				{
					printf("�ֻ��ŷ����ظ���������Ψһ���ֻ��ţ�����\n");
				}
				else
				{
					int len = strlen(temp), i, s = 0;
					if (temp[0] != '1' || len != 11)
						printf("NO!!!\n");
					else
					{
						for (i = 0; i < 11; i++)
						{
							if (temp[i] >= '0' && temp[i] <= '9')
								s++;//S��¼ѭ������
							else
								break;
						}
						if (s == 11)
						{
							printf("yes\n");
							break;
						}
						else printf("no\n");
					}
				}
			}
			while (1)
			{
				printf("Ҫ�����û����ǳ�:(�ǳ�Ҫ��λ����4��12λ֮��)");
				scanf("%s", nickname);
				int len = strlen(nickname), i, s = 0;
				if (len >= 4 && len <= 12)
				{
					break;
				}
				else
				{
					printf("NO!\n");
				}
			}
			while (1)
			{
				printf("�����������û����Ա�(0ΪŮ��1Ϊ��)");
				scanf("%d", &sex);
				if (sex == 0 || sex == 1)
					break;
			}
			while (1)
			{
				printf("��Ҫ�����û������䣨������С��0���ߴ���150����");
				scanf("%d", &age);
				if ((age > 0) && (age < 150))
				{
					break;
				}
				else
					printf("������󣡣���\n");
			}
			UserPushFront(&phead, temp, nickname, sex, age, move);//ͷ�壬������û���
			MovePrint(phead);//��ӡ�����û���Ϣ
		}
		continue;
		case 2://ɾ���û�:�ɸ����û��ź��ǳƽ���ɾ����ɾ��֮ǰ�Ȳ�ѯ���ҵ������Ҫ��ɾ��ȷ�ϲſ������ɾ��������
		{
			int i = 0;
			printf("����Ը����û��Ż��û��ǳ����ַ�ʽ��ѯ�û���Ϣ������ɾ������ѡ���ѯģʽ��  1.�����û���   2.�ǳƣ�\n");
			scanf("%d", &i);
			switch (i)
			{
				//�����û�:Ҫ�������û����û��ţ��ֻ��ţ����ǳơ��Ա��������Ϣ���˶��������˶���Ϣ��������ӣ�ƽ�������������˶�����ͨ�������á�
			case 1:// 1.�����û���
			{
				printf("������Ҫ��ѯ���û��ţ�");
				scanf("%s", telephone);
				User* cur = UserNumFind(phead, telephone);
				if (cur == NULL)
					printf("�����û������󣬵�ǰû�и��û�����");
				else
					printf("�ҵ��ˣ�\n�����Ƿ�ȷ��ɾ���� 1.ȷ��ɾ��  2.���˲���\n");
				int j = 0;
				scanf("%d", &j);
				if (j == 1)
					UserErase(&phead, cur);// ɾ��curλ��
				MovePrint(phead);//��ӡ�����û���Ϣ
			}
			break;
			case 2:
			{
				printf("������Ҫ��ѯ���û��ǳƣ�");
				scanf("%s", nickname);
				User* cur = UserNameFind(phead, nickname);
				if (cur == NULL)
					printf("�����û������󣬵�ǰû�и��û��ǳƣ�");
				else
					printf("�ҵ��ˣ�\n�����Ƿ�ȷ��ɾ���� 1.ȷ��ɾ��  2.���˲���");
				int j = 0;
				scanf("%d", &j);
				if (j == 1)
					UserErase(&phead, cur);// ɾ��curλ��
				MovePrint(phead);//��ӡ�����û���Ϣ
			}
			break;
			default:
				printf("�������\n");
				break;
			}
		}
		continue;
		case 3://��ѯ�û����ɸ����û��š��Ա������˶������Ƚ��в�ѯ��Ҫ����ʾ���з�����������Ϣ��
		{
			int i = 0;
			printf("����Ը����û��š��Ա������˶������Ƚ��в�ѯ����ѡ����Ҫ��ѯ�ķ�ʽ��1.�û���  2.�Ա�  3.�����˶�����\n");
			scanf("%d", &i);
			switch (i)
			{
			case 1://1.�û���  
			{
				printf("������Ҫ��ѯ���û��ţ�");
				scanf("%s", telephone);
				User* cur = UserNumFind(phead, telephone);
				if (cur == NULL)
				{
					printf("�����û������󣬵�ǰû�и��û�����\n");
					break;
				}
				else
					printf("�ҵ��ˣ�\n");
				UserPerPrint(cur);//��ӡ���ҵ����û���Ϣ
			}
			break;
			case 2://2.�Ա�
			{
				printf("������Ҫ��ѯ���Ա�");
				scanf("%d", &sex);
				User* cur = UserSexFind(phead, sex);
				while (cur != NULL)
				{
					printf("�ҵ��ˣ�\n");
					UserPerPrint(cur);//��ӡ���ҵ����û���Ϣ
					cur = UserSexFind(cur->next, sex);
				}
			}
			break;
			case 3://3.�����˶�����
			{
				printf("������Ҫ��ѯ�������˶�������");
				scanf("%d", &ConDay);
				User* cur = UserConDayFind(phead, ConDay);
				/*	if (cur == NULL)
						printf("���������˶��������󣬵�ǰû�и������˶�������");
					else*/
				while (cur != NULL)
				{
					printf("�ҵ��ˣ�\n");
					UserPerPrint(cur);//��ӡ���ҵ����û���Ϣ
					cur = UserConDayFind(cur->next, ConDay);
				}
			}
			break;
		defalut:
			printf("�������");
			break;
			}
		}
		continue;
		case 4://�޸��û�:�����޸ĵ��û���Ϣ�����û��š��ǳơ��Ա�����ȡ��޸��û��ź�һ��Ҫ��֤�µ��û�����Ψһ�ġ�			
		{
			int j = 0;
			printf("������Ҫ�޸ĵ��û���Ϣ���û��ţ�");
			scanf("%s", telephone);
			User* cur = UserNumFind(phead, telephone);
			if (cur == NULL)
				printf("�����û��Ŵ��󣬵�ǰû�и��û��ţ�\n");
			else
			{
				printf("�ҵ��ˣ�\n");
				printf("��������Ҫ�޸ĵ��û���Ϣ�� 1.�û���  2.�ǳ�  3.�Ա�  4.����:\n");
				int i = 0;
				scanf("%d", &i);
				switch (i)
				{
				case 1://1.�û���  			
				{
					char temp[12] = { 0 };
					while (1)
					{
						printf("������Ҫ�޸ĵ��û��ţ�����ȷ�����û�����Ψһ�ģ�");
						printf("�޸ĺ���ֻ���:��Ҫ����11λ����λ��0,�������룩");
						scanf("%s", temp);

						bool ret = UserName(phead, temp);
						if (ret == false)
						{
							printf("�ֻ��ŷ����ظ���������Ψһ���ֻ��ţ�����\n");
						}
						else
						{
							int len = strlen(temp), i, s = 0;
							if (temp[0] != '1' || len != 11)
								printf("NO!!!\n");
							else
							{
								for (i = 0; i < 11; i++)
								{
									if (temp[i] >= '0' && temp[i] <= '9')
										s++;//S��¼ѭ������
									else
										break;
								}
								if (s == 11)
								{
									printf("yes\n");
									break;
								}
								else printf("no\n");
							}
						}
					}
					strcpy(cur->telephone, temp);
				}
				break;
				case 2://�ǳ�
				{
					char nickname[20] = { 0 };
					while (1)
					{
						printf("�޸ĺ���ǳ�:(�ǳ�Ҫ��λ����4��12λ֮��)");
						scanf("%s", nickname);
						int len = strlen(nickname), i, s = 0;
						if (len >= 4 && len <= 12)
						{
							break;
						}
						else
						{
							printf("NO!\n");
						}
					}
					strcpy(cur->nickname, nickname);
				}
				break;
				case 3:
				{
					int sex = 0;
					while (1)
					{
						printf("������Ҫ�޸ĵ��û��Ա�(0ΪŮ��1Ϊ��)");
						scanf("%d", &sex);
						if (sex == 0 || sex == 1)
							break;
					}
					cur->sex = sex;
				}
				break;
				case 4:
				{
					int age = 0;
					while (1)
					{
						printf("�������޸ĺ���û����䣨������С��0���ߴ���150����");
						scanf("%d", &age);
						if ((age > 0) && (age < 150))
						{
							break;
						}
						else
							printf("������󣡣���\n");
					}
					cur->age = age;
				}
				break;
				default:
					printf("�������");
					break;
				}
			}

		}
		continue;
		case 5://����û��˶���Ϣ
		{
			printf("��������Ҫ��ӵ��û����û��ţ�");
			scanf("%s", telephone);
			User* cur = UserNumFind(phead, telephone);
			if (cur == NULL)
				printf("�����û������󣬵�ǰû�и��û�����");
			else
				printf("�ҵ��ˣ�\n");
			int today = IsDay(cur->move);//6,5,4,3,2,1,0
			printf("�����������˶�������");
			scanf("%d", &StepNum);
			OrderDay(cur->move, today, StepNum);//����˳���Ƿ�������,��������
		}
		continue;
		case 6://6���޸��û��˶���Ϣ
		{
			printf("��������Ҫ��ӵ��û����û��ţ�");
			scanf("%s", telephone);
			User* cur = UserNumFind(phead, telephone);
			if (cur == NULL)
				printf("�����û������󣬵�ǰû�и��û�����");
			else
				printf("�ҵ��ˣ�\n");
			int today = IsDay(cur->move);//6,5,4,3,2,1,0
			printf("������Ҫ�޸�Ϊ���˶�������");
			scanf("%d", &StepNum);
			cur->move[today - 1] = StepNum;
		}
		continue;
		case 7://��ʾ�����û��˶���Ϣ
		{
			MovePrint(phead);
		}
		continue;
		case 8://�������а�:�������а���������ʾ�����û������˶���Ϣ�����а񣬰�������˶�������Ϊ���ݡ�
		{
			User* cur = phead;
			while (cur != NULL)
			{
				int today = IsDay(cur->move) - 1;//�жϵ�ǰ�ǵڼ���
				RankPushFront(&plist, cur->telephone, cur->nickname, cur->move[today]);//ͷ��
				cur = cur->next;
			}
			bubble_sort(plist);
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("�û���       �û��ǳ�     �����˶��������Ӵ�С���У�\n");
			RankPrint(plist);
		}
		continue;
		case 9://�����˶����а���������ʾ�����û��������˶��������У����û������˶�����Ϊ���ݡ�
		{
			RankDestory(&plist);
			User* cur = phead;
			while (cur != NULL)
			{
				int ConDay = Con_Day(cur->move);//��������
				RankPushFront(&plist, cur->telephone, cur->nickname, ConDay);//ͷ��
				cur = cur->next;
			}
			bubble_sort(plist);
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("�û���       �û��ǳ�     �����˶��������Ӵ�С���У�\n");
			RankPrint(plist);
		}
		continue;
		case 10://һ�����а���������ʾָ���û���������˶����а񣬰��˶�����Ϊ����
		{
			RankDestory(&plist);

			printf("������Ҫ��ѯ���û��ţ�");
			scanf("%s", telephone);
			User* cur = UserNumFind(phead, telephone);
			if (cur == NULL)
				printf("�����û������󣬵�ǰû�и��û�����");
			else
				printf("�ҵ��ˣ�\n");
			int move[7] = { 0 };
			for (int i = 0; i < 7; i++)
			{
				move[i] = cur->move[i];
			}
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 6 - i; j++)
				{
					if (cur->move[j] < cur->move[j + 1])
					{
						int temp = cur->move[j];
						cur->move[j] = cur->move[j + 1];
						cur->move[j + 1] = temp;
					}
				}
			}
			UserWeekPrint(cur, move);//��ӡ���ҵ����û���Ϣ
		}
		continue;
		case 11://������������ÿ���ص�����·��
		{
			char ch[20] = { 0 };
			int i = 0;
			int u;
			printf("�������˶���㣺");
			scanf("%s", &ch);
			for (i = 0; i < pGraph->Nv; i++)
			{
				if (strcmp(ch, pGraph->Data[i]) == 0)
				{
					u = i;
					break;
				}
			}
			printf("�������·���У����Ժ�...\n");
			Dijkstra(pGraph, u);
			for (int i = 0; i < pGraph->Nv; i++)//���Դ�㵽ÿ��������·���Լ�·����·
				printf_path(pGraph,u, i);
			printf("�������·����ϣ�\n");
		}
		continue;
		case 12://���ݵ���
		{
			ReadUserFile(&phead);//�����û���
			MovePrint(phead);
			ReadBuildGraph(&pGraph, &pE);//�����˶�ͼ
			printf_MG(*pGraph);//���ͼ
			/*printf("%d %d\n", pGraph->Ne, pGraph->Nv);
			printf("%d %d", pE->V1,pE->V2);*/
		}
		continue;
		case 13://���ݵ���
		{
			WriteUserFile(&phead);
		}
		continue;
		}
	}
	return 0;
}
