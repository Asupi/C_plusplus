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
//		cout << "Benz-����" << endl;
//	}
//};



//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-�ٿ�" << endl;
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



//final���λ�����麯�����ܱ���������д
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
		cout << "Benz-����" << endl;
	}
};
class Car
{
public:
	virtual void Drive(){}
};



//override �����������麯��ǿ�������д�����û����д�ͻ���뱨��
class Benz :public Car
{
public:
	virtual void Drive()override
	{
		cout << "Benz-����" << endl;
	}
};