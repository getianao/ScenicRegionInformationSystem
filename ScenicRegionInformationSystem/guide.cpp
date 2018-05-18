#include<iostream>
#include<string>
#include"createGraph.h"
using namespace std;

int *visit = new int[vexNum + 1];//����״̬���֣��������״̬
int solutionNum = 0;
void dfs(int index, int depth)
{
	visit[index] = depth;//��־�ѷ���

	if (depth == vexNum)//������ɣ����·����Ϣ
	{
		solutionNum++;
		cout << "·��" << solutionNum << ": ";
		for (int i = 1; i < vexNum; i++)
		{
			for (int j = 1; j <= vexNum; j++)
				if (i == visit[j])
				{
					cout << vexinfo[j-1].vexName << "->";
					break;
				}
		}
		for (int j = 1; j <= vexNum; j++)
			if (vexNum == visit[j])
				cout << vexinfo[j - 1].vexName << endl ;
	}
	else//����δ���,����Ѱ�����ڶ���
	{
		for (int i = 0; i < vexNum; i++)
		{
			if (edge[index-1][i] > 0 && visit[i+1] == 0)//����ɴﲢ��δ����
			{
				dfs(i+1, ++depth);
				visit[i+1] = 0;//�ָ���һ״̬
				depth--;
			}
		}
	}
}

int guide()
{
	int index;
	solutionNum = 0;
	for (int i = 0; i <= vexNum; i++)
		visit[i] = 0;
	if (vexNum == 0)
	{
		cout << "��ѯʧ�ܣ����ȴ�����������ͼ" << endl;
		return 1;
	}
	else
	{
		for (int i = 0; i < vexNum; i++)
			cout << i << " - " << vexinfo[i].vexName << endl;
		cout << "��������ʼ���ţ�";
		while (cin >> index)
		{
			if (index >= vexNum)
				cout << "����ı�Ų��Ϸ������������룡" << endl;
			else
				break;
		}
		cout << "����·��Ϊ��" << endl;
		dfs(index+1, 1);
		cout << endl;
	}
	return 0;
}
