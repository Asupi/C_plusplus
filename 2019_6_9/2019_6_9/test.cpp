#define _CRT_SECURE_NO_WARNINGS 


//#include<iostream>
//using namespace std;
//int getTotalCount(int month)
//{
//	int count;
//	if (month < 3)
//		count = 1;
//	else
//		count = getTotalCount(month - 1) + getTotalCount(month - 2);
//	return count;
//}
//int main()
//{
//	int month;
//	while (cin >> month)
//	{
//		cout << getTotalCount(month) << endl;
//	}
//	return 0;
//}

#include <iostream>
#include <string>
using namespace std;
bool match(const char* pattern, const char *str)
{
	//当前字符结束，返回true
	if (*pattern == '\0' && *str == '\0')
		return true;
	//两个字符串有一个先结束，则返回false
	if (*pattern == '\0' || *str == '\0')
		return false;
	if (*pattern == '?')
	{
		//遇到?号，匹配一个字符，跳过一个位置
		return match(pattern + 1, str + 1);
	}
	else if (*pattern == '*')
	{
		// 遇到*号，匹配0个(str不挪动)，1个（两者都向前挪动一个字符）或多个(str向前挪动一个字符)
		return match(pattern + 1, str) || match(pattern + 1, str + 1) || match(pattern, str + 1);
	}
	else if (*pattern == *str)
	{
		//如果当前字符相等，匹配下一个字符
		return match(pattern + 1, str + 1);
	}
	return false;
}
int main()
{
	string pattern, str;
	while (cin >> pattern >> str)
	{
		bool ret = match(pattern.c_str(), str.c_str());
		if (ret)
			cout << "true" << endl;
		else

			cout << "false" << endl;
	}
	return 0;
}