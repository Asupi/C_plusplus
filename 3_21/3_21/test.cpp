#include<string>
#include<iostream>
using namespace std;
//字符串里最后一个单词的长度
//int main()
//{
//	string s();
//	while (cin >> s)
//	{
//		size_t pos = s.rfind(' ');
//		if (pos == string::npos)
//		{
//			cout << s.size() << endl;
//		}
//		else
//		{
//			cout << s.size() - pos - 1 << endl;
//		}
//	}
//	system("pause");
//	return 0;
//}

//找出字符串里第一个只出现一次的字符
//#include <string>
//#include <iostream>
//using namespace std;
//
//char firstUniqChar(string s) {
//	int hashtable[256] = { 0 };
//	for (auto& e : s)
//	{
//		hashtable[e]++;
//	}
//
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (hashtable[s[i]] == 1)
//			return s[i];
//	}
//
//	return -1;
//}
//int main()
//{
//	string s("bitekeji");
//	cout << firstUniqChar(s) << endl;
//	system("pause");
//	return 0;
//}
//字符串反转
//#include <iostream>
//#include <string>
//using namespace std;
//class Solution
//{
//public:
//	string reverseString(string s)
//	{
//		if (s.empty())
//			return s;
//
//		size_t start = 0;
//		size_t end = s.size() - 1;
//		while (start < end)
//		{
//			swap(s[start], s[end]);
//			start++;
//			end--;
//		}
//		return s;
//	}
//};
//int main()
//{
//	string s("bitekeji");
//	Solution s1;
//	cout << s1.reverseString(s) << endl;
//	system("pause");
//	return 0;
//}
//判断是否是回文字符串
//#include <iostream>
//#include <string>
//using namespace std;
//class Solution
//{
//public:
//
//	bool isPalindrome(string s) {
//		if (s.empty())
//			return true;
//		int begin = 0;
//		int end = s.size() - 1;
//		char* p = (char*)s.c_str();
//		while (begin < end)
//		{
//			// 从前往后找一个数字字符或者字母
//			while (begin != end)
//			{
//				if (IsNumberOrLetter(s[begin]))
//					break;
//				++begin;
//			}
//			// 从后往前找一个数字字符或者字母
//			while (begin < end)
//			{
//				if (IsNumberOrLetter(s[end]))
//					break;
//				--end;
//			}
//			if (begin < end)
//			{
//				// 检测start和end位置字符是否相等 或者是否不区分大小的相等
//				if ((s[begin] + 32 - 'a') % 32 != (s[end] + 32 - 'a') % 32)
//					return false;
//				++begin;
//				--end;
//			}
//		}
//		return true;
//	}
//	bool IsNumberOrLetter(char c)
//	{
//		if (c >= '0' && c <= '9' ||
//			c >= 'a' && c <= 'z' ||
//			c >= 'A' && c <= 'Z')
//		{
//			return true;
//		}
//		return false;
//	}
//};
//int main()
//{
//	string s("doon"); 
//	Solution s1;
//	cout << s1.isPalindrome(s) << endl;
//	system("pause");
//	return 0;
//}
#include <algorithm>
class Solution {
public:
	string addStrings(string num1, string num2) 
	{
        int LSize = num1.size();
		int RSize = num2.size();

		// 以长字符串作为外部循环
		if (LSize < RSize)
		{
			num1.swap(num2);
			swap(LSize, RSize);
		}

		string strRet;
		strRet.reserve(LSize + 1);

		char cRet = 0;
		char cstep = 0;

		for (size_t i = 0; i < LSize; ++i)
		{
			cRet = num1[LSize - i - 1] - '0' + cstep;
			cstep = 0;

			if (i < RSize)
			{
				cRet += num2[RSize - i - 1] - '0';
			}

			if (cRet >= 10)
			{
				cRet -= 10;
				cstep = 1;
			}

			strRet += cRet + '0';
		}

		if (cstep)
			strRet += '1';

		reverse(strRet.begin(), strRet.end());

		return strRet;
	}
};
int main()
{
	string num1("hello");
	string num2("bite");
	Solution s1;
	cout << s1.addStrings(num1, num2) << endl;
	system("pause");
	return 0;
}