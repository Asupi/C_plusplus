#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <thread>
#include <mutex>
#include <memory>
#include <vector>
using namespace std;

template <class T>
class SharedPtr
{
public:
	//构造函数在第一次申请资源后调用
	// sharedPtr<T> sp(new T)
	SharedPtr(T* ptr)
		:_ptr(ptr)
		, _useCount(new int(1))
		, _mtx(new mutex)
	{}

	SharedPtr(const SharedPtr<T>& sp)
		:_ptr(sp._ptr)
		, _useCount(sp._useCount)
		, _mtx(sp._mtx)
	{
		//当前指向资源的引用计数加1
		addRef();
	}

	SharedPtr<T>& operator=(const SharedPtr<T>& sp)
	{
		// 对于两个智能指针管理同一片空间的情况，不需要进行赋值
		//if (this != &sp)
		if (_ptr != sp._ptr)
		{
			if (subRef() == 0)
			{
				delete _ptr;
				delete _useCount;
				delete _mtx;
			}

			_ptr = sp._ptr;
			_useCount = sp._useCount;
			_mtx = sp._mtx;
			addRef();
		}
		return *this;

	}

	~SharedPtr()
	{
		if (subRef() == 0)
		{
			delete _ptr;
			delete _mtx;
			delete _useCount;
			_ptr = nullptr;
			_mtx = nullptr;
			_useCount = nullptr;
			//cout << "delete _ptr" << endl;
		}
	}

	int addRef()
	{
		_mtx->lock();
		++(*_useCount);
		_mtx->unlock();
		return *_useCount;
	}

	int subRef()
	{
		_mtx->lock();
		--(*_useCount);
		_mtx->unlock();
		return *_useCount;
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
	int useCount()
	{
		return *_useCount;
	}

private:
	T* _ptr;
	//int _useCount;
	//static int _useCount;
	int* _useCount;
	mutex* _mtx;
};

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
	/*shared_ptr<Date> sp(new Date);
	shared_ptr<Date> spcopy(sp);
	shared_ptr<Date> sp2(new Date);
	sp2 = sp;

	cout << sp.use_count() << endl;
	return 0;*/

	//非法使用：不满足RAII思想
	//Date* pd = new Date;
	//shared_ptr<Date> sp(pd);
	//shared_ptr<Date> spcopy(pd);


	shared_ptr<Date> sp(new Date);
	shared_ptr<Date> spcopy(sp);
	spcopy = sp;
	shared_ptr<Date> sp2(new Date);
	shared_ptr<Date> sp2copy(sp2);
	cout << sp.use_count() << endl;
	cout << sp2.use_count() << endl;
	return 0;
}
