#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <thread>
#include <mutex>
#include <memory>
#include <vector>
using namespace std;
template <class T>
class AutoPtr
{
public:
	AutoPtr(T* ptr)
		:_ptr(ptr)
	{}
	//管理权转移，解决二次释放
	AutoPtr(AutoPtr<T>& ap)
		:_ptr(ap._ptr)
	{
		ap._ptr = nullptr;
	}



	~AutoPtr()
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
//// 靠谱
//// 实现RAII + 指针
//// 缺点：不能拷贝
//template <class T>
//class UniquePtr
//{
//public:
//	UniquePtr(T* ptr)
//		:_ptr(ptr)
//	{}
//	~UniquePtr()
//	{
//		if (_ptr)
//		{
//			delete _ptr;
//			_ptr = nullptr;
//			//cout << "delete _ptr" << endl;
//		}
//	}
//
//	//*ptr  ptr->
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//
//private:
//	//只声明，不实现
//	UniquePtr(const UniquePtr<T>& up);
//	UniquePtr<T>& operator=(const UniquePtr<T>& up);
//	//定义为delete函数
//	/*UniquePtr(const UniquePtr<T>& up) = delete;
//	UniquePtr<T>& operator=(const UniquePtr<T>& up) = delete;*/
//	T* _ptr;
//};
struct Date
{
	int _year = 1;
	int _month = 1;
	int _day = 1;

	~Date()
	{
		cout << "~Date()" << endl;
	}
};

int main()
{
	AutoPtr<Date> ap(new Date);
	AutoPtr<Date> ap2 = ap; 
	AutoPtr<Date> ap3 = ap2;
	Date* p = new Date;
	Date* p2 = p;
	Date* p3 = p;
	p->_year = 2019;
	p2->_year = 2019;
	p3->_year = 2020;

	//管理权转移，指针悬空， C++98: auto_ptr 禁止使用
	//ap->_year = 2019;
	//ap2->_year = 2020;
	ap3->_year = 2019;
	(*ap3)._year = 2020;
	return 0;
}

//int main()
//{
//	UniquePtr<Date> up(new Date);
//	//UniquePtr<Date> upcopy(up);
//	up->_year = 0;
//	return 0;
//}