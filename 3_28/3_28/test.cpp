#define _CRT_SECURE_NO_WARNINGS 

#pragma once
#include<iostream>
#include<assert.h>
#include<string>
#include<algorithm>
using namespace std;
	class String
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
//1.string�����ĳ�������
		//���캯��
		String(const char* str = "")
		{
			if (nullptr == str)
			{
				assert(false);
				return;
			}
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];//��1����'\0'
			strcpy(_str, str);
		}
		//��������
		String(const String& s)
			:_str(new char[s._capacity + 1])
			, _size(s._size)
			, _capacity(s._capacity)
		{
			strcpy(_str, s._str);
		}
		//��ֵ����
		String& operator=(const String& s)
		{
			if (this != &s)
			{
				String tmp(s._str);
				swap(_str, tmp._str);
			}
			return *this;
		}
		//��������
		~String()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
				_size = 0;
				_capacity = 0;
			}
		}
		char* c_str()
		{
			return _str;
		}
		//modify�޸Ĳ���
		void PushBack(char ch)//β��һ���ַ�
		{
			if (_size == _capacity)
			{
				Reserve(_capacity * 2);
			}
			_str[_size++] = ch;
			_str[_size] = '\0';
		}
		void Append(size_t n, char c)//׷��n���ַ�c
		{
			for (size_t i = 0; i < n; ++i)
			{
				PushBack(c);
			}
		}
		void Append(const char* str)//׷���ַ���
		{
			for (size_t i = 0; i < strlen(str); ++i)
			{
				PushBack(str[i]);
			}
		}
		String& operator+=(char ch)//��һ���ַ�
		{
			PushBack(ch);
			return *this;
		}
		String& operator+=(const char* str)//��һ���ַ���
		{
			Append(str);
			return *this;
		}
		String& Insert(size_t pos, char ch)
		{
			assert(pos < _size);
			int end = _size;
			if (_size == _capacity)
			{
				Reserve(_capacity * 2);
			}
			for (end = _size; end >= (int)pos; --end)
			{
				_str[end + 1] = _str[end];
			}
			_str[pos] = ch;
			++_size;
			_str[_size] = '\0';
			return *this;
		}
		String& Insert(size_t pos, const char* str)
		{
			assert(pos < _size);
			size_t len = strlen(str);
			if (len + _size>_capacity)
			{
				Reserve(len + _size);
			}
			for (size_t i = _size + len; i > pos; --i)
			{
				_str[i] = _str[i - len];
			}
			for (size_t j = 0; j < len; ++j)
			{
				_str[pos + j] = str[j];
				++_size;
			}
			_str[_size] = '\0';
			return *this;
		}
		String& Erase(size_t pos, size_t len)
		{
			if (pos + len >= _size - 1)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
			}
			_size -= len;
			_str[_size] = '\0';
			return *this;
		}
		size_t Find(char ch, size_t pos = 0)//�ӵ�pos��λ���������ַ�ch
		{
			assert(pos < _size);
			for (size_t i = pos; i < _size; ++i)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return 0;
		}
		size_t Find(const char* str, size_t pos = 0)
		{
			assert(pos<_size);
			size_t begin = pos;//Դ�ַ���_str���±��posλ�ÿ�ʼ��
			size_t len = strlen(str);
			while (begin < _size)
			{
				size_t i = 0;//����str���±��0��ʼ
				size_t start = begin;
				while (_str[start] == str[i])
				{
					++i;
					++start;
					if (i == len)//��ʱ�ַ���str�Ѿ��ߵ�ĩβ��
					{
						return begin;
					}
				}
				++begin;
			}
			return -1;
		}


//capacity ��������
		void Resize(size_t newsize, char ch)//����Ч�ַ��ĸ����ĳ�newsize��������Ŀռ����ַ�ch���
		{
			if (newsize > _size)
			{
				if (newsize > _capacity)
				{
					Reserve(newsize);
				}
				memset(_str + _size, ch, newsize - _size);//�ڴ����ã�������Ŀռ���Ϊch
			}
			_size = newsize;
			_str[newsize] = '\0';
		}
		void Reserve(size_t newcapacity)//Ϊ�ַ���Ԥ���ռ�
		{
			//����µ��������ھ�����������
			if (newcapacity > _capacity)
			{
				char* str = new char[newcapacity + 1];
				strcpy(str, _str);
				//�ͷžɿռ䣬ʹ���¿��ٵĿռ�
				delete[] _str;
				_str = str;
				_capacity = newcapacity;
			}
		}
		void Clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}
		size_t Size()const
		{
			return _size;
		}
		size_t Capacity()const
		{
			return _capacity;
		}
		bool Empty()const
		{
			return 0 == _size;
		}


//access�±����
		char& operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}
		const char& operator[](size_t index)const
		{
			assert(index < _size);
			return _str[index];
		}
		//�жϴ�С��ϵ
		bool operator<(const String& s)const
		{
			size_t index1 = 0, index2 = 0;
			while (index1 < _size && index2 < s._size)
			{
				if (_str[index1] < s._str[index2])
				{
					return true;
				}
				++index1;
				++index2;
			}
			return false;
		}
		bool operator==(const String& s)const
		{
			//��������ַ����Ĵ�С����
			if (s._size != _size)
			{
				return false;
			}
			//��С��ȣ����α��������ַ����Ƚ�ֵ�Ƿ����
			size_t i = 0;
			while (_str[i] == s._str[i] && i < _size)
			{
				++i;
			}
			if (i == _size && s._str[i] == '\0')
			{
				return true;
			}
			return false;
		}
		bool operator>(const String& s)const
		{
			return !(*this < s || *this == s);
		}
		bool operator<=(const String& s)const
		{
			return *this < s || *this == s;
		}
		bool operator>=(const String& s)const
		{
			return !(*this < s);
		}
		bool operator!=(const String& s)const
		{
			return !(*this == s);
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
};


void TestString1()
{
	String s1("hello");
	String s2("world");
	String copy(s1);
	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;
	cout << copy.c_str() << endl;
	//���õ�������ӡString�� ��Ԫ��
	String::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//��Χfor
	for (auto e : s1)
	{
		cout << e << " ";
	}
	cout << endl;
}
void TestString2()
{
	String s1("hello");
	s1.PushBack(' ');
	s1.PushBack('w');
	s1.PushBack('o');
	s1.PushBack('r');
	s1.PushBack('l');
	s1.PushBack('d');
	s1.PushBack(' ');
	s1.Append("code");
	cout << s1.c_str() << endl;
	s1 += 'A';
	cout << s1.c_str() << endl;
	s1 += "hehe";
	cout << s1.c_str() << endl;
	s1.Insert(2, 'a');
	cout << s1.c_str() << endl;
	s1.Insert(3, "copy");
	cout << s1.c_str() << endl;
	s1.Erase(3, 2);
	cout << s1.c_str() << endl;
	cout << s1.Find('c', 5) << endl;
	cout << s1.Find("py") << endl;

}
void TestString3()
{
	String s1("hello");
	s1.PushBack(' ');
	s1.PushBack('w');
	s1.PushBack('o');
	s1.PushBack('r');
	s1.PushBack('l');
	s1.PushBack('d');
	s1.PushBack(' ');
	s1.Append("code");
	cout << s1.Size() << endl;
	cout << s1.Capacity() << endl;
	s1.Clear();
	cout << s1.Size() << endl;
}
void TestString4()
{
	String s1("absehret");
	String s2("adgfiesk");
	cout << s1[2] << endl;
	cout << (s1 > s2) << endl;
	cout << (s1 < s2) << endl;
	cout << (s1 >= s2) << endl;
	cout << (s1 <= s2) << endl;
	cout << (s1 == s2) << endl;
	cout << (s1 != s2) << endl;
}

int main()
{
	TestString1();
	cout <<" "<< endl;
	TestString2();
	cout << " " << endl;
	TestString3();
	cout << " " << endl;
	TestString4();
	system("pause");
	return 0;
}

