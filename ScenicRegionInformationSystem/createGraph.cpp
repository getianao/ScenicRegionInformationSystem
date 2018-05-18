#include<iostream>
#include<fstream>
#include<string>
#include"createGraph.h"
#define VEX_PATH "Vex.txt"//������Ϣ�ļ�·��
#define EDGE_PATH "Edge.txt"//��·��Ϣ�ļ�·��
using namespace std;

 
 int** edge;
 int vexNum;//��������
 VexInfo* vexinfo;//���澰������


int createGraph()
{
	 
	ifstream finVex(VEX_PATH, ios::in);
	if (!finVex)
	{
		cout << "������Ϣ�ļ���ʧ�ܣ�" << endl;
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
		cout << "��·��Ϣ�ļ���ʧ�ܣ�" << endl;
		return 1;
	}
	edge = new int*[vexNum];//������ά����洢��·��Ϣ
	for (int i = 0; i < vexNum; i++)
		edge[i] = new int[vexNum];

	for (int i = 0; i < vexNum; i++)//��ʼ����·��Ϣ��-1��ʾ������
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
	return 0;//ͼ�������
}
int outputGraphInfo()
{
	if (createGraph() == 1)
	{
		cout << "�ļ���ȡ����" << endl;
		return 1;
	}
	cout << "===������������ͼ===" << endl;
	cout << "������Ŀ��" << vexNum << endl;
	cout << "---����---" << endl;
	for (int i = 0; i < vexNum; i++)
		cout << i << " - " << vexinfo[i].vexName << endl;
	cout << "---��---" << endl;
	for (int i = 0; i < vexNum; i++)//ֻ�����ά��������Ͻ�
		for (int j = i + 1; j < vexNum; j++)
			if (edge[i][j] != -1)
				cout << "(v" << i << ",v" << j << ") " << edge[i][j] << endl;
	cout << endl;
	return 0;
 }
