#include<iostream>
#include"createGraph.h"
#include"queryInfo.h"
#include"guide.h"
#include"shortestTour.h"
#include"linePlan.h"

using namespace std;
int main()
{
	int index, flag = 0;
	while (flag==0)
	{
		cout << "=====景区信息管理系统=====" << endl;
		cout << "1.创建景区景点图" << endl;
		cout << "2.查询景点信息" << endl;
		cout << "3.旅游景点导航" << endl;
		cout << "4.搜索最短路径" << endl;
		cout << "5.铺设电路规划" << endl;
		cout << "0.退出" << endl;
		cout << "输入操作编号（0~5）：";
		cin >> index;
		switch (index)
		{
			case 1:
			{
				cout << "~~创建景区景点图~~" << endl;
				if (outputGraphInfo() == 1)
				{
					cout << "创建景区景点图失败" << endl<<endl;
					flag = 1;
				}
				break;
			}
			case 2:
			{
				cout << "~~查询景点信息~~" << endl;
				if (queryInfo() == 1)
				{
					cout << "查询景点信息失败" << endl << endl;;
				}
				break;
			}

			case 3:
			{
				cout << "~~旅游景点导航~~" << endl;
				if (guide() == 1)
					cout << "生成旅游景点导航失败" << endl;
				break;
			}

			case 4:
			{
				cout << "~~搜索最短路径~~" << endl;
				if (shortestTour() == 1)
					cout << "搜索最短路径失败" << endl;
				break;
			}
			case 5:
			{
				cout << "~~铺设电路规划~~" << endl;
				if (linePlan() == 1)
					cout << "生成铺设电路规划失败" << endl;
				break;
			}
			case 0:
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)//退出程序
			break;
	}
		


}