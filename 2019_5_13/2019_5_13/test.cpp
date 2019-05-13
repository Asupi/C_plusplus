#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <thread>
#include <mutex>
#include <memory>
using namespace std;


//智能指针：
// 实现RAII思想
// 像指针一样操作

template <class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}

	~SmartPtr()
	{
		if (_ptr)
		{
			delete _ptr;
			_ptr = nullptr;
			//cout << "delete _ptr" << endl;
		}
	}

	//*ptr  ptr->
	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

private:
	T* _ptr;
};

struct Date
{
	int _year = 1900;
	int _month = 1;
	int _day = 1;

	~Date()
	{
		cout << "~Date()" << endl;
	}
};

int main()
{
	/*int* pa = new int(1);*/
	SmartPtr<int> sp(new int(1));
	//*pa = 8;
	*sp = 10;

	//Date* pd = new Date;
	SmartPtr<Date> spd(new Date);
	//pd->_year = 2019;
	spd->_year = 2018;
	spd.operator->()->_year = 2020;
	//拷贝构造：默认--> 浅拷贝--> 二次释放
	SmartPtr<Date> spd2 = spd;
	spd2->_year = 2021;

	Date* pd3 = new Date;
	Date* pd4 = pd3;
	return 0;
}