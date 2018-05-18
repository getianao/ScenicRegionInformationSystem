#include<iostream>
#include<string>
#include"createGraph.h"
using namespace std;

void dijkstra(int start,int end)
{
	int i, j, k;
	int min;
	int* path = new int[vexNum + 1];//���浽���ڵ����·����ǰ��  
	int* mark = new int[vexNum + 1];//����Ƿ����ҳ����ýڵ����·��  
	int* dist = new int[vexNum + 1];//�������������С·������  
	 
	for (int i = 1; i <= vexNum; i++)//��ʼ�� 
	{
		mark[i] = 0;//0��ʾδѡ��1��ʾ��ѡ�� 
		if (edge[start - 1][i - 1] == -1)
			dist[i] = INT_MAX;
		else 
			dist[i] = edge[start - 1][i - 1];//ֱ�ӵ�x�ĳ���  
		path[i] = start;//��x  
	}
	mark[start] = 1;
	do {
		min = INT_MAX;
		k = 0;
		//�ҳ���������������·�������ֵһ���ǴӸõ㵽���󶥵�·������Сֵ����Ϊ���Ѿ�����֪����С��������С��
		for (int i = 1; i <= vexNum; i++)
		{
			if (mark[i] != 1 && dist[i] < min)
			{	
				min = dist[i];//minΪ���ö�������·��  
				k = i;
				if (k == end )//�ҵ���㵽�յ�����·��
				{
					cout << "�����·Ϊ��";
					do
					{
						cout << vexinfo[k - 1].vexName << "<-";
						k = path[k];
					} while (k != start);
					cout << vexinfo[k - 1].vexName <<endl<< "��̾���Ϊ:" << dist[end] << endl<<endl;
					return ;
				}
			}
		}
		if (k)//����ҵ�  
		{
			mark[k] = 1;//������ҵ�  
						//����Ƿ���ͨ����ѡ��������·����ʹ����������·�����ȱ��  
			for (int i = 1; i <= vexNum; i++)//����·����Ϣ
			{
				if (edge[k - 1][i - 1]!=-1 && dist[i] > min + edge[k - 1][i - 1])//�ö�������·�����µó���x+x����������  
				{
					dist[i] = min + edge[k - 1][i - 1];
					path[i] = k;
				}
			}
		}
	} while (k);//���е㶼��ѡ��ʱk=0�˳�  
}

int shortestTour()
{
	int start,end;
	if (vexNum == 0)
	{
		cout << "��ѯʧ�ܣ����ȴ�����������ͼ" << endl;
		return 1;
	}
	else
	{
		for (int i = 0; i < vexNum; i++)
			cout << i << " - " << vexinfo[i].vexName << endl;
		cout << "���������ı�ţ�";
		while (cin >> start)
		{
			if (start >= vexNum)
				cout << "����ı�Ų��Ϸ������������룡" << endl;
			else
				break;
		}
		cout << "�������յ�ı�ţ�";
		while (cin >> end)
		{
			if (end >= vexNum)
				cout << "����ı�Ų��Ϸ������������룡" << endl;
			else
				break;
		}
		dijkstra( start+1,  end+1);
	}
	return 0;
}