#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
using namespace std;
//class Car
//{
//public:
//	virtual void Drive() = 0;
//};



//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-舒适" << endl;
//	}
//};



//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-操控" << endl;
//	}
//};

//void Test()
//{
//	Car* pBenz = new Benz;
//	pBenz->Drive();
//
//	Car* pBMW = new BMW;
//	pBMW->Drive();
//}



//final修饰基类的虚函数不能被派生类重写
class Car
{
public:
	virtual void Drive()final{}
};
class Benz :public Car
{
public:
	virtual void Drive()
	{
		cout << "Benz-舒适" << endl;
	}
};
class Car
{
public:
	virtual void Drive(){}
};



//override 修饰派生类虚函数强制完成重写，如果没有重写就会编译报错
class Benz :public Car
{
public:
	virtual void Drive()override
	{
		cout << "Benz-舒适" << endl;
	}
};