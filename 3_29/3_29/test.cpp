#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <assert.h>
using namespace std;

//class String
//{
//public:
//	//�ַ���ָ��������������ã����ڿ�ָ������ñ���
//	//��������ָ�����Ϊ��ַ
//	//�����޲ι��죬Ӧ����һ���ֽڵĿռ䣬���'\0'
//	//����һ���ֽڵĿռ䣬Ҳ��Ҫ�� new [], ����ʱ�õ���delete[],����ȫ��ͳһ
//	/*String()
//		:_str(new char[1])
//	{
//		_str[0] = '\0';
//	}*/
//	//���ι��죬��Ҫ����������ַ���һ����Ŀռ�
//	//�������ַ���������ȥ
//	//���ֻ�����ַ���ָ�룬
//	//�ͷſ��ܻ������⣺ 1. �����ͷ�(����ָ��ͬʱָ��ͬһƬ�ռ�)�� 
//	//				  2. ��������Ϊ�ַ��������������ͻᱼ�������������ͷŴ���ε��ַ���������
//	/*String(char* str)
//		:_str(new char[strlen(str) + 1])
//	{
//		strcpy(_str, str);
//	}*/
//
//	//ȫȱʡ���캯��,ȱʡֵΪ""
//	String(char* str = "")
//		:_str(new char[strlen(str) + 1])
//	{
//		strcpy(_str, str);
//	}
//
//	//�������죨�����, 1������ռ䣬 2. ��������
//	/*String(const String& s)
//		:_str(new char[strlen(s._str) + 1])
//	{
//		strcpy(_str, s._str);
//	}*/
//
//	//�������죬�ִ�д��
//	String(const String& s)
//		:_str(nullptr)
//	{
//		String tmp(s._str);
//		swap(_str, tmp._str);
//	}
//
//	//�������ã�������ֵ
//	//һ��Ҫ����Ƿ��Լ����Լ���ֵ����������
//	// Ҫ�������ַ������Ȳ�һ���͵�ǰ������ַ�������һ��
//	// ���ֱ�ӿ������ռ䲻���ʱ�򣬻ᵼ�����ݶ�ʧ
//	// ����ֱ���ͷ�ԭ�пռ䣬����һ���͵�ǰҪ�������ַ���һ����Ŀռ�
//	// _str������һ���ֽڵĿռ䣬�ɹ��캯����֤��
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
//	// �ִ�д��
//	// ��������� ��ֵ�� ������������ֵ���������ݹ飬ͨ�����ÿ����������ֵ����
//	// ��ֵ�൱���ں���ջ֡������һ����ʱ����
//	// �Ϳ���������ȣ� ������ʱ�����ʱ����ͬ�� �������죺 �����ڲ����ɣ� ��ֵ�� ��ֵʱ����
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

	//ȫȱʡ���캯��,ȱʡֵΪ""
	String(const char* str = "")
		:_size(strlen(str))
		, _capacity(_size)
		, _str(new char[_size + 1])
	{
		strcpy(_str, str);  // while(*_str++ = *str++) ;  �´��'\0'
	}

	//�������죬�ִ�д��
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

	// �ִ�д��
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

	// ���ȼ��capacity���������������������������
	// 
	void PushBack(const char c)
	{
		//if (_size == _capacity)
		//{
		//	//�Ѵ����� ����, ����ʼ�ռ��Ƿ�Ϊ0�������0�� ����Ϊ15byte
		//	size_t newC = (_capacity == 0 ? 15 : _capacity * 2);
		//	Reserve(newC);
		//}
		////β��
		//_str[_size++] = c;
		////++_size;
		//_str[_size] = '\0';

		Insert(_size, c);
	}
	// ֻ���ݣ������������� ���ı�size
	void Reserve(size_t n)
	{
		if (n > _capacity)
		{
			//����
			char* tmp = new char[n + 1];
			//����ԭ�пռ�����ݵ��µĿռ�
			strcpy(tmp, _str);
			//�ͷ�ԭ�пռ�
			delete[] _str;
			//ָ���¿ռ�
			_str = tmp;
			//��������ֵ
			_capacity = n;
		}
	}
	// βɾ
	void PopBack()
	{
		//ȷ����������һ����Ч�ַ�
		assert(_size > 0);
		_str[--_size] = '\0';

	}
	//β��
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
	n < _size: _size = n, ����'\0'λ��
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

		//���ռ��Ƿ�����
		if (_size == _capacity)
		{
			//����
			size_t newC = (_capacity == 0 ? 15 : _capacity * 2);
			Reserve(newC);
		}

		size_t end = _size;
		while (end > pos)  // max end : pos + 1
		{
			//�Ӻ���ǰŲ��
			_str[end] = _str[end - 1];
			--end;
		}

		// ��pos����c
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
		//�Ӻ���ǰŲ������
		size_t end = _size + len;
		while (end > pos + len - 1)
		{
			//��һ��Ų����Ϊ'\0'
			_str[end] = _str[end - len];
			--end;
		}
		//��posλ�ÿ���str
		for (int i = 0; i < len; i++)
		{
			_str[i + pos] = str[i];
		}
		_size += len;

	}

	void Erase(size_t pos, size_t len)
	{
		assert(pos < _size);
		//��pos��ʼ�����ַ�ȫ����ɾ��
		if (pos + len > _size)
		{
			_size = pos;
			_str[_size] = '\0';
		}
		else
		{
			size_t start = pos + len;
			//��pos + lenλ�ÿ�ʼһ��һ����ǰŲ��len��λ��
			while (start < _size)
			{
				_str[pos++] = _str[start];
				start++;
			}
			_size -= len;
			_str[_size] = '\0';
		}
	}
	// s1 += s2   -->  �ı�s1
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
		//��ֹ����Խ��
		assert(pos < _size);
		return _str[pos];
	}

	//ֻ���ӿڣ��������޸ģ�����const����
	const char& operator[](size_t pos) const
	{
		//��ֹ����Խ��
		assert(pos < _size);
		return _str[pos];
	}


	iterator begin()
	{
		//���ص�һ��Ԫ�ص�λ��(��ַ��
		return _str;
	}

	iterator end()
	{
		//�������һ��Ԫ�ص���һ��λ��
		return _str + _size;
	}

	const_iterator begin() const
	{
		//���ص�һ��Ԫ�ص�λ��(��ַ��
		return _str;
	}

	const_iterator end() const
	{
		//�������һ��Ԫ�ص���һ��λ��
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
	// _size: ��Ч�ַ����ȣ� ����'\0'
	size_t _size;
	// _capacity: ʵ���ܴ�ŵ�����ַ���������'\0', ����ʵ������Ŀռ�Сһ���ֽ�
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
		//�����жϵ�һ���ַ��Ƿ����
		if (*substr == *dest)
		{
			const char* msubstr = substr;
			const char* mdest = dest;
			//�ж�substrÿһ���ַ�
			while (*msubstr && *mdest)
			{
				if (*msubstr != *mdest)
					break;
				msubstr++;
				mdest++;
			}
			// ƥ��ɹ�������substr��dest�е���ʼλ��
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
	//ͷ��
	s.Insert(0, "123");
	//�м����
	s.Insert(4, "456");
	//β��
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