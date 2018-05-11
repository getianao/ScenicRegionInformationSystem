#ifndef CREATEGRAGH_H
#define CREATEGRAGH_H
using namespace std;

class VexInfo//储存节点信息的类
{
public:
	string vexName;
	string descrip;
};

extern int vexNum;//景区数量
extern VexInfo* vexinfo;//储存景区名字
extern int** edge;

int outputGraphInfo();
#endif // !CREATEGRAGH_H

