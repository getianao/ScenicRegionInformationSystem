#include<iostream>
#include<string>
#include"createGraph.h"


int queryInfo()
{
	int index;
	if (vexNum == 0)
	{
		cout << "��ѯʧ�ܣ����ȴ�����������ͼ" << endl;
		return 1;
	}
	else
	{
		for (int i = 0; i < vexNum; i++)
			cout << i << " - " << vexinfo[i].vexName << endl;

		cout<<"��������Ҫ��ѯ�ľ����ţ�";
		while (cin >> index)
		{
			if (index >= vexNum)
				cout << "����ı�Ų��Ϸ������������룡" << endl;
			else
				break;
		}
		cout << vexinfo[index].vexName << endl;
		cout << vexinfo[index].descrip << endl;
		cout << "---��Χ����---" << endl;
		for (int i = 0; i < vexNum; i++)//��ʼ����·��Ϣ��-1��ʾ������
			if (edge[index][i] != -1)
				cout << vexinfo[index].vexName << "-->" << vexinfo[i].vexName << "  " << edge[index][i] << endl;
		cout << endl;
		return 0;
	}
	
}