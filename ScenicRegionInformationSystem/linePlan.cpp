#include<iostream>
#include<string>
#include"createGraph.h"
using namespace std;

int linePlan()
{
	int num = vexNum;
	int min = INT_MAX;
	int *state = new int[vexNum];
	int lineLength=0;
	int q, p;//记录新增路径端点

	for (int i = 0; i < vexNum; i++)
		state[i] = 0;//0表示还未被选择
	for(int i = 0;i<vexNum;i++)
		for (int j = 0; j<vexNum; j++)
			if (edge[i][j] != -1 && i!=j && edge[i][j] < min)
			{
				min = edge[i][j];
				p = i;
				q = j;
			}
	state[p] = 1;
	state[q] = 1;
	num -= 2;
	lineLength += edge[p][q];
	cout << "在以下两个景点之间铺设电路：" << endl;
	cout << vexinfo[p].vexName << " - " << vexinfo[q].vexName << "  " << edge[p][q] << "m" << endl;

	while (num != 0)
	{
		min = INT_MAX;
		for (int i = 0; i < vexNum; i++)
		{
			if (state[i] == 1)//从已选择顶点中选一点
			{
				for (int j = 0; j < vexNum; j++)
					if (state[j] != 1 && edge[i][j] != -1 && min > edge[i][j])//从没有选择的点中选一点，且长度最短
					{
						min = edge[i][j];
						p = i;
						q = j;
					}
			}
			else
				continue;
		}
		state[p] = 1;
		state[q] = 1;
		lineLength += edge[p][q];
		num--;
		cout << vexinfo[p].vexName << " - " << vexinfo[q].vexName << "  " << edge[p][q] << "m" << endl;
	}
	cout << "铺设电路的总长度为：" << lineLength << "m" << endl << endl;
	return 0;
}