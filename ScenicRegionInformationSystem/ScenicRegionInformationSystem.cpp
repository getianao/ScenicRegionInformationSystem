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
		cout << "=====������Ϣ����ϵͳ=====" << endl;
		cout << "1.������������ͼ" << endl;
		cout << "2.��ѯ������Ϣ" << endl;
		cout << "3.���ξ��㵼��" << endl;
		cout << "4.�������·��" << endl;
		cout << "5.�����·�滮" << endl;
		cout << "0.�˳�" << endl;
		cout << "���������ţ�0~5����";
		cin >> index;
		switch (index)
		{
			case 1:
			{
				cout << "~~������������ͼ~~" << endl;
				if (outputGraphInfo() == 1)
				{
					cout << "������������ͼʧ��" << endl<<endl;
					flag = 1;
				}
				break;
			}
			case 2:
			{
				cout << "~~��ѯ������Ϣ~~" << endl;
				if (queryInfo() == 1)
				{
					cout << "��ѯ������Ϣʧ��" << endl << endl;;
				}
				break;
			}

			case 3:
			{
				cout << "~~���ξ��㵼��~~" << endl;
				if (guide() == 1)
					cout << "�������ξ��㵼��ʧ��" << endl;
				break;
			}

			case 4:
			{
				cout << "~~�������·��~~" << endl;
				if (shortestTour() == 1)
					cout << "�������·��ʧ��" << endl;
				break;
			}
			case 5:
			{
				cout << "~~�����·�滮~~" << endl;
				if (linePlan() == 1)
					cout << "���������·�滮ʧ��" << endl;
				break;
			}
			case 0:
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)//�˳�����
			break;
	}
		


}