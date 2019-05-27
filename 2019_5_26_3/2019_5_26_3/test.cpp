#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int StrToInt(string str)
	{
		if (str.empty())
			return 0;
		int symbol = 1;
		if (str[0] == '-') //处理负号
		{
			symbol = -1;
			str[0] = '0'; //这里是字符'0',不是0
		}
		else if (str[0] == '+') //处理正号
		{
			symbol = 1;
			str[0] = '0';
		}
		int sum = 0;
		for (int i = 0; i<str.size(); ++i)
		{
			if (str[i] < '0' || str[i] > '9')
			{
				sum = 0;
				break;
			}
			sum = sum * 10 + str[i]-'0' ;
		}
		return symbol * sum;
	}
};
int main()
{
	string str = "-123";
	Solution s;
	int result = s.StrToInt(str);
	cout << result << endl;
	return 0;
}
//int main()
//{
//	char c = getchar();
//	int n = c - '0';
//	cout <<n<< endl;
//	system("pause");
//	return 0;
//}