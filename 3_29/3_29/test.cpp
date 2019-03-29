#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <assert.h>
using namespace std;

//class String
//{
//public:
//	//字符串指针输出会作解引用，对于空指针解引用奔溃
//	//其它类型指针输出为地址
//	//对于无参构造，应申请一个字节的空间，存放'\0'
//	//申请一个字节的空间，也需要用 new [], 析构时用的是delete[],保持全局统一
//	/*String()
//		:_str(new char[1])
//	{
//		_str[0] = '\0';
//	}*/
//	//带参构造，需要申请和输入字符串一样大的空间
//	//把输入字符串拷贝进去
//	//如果只拷贝字符串指针，
//	//释放可能会有问题： 1. 二次释放(两个指针同时指向同一片空间)， 
//	//				  2. 如果传入的为字符串常量，析构就会奔溃（不能主动释放代码段的字符串常量）
//	/*String(char* str)
//		:_str(new char[strlen(str) + 1])
//	{
//		strcpy(_str, str);
//	}*/
//
//	//全缺省构造函数,缺省值为""
//	String(char* str = "")
//		:_str(new char[strlen(str) + 1])
//	{
//		strcpy(_str, str);
//	}
//
//	//拷贝构造（深拷贝）, 1，申请空间， 2. 拷贝内容
//	/*String(const String& s)
//		:_str(new char[strlen(s._str) + 1])
//	{
//		strcpy(_str, s._str);
//	}*/
//
//	//拷贝构造，现代写法
//	String(const String& s)
//		:_str(nullptr)
//	{
//		String tmp(s._str);
//		swap(_str, tmp._str);
//	}
//
//	//返回引用，连续赋值
//	//一定要检查是否自己给自己赋值，如果不检查
//	// 要拷贝的字符串长度不一定和当前对象的字符串长度一致
//	// 如果直接拷贝，空间不足的时候，会导致数据丢失
//	// 所以直接释放原有空间，申请一个和当前要拷贝的字符串一样大的空间
//	// _str至少有一个字节的空间，由构造函数保证的
//	String& operator=(const String& s)
//	{
//		if (this != &s)
//		{	
//			delete[] _str;
//			_str = new char[strlen(s._str) + 1];
//			strcpy(_str, s._str);
//		}
//		return *this;
//	}
//	// 现代写法
//	// 传入参数： 传值， 并不会引发赋值运算符无穷递归，通过调用拷贝构造完成值拷贝
//	// 传值相当于在函数栈帧中生成一个临时对象
//	// 和拷贝构造相比， 生成临时对象的时机不同， 拷贝构造： 函数内部生成， 赋值： 传值时生成
//	// 
//	String& operator=(String s)
//	{
//		swap(_str, s._str);
//		return *this;
//	}
//
//	const char* c_str()
//	{
//		return _str;
//	}
//
//
//	~String()
//	{
//		if (_str)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//private:
//	char* _str;
//};

//int main()
//{
//	String s;
//	cout << s.c_str() << endl;
//	return 0;
//}

const char* StrStr(const char* dest, const char* substr);

class String
{
public:
	typedef char* iterator;
	typedef const char* const_iterator;

	//全缺省构造函数,缺省值为""
	String(const char* str = "")
		:_size(strlen(str))
		, _capacity(_size)
		, _str(new char[_size + 1])
	{
		strcpy(_str, str);  // while(*_str++ = *str++) ;  会拷贝'\0'
	}

	//拷贝构造，现代写法
	// String(this, const String& s)
	String(const String& s)
		:_str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		String tmp(s._str);
		// Swap(this, tmp)
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

	// 首先检查capacity够不够，如果容量已满，则扩容
	// 
	void PushBack(const char c)
	{
		//if (_size == _capacity)
		//{
		//	//已存满， 扩容, 检测初始空间是否为0，如果是0， 增容为15byte
		//	size_t newC = (_capacity == 0 ? 15 : _capacity * 2);
		//	Reserve(newC);
		//}
		////尾插
		//_str[_size++] = c;
		////++_size;
		//_str[_size] = '\0';

		Insert(_size, c);
	}
	// 只增容，不减少容量， 不改变size
	void Reserve(size_t n)
	{
		if (n > _capacity)
		{
			//增容
			char* tmp = new char[n + 1];
			//拷贝原有空间的内容到新的空间
			strcpy(tmp, _str);
			//释放原有空间
			delete[] _str;
			//指向新空间
			_str = tmp;
			//更新容量值
			_capacity = n;
		}
	}
	// 尾删
	void PopBack()
	{
		//确保含有至少一个有效字符
		assert(_size > 0);
		_str[--_size] = '\0';

	}
	//尾插
	void Append(const char* str)
	{
		/*size_t sz = strlen(str);
		if (_size + sz > _capacity)
		{
		Reserve(_size + sz);
		}
		strcpy(_str + _size, str);
		_size += sz;*/

		Insert(_size, str);
	}
	/*
	n < _size: _size = n, 更新'\0'位置
	*/
	void Resize(size_t n, char c = '\0')
	{
		assert(n > 0);
		if (n > _capacity)
		{
			Reserve(n);
		}
		if (n > _size)
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

		//检查空间是否已满
		if (_size == _capacity)
		{
			//增容
			size_t newC = (_capacity == 0 ? 15 : _capacity * 2);
			Reserve(newC);
		}

		size_t end = _size;
		while (end > pos)  // max end : pos + 1
		{
			//从后向前挪动
			_str[end] = _str[end - 1];
			--end;
		}

		// 在pos插入c
		_str[pos] = c;
		_str[++_size] = '\0';

	}

	void Insert(size_t pos, const char* str)
	{
		assert(pos <= _size);
		int len = strlen(str);
		if (_size + len > _capacity)
		{
			Reserve(_size + len);
		}
		//从后先前挪动数据
		size_t end = _size + len;
		while (end > pos + len - 1)
		{
			//第一个挪动的为'\0'
			_str[end] = _str[end - len];
			--end;
		}
		//从pos位置拷贝str
		for (int i = 0; i < len; i++)
		{
			_str[i + pos] = str[i];
		}
		_size += len;

	}

	void Erase(size_t pos, size_t len)
	{
		assert(pos < _size);
		//从pos开始向后的字符全部被删除
		if (pos + len > _size)
		{
			_size = pos;
			_str[_size] = '\0';
		}
		else
		{
			size_t start = pos + len;
			//以pos + len位置开始一个一个向前挪动len个位置
			while (start < _size)
			{
				_str[pos++] = _str[start];
				start++;
			}
			_size -= len;
			_str[_size] = '\0';
		}
	}
	// s1 += s2   -->  改变s1
	// s1.operator+=(&s1, s2)  --> Append(&s1, s2._str)
	String& operator+=(const String& s)
	{
		Append(s._str);
		return *this;   // this --> &s1
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

		// char*  strstr(char* dest, char* substr)
		//char* start = strstr(_str, str);
		const char* start = StrStr(_str, str);

		if (start)
			return start - _str;
		else
			return npos;
	}


	size_t Size() const
	{
		return _size;
	}

	char& operator[](size_t pos)
	{
		//防止访问越界
		assert(pos < _size);
		return _str[pos];
	}

	//只读接口，不允许修改，返回const引用
	const char& operator[](size_t pos) const
	{
		//防止访问越界
		assert(pos < _size);
		return _str[pos];
	}


	iterator begin()
	{
		//返回第一个元素的位置(地址）
		return _str;
	}

	iterator end()
	{
		//返回最后一个元素的下一个位置
		return _str + _size;
	}

	const_iterator begin() const
	{
		//返回第一个元素的位置(地址）
		return _str;
	}

	const_iterator end() const
	{
		//返回最后一个元素的下一个位置
		return _str + _size;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
	friend ostream& operator<<(ostream& _cout, const String& s);
private:
	// _size: 有效字符长度， 不含'\0'
	size_t _size;
	// _capacity: 实际能存放的最大字符数，不含'\0', 它比实际申请的空间小一个字节
	size_t _capacity;
	char* _str;
	static const size_t npos;
};
// s1 + s2   :  s1: "hello"   s2: "world"    s3 :"hello world"
String operator+(const String& s1, const String& s2)
{
	String s3(s1);
	s3 += s2;   // += String   += 'c'   += "str"
	return s3;
}
String operator+(const String& s1, const char* s2)
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

// "abc"   "abd"
const char* StrStr(const char* dest, const char* substr)
{
	while (*dest)
	{
		//首先判断第一个字符是否相等
		if (*substr == *dest)
		{
			const char* msubstr = substr;
			const char* mdest = dest;
			//判断substr每一个字符
			while (*msubstr && *mdest)
			{
				if (*msubstr != *mdest)
					break;
				msubstr++;
				mdest++;
			}
			// 匹配成功，返回substr在dest中的起始位置
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

void PrintStringIIterator(const String& s)
{
	String::const_iterator sit = s.begin();
	while (sit != s.end())
	{
		cout << *sit << " ";
		++sit;
	}
	cout << endl;
}

void PrintStringFor(const String& s)
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
	s.PopBack();*/

	//for (int i = 0; i < s.Size(); i++)
	//{
	//	cout << s[i] << " ";   //s.operator[](&s, i)
	//}
	//cout << endl;
	//PrintString(s);
	//PrintStringIIterator(s);
	//PrintStringFor(s);
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

	/*s.Append("qwertyuiopasdfghjklzxcvbnm");
	s.Resize(10, 'K');*/
	PrintStringFor(s);
}

void testString3()
{
	String s;
	s += 'a';
	s += "hello";
	String s2("world");
	s += s2;
	cout << s << endl;

	cout << s.find('e') << endl;  // 2
	cout << s.find(0, "hello") << endl; // 1

}

int main()
{
	testString1();

	system("pause");
	return 0;
}