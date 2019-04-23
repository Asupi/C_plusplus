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
	cout << sizeof(Base) << endl;//b占八个比特位
	return 0;
}

//通过以下代码验证发现vs下虚表是存放在代码段的
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

int global = 10;//数据段
int main()
{
	Base b;
	Drive d;
	int tmp = 2;//栈上
	int*ptr = new int;//堆上
	cout << "栈: " << &tmp << endl;
	cout << "堆: " << ptr << endl;
	cout << "数据段: " << &global << endl;
	printf("代码段:  %p\n", &Base::Func3);
	printf("虚表： %p\n", *((int*)&d));
	return 0;
}
