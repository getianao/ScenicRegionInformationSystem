#include<iostream>
#include"createGraph.h"
#include"queryInfo.h"
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
				if (outputGraphInfo() == 1)
				{
					cout << "������������ͼʧ��" << endl<<endl;
					flag = 1;
				}
				break;
			}
			case 2:
			{
				if (queryInfo() == 1)
				{
					cout << "��ѯ������Ϣʧ��" << endl << endl;;
				}
				break;
			}

			case 3:
			{

				break;
			}

			case 4:
			{

				break;
			}
			case 5:
			{

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