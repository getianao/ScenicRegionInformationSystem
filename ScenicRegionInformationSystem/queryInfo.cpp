#include<iostream>
#include<string>
#include"createGraph.h"


int queryInfo()
{
	int index;
	if (vexNum == 0)
	{
		cout << "查询失败，请先创建景区景点图" << endl;
		return 1;
	}
	else
	{
		for (int i = 0; i < vexNum; i++)
			cout << i << " - " << vexinfo[i].vexName << endl;

		cout<<"请输入想要查询的景点编号：";
		while (cin >> index)
		{
			if (index >= vexNum)
				cout << "输入的编号不合法，请重新输入！" << endl;
			else
				break;
		}
		cout << vexinfo[index].vexName << endl;
		cout << vexinfo[index].descrip << endl;
		cout << "---周围景点---" << endl;
		for (int i = 0; i < vexNum; i++)//初始化道路信息，-1表示不相连
			if (edge[index][i] != -1)
				cout << vexinfo[index].vexName << "-->" << vexinfo[i].vexName << "  " << edge[index][i] << endl;
		cout << endl;
		return 0;
	}
	
}