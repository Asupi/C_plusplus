#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
using namespace std;
class Base
{
public:
	virtual void Func1()
	{
		cout << "Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Func1()" << endl;
	}
	virtual void Func3()
	{
		cout << "Func1()" << endl;
	}
private:
	int _b = 1;

};
int main()
{
	Base b;
	cout << sizeof(Base) << endl;//bռ�˸�����λ
	return 0;
}

//ͨ�����´�����֤����vs������Ǵ���ڴ���ε�
class Base
{
public:
	virtual void Func1()
	{
		cout << "Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Func2()" << endl;
	}
	void Func3()
	{
		cout << "Func3()" << endl;
	}
private:
	int _b = 1;

};
class Drive :public Base
{
public:
	virtual void Func1()
	{
		cout << "Drive::Func1()" << endl;
	}
private:
	int _d = 2;
};

int global = 10;//���ݶ�
int main()
{
	Base b;
	Drive d;
	int tmp = 2;//ջ��
	int*ptr = new int;//����
	cout << "ջ: " << &tmp << endl;
	cout << "��: " << ptr << endl;
	cout << "���ݶ�: " << &global << endl;
	printf("�����:  %p\n", &Base::Func3);
	printf("��� %p\n", *((int*)&d));
	return 0;
}
