#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string>
using namespace std;

//class Solution {
//public:
//	bool isNumberLetter(char c)
//	{
//		return (c >= '0' && c <= '9')
//			|| (c >= 'a' && c <= 'z')
//			|| (c >= 'A' && c <= 'Z');
//	}
//	bool isPalindrome(string s) {
//		int begin = 0;
//		int end = s.size() - 1;
//		while (begin < end)
//		{
//			//从前向后找到第一个字母或数字
//			while (begin < end)
//			{
//				if (isNumberLetter(s[begin]))
//					break;
//				begin++;
//			}
//
//			//从后向前找到第一个字母或数字
//			while (begin < end)
//			{
//				if (isNumberLetter(s[end]))
//					break;
//				end--;
//			}
//
//			//比较begin和end位置的字符
//			// 大小写字母相差32
//			if (s[begin] % 32 != s[end] % 32)
//				return false;
//
//			begin++;
//			end--;
//
//		}
//		return true;
//
//	}
//};
//
//int main()
//{
//	Solution solu;
//	string s;
//	while (cin >> s)
//	{
//		cout << solu.isPalindrome(s);
//	}
//	return 0;
//}

//class Solution {
//public:
//	string addStrings(string num1, string num2) {
//		//获取个位位置
//		int len1 = num1.size() - 1;
//		int len2 = num2.size() - 1;
//		int step = 0;
//		int sum = 0;
//		string ret = "";
//		//以最长的字符串结束相加
//		while (len1 >= 0 || len2 >= 0)
//		{
//			//当前位的和
//			sum = 0;
//			//获取当前位的和： num1[len1] + num2[len2] + step
//			//先加上一位进位
//			sum += step;
//			if (len1 >= 0)
//			{
//				sum += num1[len1] - '0';
//			}
//			if (len2 >= 0)
//			{
//				sum += num2[len2] - '0';
//			}
//			//获取当前位的值
//			if (sum > 9)
//			{
//				sum -= 10;
//				//更新进位
//				step = 1;
//			}
//			else
//			{
//				step = 0;
//			}
//			//把当前位值用字符形式保存到字符串中，头插
//			ret.insert(0, 1, sum + '0');
//			
//			//计算下一位值
//			len1--;
//			len2--;	
//		}
//
//		if (step == 1)
//		{
//			//更新最高位进位
//			ret.insert(0, 1, '1');
//		}
//
//		return ret;
//
//	}
//};
//
//int main()
//{
//	/*Solution s;
//	string s1, s2;
//	while (cin >> s1 >> s2)
//	{
//	cout << s.addStrings(s1, s2);
//	}
//	return 0;*/
//	string s1("hello");
//	string s2("world");
//	
//	int a = 1;
//	int b = 2;
//	swap(a, b);
//	swap(s1, s2);
//	s1.swap(s2);
//	return 0;
//}

class String
{
public:
	/*String()
	:_str(new char[1])
	{
	_str[0] = '\0';
	}

	String(char* str)
	:_str(new char[strlen(str) + 1])
	{
	strcpy(_str, str);
	}*/


	String(char* str = "")
		:_str(new char[strlen(str) + 1])
	{
		strcpy(_str, str);
	}
	//深拷贝： 拷贝成员变量 + 资源
	//浅拷贝： 拷贝成员变量
	//传统写法
	/*String(const String& s)
	:_str(new char[strlen(s._str) + 1])
	{
	strcpy(_str, s._str);
	}*/
	//现代写法
	String(const String& s)
		:_str(nullptr)
	{
		String tmp(s._str);
		swap(_str, tmp._str);
	}

	//深拷贝,传统写法
	//String& operator=(const String& s)
	//{
	//	if (this != &s)
	//	{
	//		delete[] _str;
	//		_str = new char[strlen(s._str) + 1];  // while(*str != '\0') count++;
	//		strcpy(_str, s._str);
	//	}
	//	
	//	return *this;
	//}
	//现代写法
	String& operator=(String s)
	{
		//String tmp(s);
		swap(_str, s._str);
		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str; //释放堆上空间
			_str = nullptr;
		}
	}

	char* c_str()
	{
		return _str;
	}
private:
	char* _str;
};

int main()
{
	//string s; // "" ---> \0
	//String s2("hello word"); // 字符串常量-->代码段
	//cout << s.c_str() << endl;
	//cout << s2.c_str() << endl;
	//return 0;

	//char s1[] = "";    // 1  \0
	//char s2[] = "\0";  // 2   \0 \0
	//char s3[] = "\\0";  // 3  \ 0 \0
	//cout << sizeof(s1) << endl;
	//cout << sizeof(s2) << endl;
	//cout << sizeof(s3) << endl;

	String s1("hello");
	String s2(s1);
	return 0;
}
