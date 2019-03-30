#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
using namespace std;
//class String
//{
//public:
//	//String()
//	//	:_str(new char[1])
//	//{
//	//	_str[0] = '\0';
//	//}
//	//String(char*str)
//	//	:_str(new char[strlen(str)+1])
//	//{
//	//	strcpy(_str, str);
//	//}
//	////全缺省构造函数，缺省值为""
//	//String(char* str = "")
//	//	:_str(new char[strlen(str) + 1])
//	//{
//	//	strcpy(_str, str);
//	//}
//	////拷贝构造（深拷贝），1.申请空间 2.拷贝内容
//	//String(const String& s)
//	//	:_str(new char[strlen(s._str) + 1])
//	//{
//	//	strcpy(_str, s._str);
//	//}
//	////拷贝构造，现代写法
//	//String(const String&s)
//	//	:_str(nullptr)
//	//{
//	//	String tmp(s.str);
//	//	swap(_str, tmp._str);
//	//}
//	//String& operator=(const String&s)
//	//{
//	//	if (this != &s)
//	//	{
//	//		delete[]_str;
//	//		_str = new char[strlen(s._str) + 1];
//	//		strcpy(_str, s._str);
//	//	}
//	//	return *this;
//	//}
//	String& operator=(String s)
//	{
//		swap(_str, s._str);
//		return *this;
//	}
//	const char*c_str()
//	{
//		return _str;
//	}
//	~String()
//	{
//		if (_str)
//		{
//			delete[]_str;
//
//			_str = nullptr;
//		}
//	}
//
//private:
//	char* _str;
//
//};
//int main()
//{
//	String s;
//	cout << s.c_str() << endl;
//	return 0;
//}
const char*StrStr(const char*dest, const char*substr);
class String
{
public:
	typedef char*iterator;
	typedef const char*const_iterator;
	//全缺省构造函数，缺省值为""
	String(const char*str = "")
		:_size(strlen(str))
		, _capacity(_size)
		, _str(new char[_size + 1])
	{
		strcpy(_str, str);
	}
	//拷贝构造，现代写法
	//String(this,const String&s)
	String(const String& s)
		:_str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		String tmp(s._str);
		Swap(tmp);
	}
	// 现代写法
	// String& operator=(this, String s)
	String& operator=(String s)
	{
		// Swap(this, s)
		Swap(s);
		return *this;
	}

	const char* c_str()
	{
		return _str;
	}

	void Swap(String& tmp)
	{
		swap(_str, tmp._str);
		swap(_size, tmp._size);
		swap(_capacity, tmp._capacity);
	}
	//首先检查capacity够不够，如果容量已满，则扩容
	void PushBack(const char c)
	{
		if (_size == _capacity)
		{
			size_t newC = (_capacity == 0 ? _capacity * 2);
			Reserve(newC);
		}
		//尾插
		_str[_size++] = c;
		++_size;
		_str[_size] = '\0';
	}
	Insert(_size, c);



private:
	// _size: 有效字符长度， 不含'\0'
	size_t _size;
	// _capacity: 实际能存放的最大字符数，不含'\0', 它比实际申请的空间小一个字节
	size_t _capacity;
	char* _str;
	static const size_t npos;
};