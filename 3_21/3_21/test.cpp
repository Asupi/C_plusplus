#include<string>
#include<iostream>
using namespace std;
//�ַ��������һ�����ʵĳ���
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

//�ҳ��ַ������һ��ֻ����һ�ε��ַ�
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
//�ַ�����ת
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
//�ж��Ƿ��ǻ����ַ���
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
//			// ��ǰ������һ�������ַ�������ĸ
//			while (begin != end)
//			{
//				if (IsNumberOrLetter(s[begin]))
//					break;
//				++begin;
//			}
//			// �Ӻ���ǰ��һ�������ַ�������ĸ
//			while (begin < end)
//			{
//				if (IsNumberOrLetter(s[end]))
//					break;
//				--end;
//			}
//			if (begin < end)
//			{
//				// ���start��endλ���ַ��Ƿ���� �����Ƿ����ִ�С�����
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

		// �Գ��ַ�����Ϊ�ⲿѭ��
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