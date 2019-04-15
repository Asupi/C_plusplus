#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
using namespace std;

//函数模板
//template<class T>

//void Swap(T& x1, T& x2)
//{
//	T tmp = x1;
//	x1 = x2;
//	x2 = tmp;
//}
//int main()
//{
//	int a = 0, b = 1;
//	double aa = 1.11, bb = 2.22;
//	Swap(a, b);
//	Swap(aa, bb);
//}

//T Add(const T& x1, const T& x2)
//{
//	return x1 + x2;
//}
//int main()
//{
//	int a = 0, b = 1;
//	double aa = 1.11, bb = 2.22;
//	Add(a, b);
//	Add(aa, bb);
//
//
//	//Add(a, aa);//类型不同，无法进行隐式实例化
//	Add<int>(a, aa);
//}
//int Add(int x1,int x2)
//{
//	return x1 + x2;
//}
//template<class T>
//T Add(const T& x1, const T& x2)
//{
//	return x1 + x2;
//}
//int main()
//{
//	int a = 0, b = 1;
//	double aa = 1.11, bb = 2.22;
//   // 编译器优先调用非模板函数，若想调用模板函数，必须将其显示给出
//	Add(a, b);
//	Add(aa, bb);
//	Add<int>(a, b);
//}


//类模板

template<class T>
class Vector
{
public:
	Vector()
		:_a(nullptr)
		, _capacity(0)
		, _size(0)
	{}
	~Vector()
	{
		if (_a)
		{
			delete[] _a;
			_size = _capacity = 0;
		}
	}
	void PushBack(const T& x)
	{
		if (_size == _capacity)
		{
			size_t newcapacity =_capacity== 0 ? 3 : 2 * _capacity;
			T*tmp = new T[newcapacity];
			if (_a)
			{
				memcpy(tmp, _a,sizeof(T)*_size);
				delete[]_a;
			}
			
			_a = tmp;
		}
		_a[_size] = x;
		_size++;
	}
	T& operator[](size_t pos)
	{
		return _a[pos];
	}
	size_t Size()
	{
		return _size;
	}
private:
	T* _a;
	size_t _size;
	size_t _capacity;
};
int main()
{
	Vector <int>v1;//int
	v1.PushBack(1);
	v1.PushBack(2);
	v1.PushBack(3);
	v1.PushBack(4);
	//v1[2] = 10;
	
	for (size_t i = 0; i < v1.Size(); ++i)
	{
		cout << v1[i] << " ";
		//cout << v1.operator[](i) << " ";
		cout << endl;
	}
	Vector <double>v2;//double
	v2.PushBack(1.11);
	v2.PushBack(2.22);
	v2.PushBack(3.33);
	v2.PushBack(4.44);
	for (size_t i = 0; i < v2.Size(); ++i)
	{
		cout << v2[i] << " ";
		//cout << v2.operator[](i) << " ";
		cout << endl;
	}
	return 0;
}