#include<iostream>
#include<string>
#include"createGraph.h"
using namespace std;

int *visit = new int[vexNum + 1];//建立状态数字，保存访问状态
int solutionNum = 0;
void dfs(int index, int depth)
{
	visit[index] = depth;//标志已访问

	if (depth == vexNum)//访问完成，输出路径信息
	{
		solutionNum++;
		cout << "路线" << solutionNum << ": ";
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
	else//访问未完成,继续寻找相邻顶点
	{
		for (int i = 0; i < vexNum; i++)
		{
			if (edge[index-1][i] > 0 && visit[i+1] == 0)//两点可达并且未访问
			{
				dfs(i+1, ++depth);
				visit[i+1] = 0;//恢复上一状态
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
		cout << "查询失败，请先创建景区景点图" << endl;
		return 1;
	}
	else
	{
		for (int i = 0; i < vexNum; i++)
			cout << i << " - " << vexinfo[i].vexName << endl;
		cout << "请输入起始点编号：";
		while (cin >> index)
		{
			if (index >= vexNum)
				cout << "输入的编号不合法，请重新输入！" << endl;
			else
				break;
		}
		cout << "导游路线为：" << endl;
		dfs(index+1, 1);
		cout << endl;
	}
	return 0;
}
