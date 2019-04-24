
#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
using namespace std;
//�ô����ӡ���̳�����еĺ���
class Base
{
public:
	virtual void func1(){ cout << "Base::func1<<endl"; }
	virtual void func2(){ cout << "Base::func2<<endl"; }
private:
	int a;
};
class Drive :public Base
{
public:
	virtual void func1(){ cout << "Drive::func1<<endl"; }
	virtual void func3(){ cout << "Drive::func3<<endl"; }
	virtual void func4(){ cout << "Drive::func4<<endl"; }
private:
	int b;
};

//int main()
//{
//	Base b;
//	Drive d;
//	return 0;
//}

typedef void(*VFPTR) ();
void PrintVTable(VFPTR vTable[])
{
	//����ȡ����е��麯��ָ���ӡ�����á����þͿ��Կ���������ĸ�����
	cout << " ����ַ>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" ��%d���麯����ַ :0X%x,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
		cout << endl;
	}
	cout << endl;
}
int main()
{
	Base b;
	Drive d;
	// ˼·��ȡ��b��d�����ͷ4bytes����������ָ�룬ǰ������˵���麯��������һ�����麯��ָ���
	//ָ�����飬���������������һ��nullptr
	// 1.��ȡb�ĵ�ַ��ǿת��һ��int*��ָ��
	// 2.�ٽ�����ȡֵ����ȡ����b����ͷ4bytes��ֵ�����ֵ����ָ������ָ��
	// 3.��ǿת��VFPTR*����Ϊ������һ����VFPTR����(�麯��ָ������)�����顣
	// 4.���ָ�봫�ݸ�PrintVTable���д�ӡ���
	// 5.��Ҫ˵�����������ӡ���Ĵ��뾭�����������Ϊ��������ʱ�����Ĵ����ɾ�����������û��
	//��nullptr������Խ�磬���Ǳ����������⡣����ֻ��Ҫ��Ŀ¼���� - ���� - �������������ٱ���ͺ��ˡ�

	VFPTR* vTableb = (VFPTR*)(*(int*)&b);
	PrintVTable(vTableb);
	VFPTR* vTabled = (VFPTR*)(*(int*)&d);
	PrintVTable(vTabled);
	return 0;
}




//class Base1
//{
//public:
//	virtual void func1(){ cout << "Base1::func1" << endl; }
//	virtual void func2(){ cout << "Base1::func2" << endl; }
//private:
//	int b1;
//};
//class Base2
//{
//public:
//	virtual void func1(){ cout << "Base2::func1" << endl; }
//	virtual void func2(){ cout << "Base2::func2" << endl; }
//private:
//	int b2;
//};
//////��������͸���ĸ�����ͬ�������Լ�������麯�����ڵ�һ��ֱ�Ӹ���������
//class Drive :public Base1, public Base2
//{
//	virtual void func1(){ cout << "Drive::func1" << endl; }
//	virtual void func3(){ cout << "Drive::func3" << endl; }
//private:
//	int d1;
//};
//int main()
//{
//	Base1 b1;
//	Base2 b2;
//	Drive d;
//	return 0;
//}
////����һ������ָ�룬 ��ʾһ�෵��ֵΪvoid,��������Ϊ0�ĺ���
//typedef void(*VFPTR) ();
//void PrintVTable(VFPTR vTable[])
//{
//	cout << " ����ַ>" << vTable << endl;
//	for (int i = 0; vTable[i] != nullptr; ++i)
//	{
//		printf(" ��%d���麯����ַ :0X%x,->", i, vTable[i]);
//		VFPTR f = vTable[i];
//		f();
//	}
//	cout << endl;
//}
//int main()
//{
//	Base1 b1;
//	Base2 b2;
//	Drive d;
//	Base2* pb2 = &d;
//	VFPTR* vTableb1 = (VFPTR*)(*(int*)&b1);
//	PrintVTable(vTableb1);
//	VFPTR* vTableb2 = (VFPTR*)(*(int*)&b2);
//	PrintVTable(vTableb2);
//	VFPTR* vTableb3 = (VFPTR*)(*(int*)&d);
//	PrintVTable(vTableb3);
//	VFPTR* vTableb4 = (VFPTR*)(*(int*)pb2);
//	//VFPTR* vTableb4 = (VFPTR*)(*(int*)((char*)&d + sizeof(Base1)));
//	PrintVTable(vTableb4);
//	return 0;
//}
