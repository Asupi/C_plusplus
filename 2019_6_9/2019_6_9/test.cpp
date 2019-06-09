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
	//��ǰ�ַ�����������true
	if (*pattern == '\0' && *str == '\0')
		return true;
	//�����ַ�����һ���Ƚ������򷵻�false
	if (*pattern == '\0' || *str == '\0')
		return false;
	if (*pattern == '?')
	{
		//����?�ţ�ƥ��һ���ַ�������һ��λ��
		return match(pattern + 1, str + 1);
	}
	else if (*pattern == '*')
	{
		// ����*�ţ�ƥ��0��(str��Ų��)��1�������߶���ǰŲ��һ���ַ�������(str��ǰŲ��һ���ַ�)
		return match(pattern + 1, str) || match(pattern + 1, str + 1) || match(pattern, str + 1);
	}
	else if (*pattern == *str)
	{
		//�����ǰ�ַ���ȣ�ƥ����һ���ַ�
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