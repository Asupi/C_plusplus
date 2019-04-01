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
		//if (_size == _capacity)
		//{
		//	size_t newC = (_capacity == 0 ?15: _capacity * 2);
		//	Reserve(newC);
		//}
		////尾插
		//_str[_size++] = c;
		//++_size;
		//_str[_size] = '\0';
	
	Insert(_size, c);
}
	void Reserve(size_t n)
	{
		if (n > _capacity)
		{
			char*tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[]_str;
			_str = tmp;
			_capacity = n;
		}
	}
	//尾删
	void PopBack()
	{
		assert(_size > 0);
		_str[--_size] = '\0';
	}
	//尾插 
	void Append(const char* str)
	{
		/*size_t sz = strlen(str);
		if (_size + sz > _capacity);
		{
			Reserve(_size + sz);
		}
		strcap(_str + _size, str);
		_size += sz;*/
		Insert(_size, str);
	}
	/*n < _size:_size = n; 更新'\0'位置*/


	void Resize(size_t n, char c = '\0')
	{
		assert(n > 0);
		if (n < _capacity)
		{
			Reserve(n);
		}
		if (n>_size)
		{
			/*for (int i = _size; i < n; i++)
			{
				_str[i] = c;
			}*/
			memset(_str + _size, c, n - _size);
		}
		_size = n;
		_str[_size] = '\0';
	}
	void Insert(size_t pos, const char c)
	{
		assert(pos <= _size);
		if (_size == _capacity)
		{
			size_t newC = (_capacity == 0 ? 15 : _capacity * 2);
			Reserve(newC);
		}
		size_t end = _size;
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			--end;
		}
		_str[pos] = c;
		_str[++_size] = '\0';
	}
	void Insert(size_t pos, const char*str)
	{
		assert(pos <= _size);
		int len = strlen(str);
		if (_size + len > _capacity)
		{
			Reserve(_size + len);
		}
		size_t end = _size + len;
		while (end > pos + len - 1)
		{
			_str[end] = _str[end - len];
			--end;
		}
		for (int i = 0; i < len; i++)
		{
			_str[i + pos] = str[i];
		}
		_size += len;
	}
	void Erase(size_t pos, size_t len)
	{
		assert(pos < _size);
		if (pos + len>_size)
		{
			_size = pos;
			_str[_size] = '\0';
		}
		else
		{
			size_t start= pos + len;
			while (start < _size)
			{
				_str[pos++] = _str[start];
				start++;
			}
			_size -= len;
			_str[_size] = '\0';
		}
	}
	String& operator+=(const String& s)
	{
		Append(s._str);
		return *this;
	}
	String& operator+=(const char c)
	{
		PushBack(c);
		return *this;
	}
	String& operator+=(const char* str)
	{
		Append(str);
		return *this;
	}
	size_t find(const char c)
	{
		for (int i = 0; i < _size; i++)
		{
			if (_str[i] == c)
				return i;
		}
		return npos;
	}
	size_t find(size_t pos, const char* str)
	{
		const char* start = StrStr(_str, str);
		if (start)
		{
			return start - _str;
		}
		else
			return npos;
	}
	size_t Size()const
	{
		return _size;
	}
	char& operator[](size_t pos)
	{
		assert(pos < _size);
		return _str[pos];
	}
	//只读借口，不允许修改返回const引用
	const char& operator[](size_t pos)const
	{
		assert(pos < _size);
		return _str[pos];
	}
	iterator begin()
	{
		return _str;
	}
	iterator end()
	{
		return _str + _size;
	}
	const_iterator begin() const
	{
		return _str;
	}
	const_iterator end()const
	{
		return _str+_size;
	}
	~String()
	{
		if (_str)
		{
			delete[]_str;
			_str = nullptr;
		}
	}
	friend ostream& operator<<(ostream&_cout, const String& s);
private:
	// _size: 有效字符长度， 不含'\0'
	size_t _size;
	// _capacity: 实际能存放的最大字符数，不含'\0', 它比实际申请的空间小一个字节
	size_t _capacity;
	char* _str;
	static const size_t npos;
};


String operator+(const String& s1, const String& s2)
{
	String s3(s1);
	s3 += s2;
	return s3;
}
String operator+(const String& s1, const char * s2)
{
	String s3(s1);
	s3 += s2;
	return s3;
}
String operator+(const char* s1, const String& s2)
{
	String s3(s1);
	s3 += s2;
	return s3;
}
const size_t String::npos = -1;
const char*StrStr(const char*dest, const char*substr)
{
	while (*dest)
	{
		if (*substr == *dest)
		{
			const char*msubstr = substr;
			const char* mdest = dest;
			while (*msubstr&&*mdest)
			{
				if (*msubstr != *mdest)
				{
					break;
				}
				msubstr++;
				mdest++;
			}
			if (*msubstr == '\0')
				return dest;
		}
		dest++;
     }
	return nullptr;
}
ostream& operator<<(ostream& _cout, const String& s)
{
	for (auto& e : s)
	{
		_cout << e;
	}
	return _cout;
}
void PrintString(const String& s)
{
	for (int i = 0; i < s.Size(); i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
}
void PrintStringIIterator(const String&s)
{
	String::const_iterator sit = s.begin();
	while (sit != s.end())
	{
		cout << sit << " ";

	}
	cout << endl;
}
void PrintStringFor(const String&s)
{
	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}
void testString1()
{
	String s;
	s.PushBack('a');
	s.PushBack('b');
	s.PushBack('c');
	s.PushBack('a');
	s.PushBack('b');
	s.PushBack('c');
	s.PushBack('a');
	s.PushBack('b');
	s.PushBack('c');
	/*s.PopBack();
	s.PopBack();
	s.PopBack();
	s.PopBack();
	s.PopBack();
	s.PopBack();*/

	for (int i = 0; i < s.Size(); i++)
	{
		cout << s[i] << " ";   //s.operator[](&s, i)
	}
	cout << endl;
	//PrintString(s);
	//PrintStringIIterator(s);
	PrintStringFor(s);
	cout << s;
}

void testString2()
{
	String s;
	s.PushBack('a');
	s.PushBack('b');
	s.PushBack('c');
	//头插
	s.Insert(0, "123");
	//中间插入
	s.Insert(4, "456");
	//尾插
	s.Insert(9, "789");  // 123a456bc789

	//s.Erase(2, 4); // 126bc789
	//s.Erase(4, 2); //126b89
	//s.Erase(3, 80); // 126

	//s.Append("qwertyuiopasdfghjklzxcvbnm");
	//s.Resize(10, 'K');
	PrintStringFor(s);
}
void testString3()
{
	String s;
	
	s += 'a';
	s += "hello";
	String s2("world");
	s += s2;
	//cout << s.find('e') << endl;  // 2
	//cout << s.find(0, "hello") << endl; // 1
	String s3 = s + s2;
	cout << s << endl;
	cout << s3 << endl;
}
int main()
{
	//testString3();
	//char* s1 = "ccaaa";
	//char* s2 = "aaa";
	cout << (void*)StrStr("ccaaa", "caa") << endl;
	system("pause");
	return 0;
}
