#ifndef CREATEGRAGH_H
#define CREATEGRAGH_H
using namespace std;

class VexInfo//����ڵ���Ϣ����
{
public:
	string vexName;
	string descrip;
};

extern int vexNum;//��������
extern VexInfo* vexinfo;//���澰������
extern int** edge;

int outputGraphInfo();
#endif // !CREATEGRAGH_H

