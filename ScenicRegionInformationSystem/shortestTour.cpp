#include<iostream>
#include<string>
#include"createGraph.h"
using namespace std;

void dijkstra(int start,int end)
{
	int i, j, k;
	int min;
	int* path = new int[vexNum + 1];//储存到各节点最短路径的前驱  
	int* mark = new int[vexNum + 1];//标记是否已找出到该节点最短路径  
	int* dist = new int[vexNum + 1];//到各个顶点的最小路径长度  
	 
	for (int i = 1; i <= vexNum; i++)//初始化 
	{
		mark[i] = 0;//0表示未选择，1表示已选择 
		if (edge[start - 1][i - 1] == -1)
			dist[i] = INT_MAX;
		else 
			dist[i] = edge[start - 1][i - 1];//直接到x的长度  
		path[i] = start;//到x  
	}
	mark[start] = 1;
	do {
		min = INT_MAX;
		k = 0;
		//找出到各个顶点的最短路径，这个值一定是从该点到所求顶点路径的最小值，因为它已经是已知的最小，不能再小了
		for (int i = 1; i <= vexNum; i++)
		{
			if (mark[i] != 1 && dist[i] < min)
			{	
				min = dist[i];//min为到该顶点的最短路径  
				k = i;
				if (k == end )//找到起点到终点的最短路径
				{
					cout << "最短线路为：";
					do
					{
						cout << vexinfo[k - 1].vexName << "<-";
						k = path[k];
					} while (k != start);
					cout << vexinfo[k - 1].vexName <<endl<< "最短距离为:" << dist[end] << endl<<endl;
					return ;
				}
			}
		}
		if (k)//如果找到  
		{
			mark[k] = 1;//标记已找到  
						//检查是否能通过新选择出的最短路径来使到其他顶点路径长度变短  
			for (int i = 1; i <= vexNum; i++)//更新路径信息
			{
				if (edge[k - 1][i - 1]!=-1 && dist[i] > min + edge[k - 1][i - 1])//该顶点的最短路径到新得出的x+x到其他各点  
				{
					dist[i] = min + edge[k - 1][i - 1];
					path[i] = k;
				}
			}
		}
	} while (k);//所有点都已选出时k=0退出  
}

int shortestTour()
{
	int start,end;
	if (vexNum == 0)
	{
		cout << "查询失败，请先创建景区景点图" << endl;
		return 1;
	}
	else
	{
		for (int i = 0; i < vexNum; i++)
			cout << i << " - " << vexinfo[i].vexName << endl;
		cout << "请输入起点的编号：";
		while (cin >> start)
		{
			if (start >= vexNum)
				cout << "输入的编号不合法，请重新输入！" << endl;
			else
				break;
		}
		cout << "请输入终点的编号：";
		while (cin >> end)
		{
			if (end >= vexNum)
				cout << "输入的编号不合法，请重新输入！" << endl;
			else
				break;
		}
		dijkstra( start+1,  end+1);
	}
	return 0;
}