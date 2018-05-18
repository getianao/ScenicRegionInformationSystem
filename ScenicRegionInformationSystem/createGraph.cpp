#include<iostream>
#include<fstream>
#include<string>
#include"createGraph.h"
#define VEX_PATH "Vex.txt"//景点信息文件路径
#define EDGE_PATH "Edge.txt"//道路信息文件路径
using namespace std;

 
 int** edge;
 int vexNum;//景区数量
 VexInfo* vexinfo;//储存景区名字


int createGraph()
{
	 
	ifstream finVex(VEX_PATH, ios::in);
	if (!finVex)
	{
		cout << "景点信息文件打开失败！" << endl;
		return 1;
	}
	string vexNumString;
	getline(finVex, vexNumString);
	vexNum= atoi(vexNumString.c_str());
	vexinfo = new VexInfo[vexNum];
	string finIndex;
	for (int i = 0; i < vexNum; i++)
	{
		getline(finVex, finIndex);
		getline(finVex, vexinfo[atoi(finIndex.c_str())].vexName);
		getline(finVex, vexinfo[atoi(finIndex.c_str())].descrip);
	}
		
	finVex.close();

	ifstream finEdge(EDGE_PATH, ios::in);
	if (!finEdge)
	{
		cout << "道路信息文件打开失败！" << endl;
		return 1;
	}
	edge = new int*[vexNum];//创建二维数组存储道路信息
	for (int i = 0; i < vexNum; i++)
		edge[i] = new int[vexNum];

	for (int i = 0; i < vexNum; i++)//初始化道路信息，-1表示不相连
		for (int j = 0; j < vexNum; j++)
		{
			if(i==j)
				edge[i][j] = 0;
			else
				edge[i][j] = -1;
		}

	int areaA,areaB,ABdistance;
	while(finEdge>> areaA)
	{
		finEdge >> areaB;
		finEdge >> ABdistance;
		edge[areaA][areaB] = ABdistance;
		edge[areaB][areaA] = ABdistance;
	}
	finEdge.close();
	return 0;//图生成完成
}
int outputGraphInfo()
{
	if (createGraph() == 1)
	{
		cout << "文件读取出错！" << endl;
		return 1;
	}
	cout << "===创建景区景点图===" << endl;
	cout << "顶点数目：" << vexNum << endl;
	cout << "---顶点---" << endl;
	for (int i = 0; i < vexNum; i++)
		cout << i << " - " << vexinfo[i].vexName << endl;
	cout << "---边---" << endl;
	for (int i = 0; i < vexNum; i++)//只输出二维数组的右上角
		for (int j = i + 1; j < vexNum; j++)
			if (edge[i][j] != -1)
				cout << "(v" << i << ",v" << j << ") " << edge[i][j] << endl;
	cout << endl;
	return 0;
 }
